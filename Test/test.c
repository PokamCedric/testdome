#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * sayHell0(){
    printf("Hello World");
}

int main(){
    pthread_t tid;
    pthread_create(&tid, NULL, &sayHell0, NULL);
    pthread_join(tid, NULL);

    return 0;
}