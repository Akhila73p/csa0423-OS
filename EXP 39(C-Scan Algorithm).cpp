#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, req[50], total = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter requests: ");
    for(int i=0;i<n;i++) scanf("%d", &req[i]);

    printf("Enter head position: ");
    scanf("%d", &head);

    for(int i=0;i<n;i++) {
        total += abs(req[i] - head);
        head = req[i];
    }

    printf("C-SCAN Movement = %d\n", total);
    return 0;
}

