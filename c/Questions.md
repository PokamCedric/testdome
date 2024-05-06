# Questions

## 1- Allocate String

What are the correct implementations of the following function that allocates memory for a string of specified length?

````C
char* allocate_string(int length)
{
    return calloc((length + 1) * sizeof(char));
    return malloc((length + 1) * sizeof(char));
}
````

## 2- Increment

````C++
array[index]++;

(*(array + index))++;
````

## 3- String Pointer

Consider the following variable declaration:

````C
    char **strings;
````

Select all the ways you can get a character at the index 3 from the string at the index 1 in the strings array.

````C
    strings[1][3];
    *(*(strings + 1) + 3);
````

## 4- Square

What is the correct implementation of the following function that sets the value of the given integer to the square of its original value?

````C
void square(int *number)
{
    *number *= *number;
}

````

## 5- Sort Params

What is the correct declaration of the sort function that sorts two integers?

````C
void sort(int* a, int* b)
{
    if (*a > *b)
    {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
}
````

## 6- Racer

Consider the following program.

````C
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

void* run(void* vargp)
{
    sleep(1);
    printf("%d\n", ((int *) vargp)[0]);
    return NULL;
}

int main()
{
    int names[] = {1, 2, 3, 4, 5};
    pthread_t handles[5] = {0};

    void start (int name)
    {
        pthread_create(&handles[name - 1], NULL, run, &names[name - 1]);
    }
    void join (int name)
    {
        pthread_join(handles[name - 1], NULL);
    }

    start(5);
    start(3);
    start(1);
    join(3);
    start(2);
    join(1);
    start(4);
    join(2);
    join(4);
    join(5);
}
````

Select the first 3 racers that will be written to the console, in any order.

1, 3, 5
