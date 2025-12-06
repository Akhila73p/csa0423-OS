#include <iostream>
#include <pthread.h>
using namespace std;

pthread_mutex_t lockVar;
int counter = 0;

void* task(void*) {
    pthread_mutex_lock(&lockVar);

    counter++;
    cout << "Counter = " << counter << endl;

    pthread_mutex_unlock(&lockVar);
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_mutex_init(&lockVar, NULL);

    pthread_create(&t1, NULL, task, NULL);
    pthread_create(&t2, NULL, task, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}

