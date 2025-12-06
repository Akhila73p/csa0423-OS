#include <iostream>
#include <pthread.h>
#include <semaphore.h>
using namespace std;

sem_t rw_mutex;
pthread_mutex_t readLock;
int readCount = 0;

void* reader(void*) {
    pthread_mutex_lock(&readLock);
    readCount++;
    if (readCount == 1)
        sem_wait(&rw_mutex);   // First reader locks writer
    pthread_mutex_unlock(&readLock);

    cout << "Reader is reading..." << endl;

    pthread_mutex_lock(&readLock);
    readCount--;
    if (readCount == 0)
        sem_post(&rw_mutex);   // Last reader unlocks writer
    pthread_mutex_unlock(&readLock);

    return NULL;
}

void* writer(void*) {
    sem_wait(&rw_mutex);
    cout << "Writer is writing..." << endl;
    sem_post(&rw_mutex);
    return NULL;
}

int main() {
    pthread_t r, w;

    sem_init(&rw_mutex, 0, 1);
    pthread_mutex_init(&readLock, NULL);

    pthread_create(&r, NULL, reader, NULL);
    pthread_create(&w, NULL, writer, NULL);

    pthread_join(r, NULL);
    pthread_join(w, NULL);

    return 0;
}

