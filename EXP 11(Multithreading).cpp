#include <stdio.h>
#include <windows.h>

DWORD WINAPI task(LPVOID arg) {
    char *msg = (char*)arg;
    printf("Thread executing: %s\n", msg);
    return 0;
}

int main() {
    HANDLE t1, t2;

    t1 = CreateThread(NULL, 0, task, (LPVOID)"Thread 1", 0, NULL);
    t2 = CreateThread(NULL, 0, task, (LPVOID)"Thread 2", 0, NULL);

    WaitForSingleObject(t1, INFINITE);
    WaitForSingleObject(t2, INFINITE);

    CloseHandle(t1);
    CloseHandle(t2);

    return 0;
}



