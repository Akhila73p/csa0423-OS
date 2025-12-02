#include <stdio.h>

int main() {
    int n, tq;
    int bt[10], rt[10], wt[10], tat[10];
    int time = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Burst time P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];          // remaining time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (rt[i] > 0) {
                done = 0;
                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    rt[i] = 0;
                    tat[i] = time;       // completion time
                }
            }
        }
        if (done) break;
    }

    for (int i = 0; i < n; i++)
        wt[i] = tat[i] - bt[i];

    printf("\nRound Robin Scheduling Completed.\n");
    for (int i = 0; i < n; i++)
        printf("P%d WT=%d TAT=%d\n", i + 1, wt[i], tat[i]);

    return 0;
}

