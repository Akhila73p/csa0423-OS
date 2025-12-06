#include <stdio.h>

int main() {
    int buffer = 0, ch;

    while (1) {
        printf("\n1. Produce\n2. Consume\n3. Exit\nEnter choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            buffer++;
            printf("Produced. Buffer = %d\n", buffer);
        } 
        else if (ch == 2) {
            if (buffer > 0) {
                buffer--;
                printf("Consumed. Buffer = %d\n", buffer);
            } else {
                printf("Buffer empty!\n");
            }
        } 
        else break;
    }
    return 0;
}

