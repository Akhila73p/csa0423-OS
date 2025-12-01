#include <stdio.h>
int main() {
    int parentPID = 1234;   // simulated parent process ID
    int parentPPID = 1;     // simulated parent's parent (init process)
    int childPID = 1235;    // simulated child process ID

    printf("Parent PID=%d PPID=%d\n", parentPID, parentPPID);
    printf("Child PID=%d PPID=%d\n", childPID, parentPID);

    return 0;
}
