#include <stdio.h>

int main() {
    int block[] = {100, 500, 200, 300, 600};
    int process[] = {212, 417, 112, 426};
    int alloc[4];
    int i, j, method;

    printf("Choose Allocation Method:\n");
    printf("1. First Fit\n2. Best Fit\n3. Worst Fit\n");
    scanf("%d", &method);

    for (i = 0; i < 4; i++)
        alloc[i] = -1;

    for (i = 0; i < 4; i++) {
        int best = -1;

        for (j = 0; j < 5; j++) {
            if (block[j] >= process[i]) {

                if (method == 1) {     // FIRST FIT
                    best = j;
                    break;
                }

                if (method == 2) {     // BEST FIT
                    if (best == -1 || block[j] < block[best])
                        best = j;
                }

                if (method == 3) {     // WORST FIT
                    if (best == -1 || block[j] > block[best])
                        best = j;
                }
            }
        }

        if (best != -1) {
            alloc[i] = best;
            block[best] -= process[i];
        }
    }

    printf("\n=== OUTPUT ===\n");
    if (method == 1) printf("Using FIRST FIT:\n");
    if (method == 2) printf("Using BEST FIT:\n");
    if (method == 3) printf("Using WORST FIT:\n");

    for (i = 0; i < 4; i++) {
        if (alloc[i] != -1)
            printf("Process %d allocated to Block %d\n", i, alloc[i]);
        else
            printf("Process %d NOT allocated\n", i);
    }

    return 0;
}


