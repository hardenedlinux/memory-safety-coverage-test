#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* x = malloc(100);
    char* y = malloc(100);
    x[y - x] = '!';
    printf("*y = %c\n", *y);
    return 0;
}
