#include <pthread.h>

int x, y, z;
pthread_mutex_t m1, m2;

void munge(int *v, mutex *m) {
    pthread_mutex_lock(m);
    (*v)++;
    pthread_mutex_unlock(m);
}

void* thread1(void* args) {
    munge(&x, &m1);
    munge(&y, &m2);
    munge(&z, &m2);
}

void* thread2(void* args) {
    munge(&x, &m1);
    munge(&y, &m1);
    munge(&z, &m2);
}

int main(int argc, char** argv) {
    pthread_t threads[2];

    pthread_mutex_init(&m1, NULL);
    pthread_mutex_init(&m2, NULL);

    pthread_create(&threads[0], NULL, thread1, NULL);
    pthread_create(&threads[1], NULL, thread2, NULL);

    pthread_join(threads[1], NULL);
    pthread_join(threads[2], NULL);

    pthread_mutex_destroy(&m1);
    pthread_mutex_destroy(&m2);
    return 0;
}