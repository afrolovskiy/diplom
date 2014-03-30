#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;

void *foo(void *arg) {
    int *count = arg;
    unsigned int thread_id = pthread_self();
    while (*count < 10) {
        pthread_mutex_lock(&lock);
        printf("thread ID = %u ,count = %d\n", thread_id,  *count);
        (*count)++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t thread1, thread2;
    int count = 0;

    pthread_mutex_init(&lock, NULL);
    pthread_create(&thread1, NULL, &foo, &count);
    pthread_create(&thread2, NULL, &foo, &count);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_mutex_destroy(&lock);

    return 0;
}
