#include <pthread.h>

pthread_mutex_t m1, m2;
int x = 0, y = 0;

void* run_thread1(void* args) {
    while (1) {
	pthread_mutex_lock(&m1);
	int flag = (x > 0);
	pthread_mutex_unlock(&m1);

	if (flag) {
	    pthread_mutex_lock(&m2);
	    x = x - 1;
	    pthread_mutex_unlock(&m2);
	}
    }
    return NULL;
}

void* run_thread2(void* args) {
    while (1) {
	pthread_mutex_lock(&m1);
	int flag = (x < 10);
	pthread_mutex_unlock(&m1);

	if (flag) {
	    pthread_mutex_lock(&m2);
	    x = x + 1;
	    pthread_mutex_unlock(&m2);
	}
    }
    return NULL;
}

int main(int argc, char** argv) {
    pthread_t thread1, thread2

    pthread_mutex_init(&m1, NULL);
    pthread_mutex_init(&m2, NULL);

    pthread_create(&thread1, NULL, run_thread1, NULL);
    pthread_create(&thread2, NULL, run_thread2, NULL);
        
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
        
    pthread_mutex_destroy(&m1);
    pthread_mutex_destroy(&m2);

    return 0;
}

