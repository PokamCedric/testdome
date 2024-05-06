// https://www.youtube.com/watch?v=ln3el6PR__Q
// https://www.youtube.com/watch?v=Adtrk3PREQI

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h> 

typedef struct Data
{
    int first;
    int second;
    int third;
} Data;

void *sum(void *arg)
{
    Data *arguments = (Data *)arg;
    int *result = (int *)malloc(sizeof(int));
    *result = 0;
    for (int i = arguments->first; i < arguments->second; i += arguments->third)
    {
        *result += i;
    }
    return (void *)result;
}

int *run_in_parallel(int count,  Data *params, void *(*function)(void*))
{
    pthread_t *th = (pthread_t *)malloc(count * sizeof(pthread_t));;
    int *result = (int *)malloc(count * sizeof(int));

    for(int i = 0; i< count; i++){
        if(pthread_create(&th[i], NULL, function, params+i) != 0){
            perror("Failed to create thread");
        }
      
    }
    
    for(int i = 0; i< count; i++){
        int* r;
        if(pthread_join(th[i], (void**)&r) !=0){
            perror("Failed to join thread");
        };

        result[i] = *r;
        free(r); // free on worker function: int *result = malloc(sizeof(int));

    }

    free(th);
    return result;
}

#ifndef RunTests
int main()
{    
    Data params[] = {{0, 1000, 2}, {6, 2000, 3}};
    int *result = run_in_parallel(2, params, sum);
    printf("%d, %d", result[0], result[1]);
    
    free(result); // free on run function: int *result = malloc(count * sizeof(int));
}
#endif