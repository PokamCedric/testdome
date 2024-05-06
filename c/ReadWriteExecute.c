/*
Implement the symbolic_to_int function so that it converts a permission's symbolic notation into an integer.

The string consists of 3 blocks of 3 characters each. The returned number will have three digits, one for each block. Each digit is the sum of all permissions present in the block:
Character 	Value
r 	4
w 	2
x 	1
- 	0

For example rwxr-x-w- is decoded as:
Block 	Value
rwx 	4+2+1 = 7
r-x 	4+0+1 = 5
-w- 	0+2+0 = 2

So the returned number would be 752.
*/

#include <stdio.h>
#include <stdlib.h>

int convert_char_to_int(const char c){
    int retVal = 0;
    switch(c){
        case 'r':
        retVal = 4;
        break;
        case 'w':
        retVal = 2;
        break;
        case 'x':
        retVal = 1;
        break;
        case '-':
        retVal = 0;
        break;
        default :
        retVal = 0;
        break;
    }
    
    return retVal;
}

int get_block(const char *block){
    int retVal = 0;
    for(int index = 0; index < 3; index++){
        retVal += convert_char_to_int(block[index]);
    }
    return retVal;
}

int symbolic_to_int(const char *perm_string)
{
    int result = get_block(perm_string) * 100;
    result += get_block(perm_string+3) * 10;
    result += get_block(perm_string+6) * 1;

    return result;
}

#ifndef RunTests
int main()
{
    // Should write 752
    printf("%d", symbolic_to_int("rwxr-x-w-"));
}
#endif