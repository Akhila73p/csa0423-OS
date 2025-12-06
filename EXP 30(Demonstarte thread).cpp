#include <stdio.h>
#include <pthread.h>

void* fun(void *arg) {
    printf("Thread is running...\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t t1;
    
    pthread_create(&t1, NULL, fun, NULL);
    
    if (pthread_equal(pthread_self(), t1))
        printf("Threads are equal\n");
    else
        printf("Threads are NOT equal\n");

    pthread_join(t1, NULL);
    printf("Thread joined successfully\n");

    return 0;
}

