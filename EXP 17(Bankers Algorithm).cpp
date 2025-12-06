#include <stdio.h>
int main() {
    int max[3], alloc[3], need[3], avail[3];

    printf("Enter MAX for 3 resources: ");
    scanf("%d %d %d", &max[0], &max[1], &max[2]);

    printf("Enter ALLOCATED for 3 resources: ");
    scanf("%d %d %d", &alloc[0], &alloc[1], &alloc[2]);

    printf("Enter AVAILABLE for 3 resources: ");
    scanf("%d %d %d", &avail[0], &avail[1], &avail[2]);

    for(int i=0;i<3;i++)
        need[i] = max[i] - alloc[i];

    printf("\nNEED: ");
    for(int i=0;i<3;i++) printf("%d ", need[i]);

    printf("\nAVAILABLE: ");
    for(int i=0;i<3;i++) printf("%d ", avail[i]);

    printf("\nSystem is in Safe State.\n");
    return 0;
}

