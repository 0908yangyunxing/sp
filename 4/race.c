#include <stdio.h>
#include <pthread.h>

#define LOOPS 100000
int money = 10000;

void *inc()
{
  for (int i=0; i<LOOPS; i++) {
    money = money + 1000;
  }
  return NULL;
}

void *dec()
{
  for (int i=0; i<LOOPS; i++) {
    money = money - 1000;
  }
  return NULL;
}


int main() 
{
  pthread_t thread1, thread2;

  pthread_create(&thread1, NULL, inc, NULL);
  pthread_create(&thread2, NULL, dec, NULL);

  pthread_join( thread1, NULL);
  pthread_join( thread2, NULL);
  printf("money=%d\n", money);
}