// marshalling.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>

#include <cassert>  // for assert
#include <cstring>  // for memset


#define MASK_FROM_00_TO_01    0x0003U
#define MASK_FROM_00_TO_03    0x000FU
#define MASK_FROM_00_TO_05    0x003FU
#define MASK_FROM_00_TO_07    0x00FFU
#define MASK_FROM_02_TO_09    0x03FCU
#define MASK_FROM_08_TO_13    0x3F00U
#define MASK_FROM_10_TO_13    0x3C00U
#define MASK_FROM_08_TO_15    0xFF00U

struct Packet {
    uint32_t    senderID : 16U;   // instructs the C compiler that the variable is going to use only 16 bits to store the value.
    uint32_t    packetType : 8U;
    int32_t     altitude : 16U;
    int32_t     longitude : 14U;
    uint32_t    latitude : 14U;
    uint8_t     flags : 4U;
    uint8_t     ext : 8U;
};

// A wrapper for a data buffer providing bit-level access.
class BitBuffer {

    uint8_t* m_data;
    size_t m_size;

public:
    BitBuffer(unsigned char* src_buffer, size_t byte_size)
        : m_data(src_buffer), m_size(byte_size)
    {
        if (m_size) assert(m_data);
    }

    // Clear the buffer (set all bits to 0).
    void clear() {
        memset(m_data, 0, m_size);
    }

    inline uint16_t read(const uint8_t lsb, const  uint8_t msb) {
        assert(lsb < msb);
        assert(msb / 8U < m_size);
        const uint8_t lsbOffset = lsb / 8U;
        const uint8_t msbOffset = msb / 8U;
        uint16_t retVal = 0x0U;
        for (size_t offset = lsbOffset; offset < (msbOffset + 1); offset++) {
            const uint8_t byteEndPos = (offset + 1U) * 8U - 1U;
            const uint8_t byteStartPos = (offset) * 8U;

            const uint8_t start = std::max(byteStartPos, lsb);
            const uint8_t end = std::min(byteEndPos, msb);

            auto read = readByte(offset - lsbOffset, start - lsb, start, end);

            retVal |= read;

        }
        return retVal;
    }

    inline void write(const int32_t value, const uint8_t lsb, const uint8_t msb) {
        assert(lsb < msb);
        assert(msb / 8U < m_size);
        const uint8_t lsbOffset = lsb / 8U;
        const uint8_t msbOffset = msb / 8U;

        for (size_t offset = lsbOffset; offset < (msbOffset + 1); offset++) {
            const uint8_t byteEndPos = (offset + 1U) * 8U - 1U;
            const uint8_t byteStartPos = (offset) * 8U;

            const uint8_t start = std::max(byteStartPos, lsb);
            const uint8_t end = std::min(byteEndPos, msb);

            writeByte(offset - lsbOffset, value, start - lsb, start, end);

        }
    }

private:

    // build mask from the given lsb to msb
    inline uint8_t buildMask(const uint8_t lsb, const uint8_t msb) {
        // determine mask space from lsb to msb
        const uint8_t nBits = msb - lsb + 1U;

        return ~(~0 << nBits);
    }

    inline uint8_t readByte(const uint8_t index, const uint8_t value_shift, const uint8_t lsb, const uint8_t msb) {
        const uint8_t offset = lsb / 8U;                // get data offset
        const uint8_t startPos = lsb % 8U;              //  get the start postion to write data on current offset

        const uint16_t mask = buildMask(lsb, msb);
        const uint8_t data_mask = mask << startPos;

        return (m_data[offset] & data_mask) << value_shift;
    }

    //
    // index: current data index
    // 
    inline void writeByte(const uint8_t index, const int32_t value, const uint8_t value_shift, const uint8_t lsb, const uint8_t msb) {
        const uint8_t offset = lsb / 8U;                // get data offset
        const uint8_t startPos = lsb % 8U;              //  get the start postion to write data on current offset

        const uint16_t mask = static_cast<uint16_t>(buildMask(lsb, msb) << value_shift);

        // write value to the mask position without changing any other bits
        // get masked value and shift it to the right position before adding it to data
        const uint16_t masked_value_shifted = (value & mask) << startPos;
        const uint16_t new_value = m_data[offset] ^ masked_value_shifted;

        m_data[offset] = new_value >> value_shift;

    }

};


void marshal(Packet* p, uint8_t data[]) {

    BitBuffer bb{ data , 10U };
    bb.clear();
    bb.write(p->senderID, 0U, 15U);
    bb.write(p->packetType, 16U, 23U);
    bb.write(p->altitude, 24U, 39U);
    bb.write(p->longitude, 40U, 53U);
    bb.write(p->latitude, 54U, 67U);
    bb.write(p->flags, 68U, 71U);
    bb.write(p->ext, 72U, 79U);

    printf("senderID,   0x%04x\n", bb.read(0U, 15U));
    printf("packetType, 0x%02x\n", bb.read(16U, 23U));
    printf("altitude,   0x%04x\n", bb.read(24U, 39U));
    printf("longitude,  0x%04x\n", bb.read(40U, 53U));
    printf("latitude,   0x%04x\n", bb.read(54U, 67U));
    printf("flags,      0x%01x\n", bb.read(68U, 71U));
    printf("ext,        0x%02x\n", bb.read(72U, 79U));
}


void unmarshal(Packet* p, uint8_t data[]) {

    p->senderID = data[0];
    p->senderID |= data[1] << 8U;

    p->packetType = data[2];

    p->altitude = data[3];
    p->altitude |= data[4] << 8U;

    p->longitude = data[5];
    p->longitude |= (data[6] & MASK_FROM_00_TO_05) << 8U;

    p->latitude = (data[6] & MASK_FROM_00_TO_05) << 8U;
    p->latitude |= (data[6] & MASK_FROM_00_TO_05) << 8U;

}

int main()
{
    Packet packet{};
    packet.senderID     = 0x2211;
    packet.packetType   = 0x33;
    packet.altitude     = 0x5544;
    packet.longitude    = 0x1133;  // 
    packet.latitude     = 0x2244;  //  2244: 10 00|10 0100 01|00
    packet.flags        = 0xA;
    packet.ext          = 0xBC;

    uint8_t newData[10];

    marshal(&packet, newData);


    printf("--- Start ---\n");
    for (rsize_t index = 0U; index < 10; index++) {
        printf("%d: 0x%02x\n", index, newData[index]);
    }
    printf("--- Stop ---\n");


    return 0;
}

