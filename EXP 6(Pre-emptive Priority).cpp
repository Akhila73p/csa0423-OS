#include <stdio.h>
int main() {
    int n;
    int bt[10], pr[10], rt[10];
    int wt[10], tat[10];
    int time = 0, completed = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Burst time P%d: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Priority P%d (smaller = higher): ", i + 1);
        scanf("%d", &pr[i]);
        rt[i] = bt[i];         
    }
    while (completed < n) {
        int idx = -1;
        int best = 100000;
        for (int i = 0; i < n; i++) {
            if (rt[i] > 0 && pr[i] < best) {
                best = pr[i];
                idx = i;
            }
        }
        rt[idx]--;          
        time++;

        if (rt[idx] == 0) { // finished
            completed++;
            tat[idx] = time;        // finish time
        }
    }

    for (int i = 0; i < n; i++)
        wt[i] = tat[i] - bt[i];

    printf("\nPreemptive Priority Scheduling Completed.\n");
    printf("P\tBT\tPR\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, bt[i], pr[i], wt[i], tat[i]);

    return 0;
}

