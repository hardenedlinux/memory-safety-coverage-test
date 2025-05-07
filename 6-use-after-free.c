#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void uaf_example() {
    // Allocate memory for a string
    char *str = (char *)malloc(20 * sizeof(char));
    if (str == NULL) {
        perror("Failed to allocate memory");
        return;
    }

    // Initialize the string
    strcpy(str, "Hello, World!");
    printf("Before free: %s\n", str);

    // Free the allocated memory
    free(str);

    // Use the pointer after it has been freed (use-after-free)
    printf("After free: %s\n", str); // Undefined behavior

    // Optionally, set the pointer to NULL to avoid accidental use
    // str = NULL;
}

int main() {
    uaf_example();
    return 0;
}
