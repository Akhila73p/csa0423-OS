#include <stdio.h>

int main() {
    int n, blocks[20];
    printf("Enter number of blocks: ");
    scanf("%d", &n);

    printf("Enter block numbers: ");
    for(int i=0;i<n;i++) scanf("%d", &blocks[i]);

    printf("Linked Allocation:\n");
    for(int i=0;i<n;i++)
        printf("%d -> ", blocks[i]);
    printf("-1");

    return 0;
}

