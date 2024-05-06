#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int count_letters(const char** strings, int string_count, char target)
{
    int count = 0;
    for (int i = 0; i < string_count; i++){
        for (int j = 0; strings[i][j]; j++)
        {
            if (strings[i][j] == target)
            {
                count++;
            }
        }
    }
    return count;
}

#ifndef RunTests
int main()
{
    const char* string_arr[] = { "Hello", "Jacqueline!" };
    int res = count_letters(string_arr, 2, 'e');
    printf("%d\n", res);
}
#endif