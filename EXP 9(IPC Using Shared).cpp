#include <stdio.h>

int main() {
    int shared_memory = 10;

    printf("Process 1 wrote: %d\n", shared_memory);

    shared_memory = 20;
    printf("Process 2 updated: %d\n", shared_memory);

    return 0;
}

