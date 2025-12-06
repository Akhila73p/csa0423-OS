#include <iostream>
#include <pthread.h>
#include <semaphore.h>
using namespace std;

sem_t emptySlots, fullSlots;
pthread_mutex_t mutexLock;
int bufferData = 0, item = 1;

void* producer(void*) {
    sem_wait(&emptySlots);
    pthread_mutex_lock(&mutexLock);

    bufferData = item++;
    cout << "Produced: " << bufferData << endl;

    pthread_mutex_unlock(&mutexLock);
    sem_post(&fullSlots);
    return NULL;
}

void* consumer(void*) {
    sem_wait(&fullSlots);
    pthread_mutex_lock(&mutexLock);

    cout << "Consumed: " << bufferData << endl;

    pthread_mutex_unlock(&mutexLock);
    sem_post(&emptySlots);
    return NULL;
}

int main() {
    pthread_t p, c;

    sem_init(&emptySlots, 0, 1);
    sem_init(&fullSlots, 0, 0);
    pthread_mutex_init(&mutexLock, NULL);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    return 0;
}

