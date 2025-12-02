#include <stdio.h>
int main() {
    int n;
    int bt[10], p[10], wt[10], tat[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Burst time P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // sort by burst time (simple SJF)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bt[j] < bt[i]) {
                int t = bt[i]; bt[i] = bt[j]; bt[j] = t;
                t = p[i];      p[i] = p[j];   p[j] = t;
            }
        }
    }

    wt[0] = 0;
    tat[0] = bt[0];
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
    }

    printf("\nNon-preemptive SJF Completed.\n");
    for (int i = 0; i < n; i++)
        printf("P%d WT=%d TAT=%d\n", p[i], wt[i], tat[i]);

    return 0;
}

