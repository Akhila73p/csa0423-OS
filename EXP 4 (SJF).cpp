#include <stdio.h>
int main() {
    int n, bt[20], p[20], wt[20], tat[20], i, j, temp;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter burst times:\n");
    for(i=0;i<n;i++){
        scanf("%d",&bt[i]);
        p[i] = i+1;
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(bt[j] < bt[i]){
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i];  p[i] = p[j];  p[j] = temp;
            }
        }
    }
    wt[0] = 0;
    for(i=1;i<n;i++)
        wt[i] = wt[i-1] + bt[i-1];
    for(i=0;i<n;i++)
        tat[i] = wt[i] + bt[i];
    printf("P\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
    return 0;
}

