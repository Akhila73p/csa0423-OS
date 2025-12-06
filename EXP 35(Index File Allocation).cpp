#include <stdio.h>

int main() {
    int index, n, blocks[20];
    printf("Enter index block: ");
    scanf("%d", &index);

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    printf("Enter block numbers:\n");
    for(int i=0;i<n;i++) scanf("%d", &blocks[i]);

    printf("Indexed Allocation:\nIndex Block %d -> ", index);
    for(int i=0;i<n;i++) printf("%d ", blocks[i]);

    return 0;
}

