#include <pthread.h>
#include <stdio.h>

int x = 123;

void* run_thread(void* args) {
  printf("x = %x\n", x);
  return NULL;
}

int main(int argc, char** argv) {
  pthread_t thread1, thread2;

  pthread_create(&thread1, NULL, run_thread, NULL);
  pthread_create(&thread2, NULL, run_thread, NULL);
      
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  return 0;
}

