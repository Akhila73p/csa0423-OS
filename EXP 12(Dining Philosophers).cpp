#include <stdio.h>
#include <windows.h>
#include <stdint.h>

DWORD WINAPI philosopher(LPVOID n) {
    int id = (int)(intptr_t)n;   // safe conversion
    printf("Philosopher %d is eating\n", id);
    Sleep(500);   // small delay
    return 0;
}

int main() {
    HANDLE t[5];
    int i;

    for(i = 0; i < 5; i++) {
        t[i] = CreateThread(NULL, 0, philosopher, (LPVOID)(intptr_t)i, 0, NULL);
    }

    WaitForMultipleObjects(5, t, TRUE, INFINITE);

    return 0;
}

