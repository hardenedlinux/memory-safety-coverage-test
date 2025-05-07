#include <stdlib.h>

int main()
{
    char* p = malloc(16);
    *(int*)p = 666;
    int *p2 = *(int**)p;
    *p2 = 42;
    return 0;
}
