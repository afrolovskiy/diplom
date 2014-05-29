#include <pthread.h>

pthread_mutex_t m1;
int x = 0;

void* run_thread1(void* args) {
  int i = 0;
  while (1) {
    if (i % 10 == 5) {
      pthread_mutex_lock(&m1);
      x = x - 1;
      pthread_mutex_unlock(&m1);
    }
    i++;
  }
  return NULL;
}

void* run_thread2(void* args) {
  while (1) {
    pthread_mutex_lock(&m1);
    x = x + 1;
    pthread_mutex_unlock(&m1);
  }
  return NULL;
}

int main(int argc, char** argv) {
  pthread_t thread1, thread2;

  pthread_mutex_init(&m1, NULL);

  pthread_create(&thread1, NULL, run_thread1, NULL);
  pthread_create(&thread2, NULL, run_thread2, NULL);
      
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
      
  pthread_mutex_destroy(&m1);

  return 0;
}

