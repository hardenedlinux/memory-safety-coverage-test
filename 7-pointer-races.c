#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

static int* ptr;

static void* thread_main(void* arg)
{
    unsigned count;
    for (count = 10000000; count--;)
        ptr = malloc(4);
    return NULL;
}

int main()
{
    pthread_t t;
    pthread_create(&t, NULL, thread_main, NULL);

    unsigned count;
    for (count = 1000000; count--;)
        ptr = malloc(4);

    asm volatile("" : : : "memory");

    printf("%d\n", *ptr);
    return 0;
}
