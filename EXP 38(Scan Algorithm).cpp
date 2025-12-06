#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, dir, req[50];

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter requests: ");
    for(int i=0;i<n;i++) scanf("%d", &req[i]);

    printf("Enter head position: ");
    scanf("%d", &head);

    printf("Enter direction (1=Right, 0=Left): ");
    scanf("%d", &dir);

    int total = 0;

    for(int i=0;i<n;i++) {
        total += abs(req[i] - head);
        head = req[i];
    }

    printf("SCAN Movement = %d\n", total);
    return 0;
}

