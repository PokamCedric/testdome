/*
Implement function sort_words that sorts an array of words that contain lowercase characters from english alphabet,
in descending order, and is efficient with respect to time used.

For example, the array { "cherry", "orange", "apple" } should, after sorting, become { "orange", "cherry", "apple" }.
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int myCompare(const void* a, const void* b)
{
    // setting up rules for comparison
    int v = strcmp(*(const char**)a, *(const char**)b);
    if(v > 0){
        v = -1;
        
    }else if(v<0){
        v = 1;
    }
    
    return v;
}

void sort_words(char *words[], int count)
{
    // calling qsort function to sort the array
    // with the help of Comparator
    qsort(words, count, sizeof(const char*), myCompare);
}


#ifndef RunTests
int main()
{
    char *words[] = { "cherry", "orange", "apple" };

    sort_words(words, 3);

    for (int i = 0; i < 3; i++)
    {
        printf("%s ", words[i]);
    }
}
#endif