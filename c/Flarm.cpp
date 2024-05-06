#include "bitBuffer.h"


// A wrapper for a data buffer providing bit-level access.

BitBuffer::BitBuffer(uint8_t* src_buffer, const size_t byte_size)
    : m_data(src_buffer), m_size(byte_size)
{
    if (m_size) assert(m_data);
}

// Clear the buffer (set all bits to 0).
void BitBuffer::clear() {
    memset(m_data, 0, m_size);
}

uint16_t BitBuffer::read(const uint8_t bit_offset, const uint8_t size_in_bits) const {
    const uint8_t msb = (bit_offset + size_in_bits) - 1U; // lsb = bit_offset;
    assert(msb / 8U < m_size);

    // lsb = bit_offset;
    const uint8_t dataIndexStart = bit_offset / 8U;
    const uint8_t dataIndexEnd = msb / 8U;
    uint16_t retVal = 0U;

    for (size_t offset = dataIndexStart; offset < (dataIndexEnd + 1); offset++) {
        const uint8_t byteEndPos = (offset + 1U) * 8U - 1U;
        const uint8_t byteStartPos = (offset) * 8U;

        const uint8_t start = std::max(byteStartPos, bit_offset);
        const uint8_t end = std::min(byteEndPos, msb);

        retVal |= readByte(start, end, offset - dataIndexStart, start - bit_offset);

    }
    return retVal;
}

void BitBuffer::write(const int32_t value, const uint8_t bit_offset, const uint8_t size_in_bits) {
    const uint8_t msb = (bit_offset + size_in_bits) - 1U; // lsb = bit_offset;
    assert(msb / 8U < m_size);

    const uint8_t dataIndexStart = bit_offset / 8U;
    const uint8_t dataIndexEnd = msb / 8U;

    for (size_t offset = dataIndexStart; offset < (dataIndexEnd + 1); offset++) {
        const uint8_t byteEndPos = (offset + 1U) * 8U - 1U;
        const uint8_t byteStartPos = (offset) * 8U;

        const uint8_t start = std::max(byteStartPos, bit_offset);
        const uint8_t end = std::min(byteEndPos, msb);

        writeByte(start, end, offset - dataIndexStart, start - bit_offset, value);

    }
}

uint16_t BitBuffer::buildMask(const uint8_t size, const uint8_t shift) const {
    return (~(~0 << size)) << shift;
}

uint16_t BitBuffer::readByte(const uint8_t bit_offset, const uint8_t msb, const uint8_t index, const uint8_t value_shift) const {
    const uint8_t offset = bit_offset / 8U;                // get data offset
    const uint8_t startPos = bit_offset % 8U;              //  get the start postion to write data on current offset

    // build mask field with a size from bit_offset to msb and shift this field to the correct position
    const uint16_t mask = buildMask(msb - bit_offset + 1U, startPos);

    return static_cast<uint16_t>(((m_data[offset] & mask) >> startPos) << value_shift);
}


void BitBuffer::writeByte(const uint8_t bit_offset, const uint8_t msb, const uint8_t index, const uint8_t value_shift, const int32_t value) {
    const uint8_t offset = bit_offset / 8U;                // get data offset
    const uint8_t startPos = bit_offset % 8U;              //  get the start postion to write data on current offset

    // build mask field with a size from bit_offset to msb
    const uint16_t mask = buildMask(msb - bit_offset + 1U, value_shift);

    // write value to the mask position without changing any other bits
    // get masked value and shift it to the right position before adding it to data
    const uint16_t masked_value_shifted = static_cast<uint16_t>((value & mask) << startPos);
    const uint16_t new_value = static_cast<uint16_t>(m_data[offset]) ^ masked_value_shifted;

    m_data[offset] = static_cast<uint8_t>(new_value >> value_shift);

}
