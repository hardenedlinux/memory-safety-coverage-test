#include <string.h>
#include <unistd.h>

int main()
{
    write(1, "hello\n" - 100, strlen("hello\n"));
    return 0;
}
