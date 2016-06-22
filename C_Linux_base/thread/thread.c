#include <pthread.h>
#include <stdio.h>

void* thread1()
{
  printf("1");
  return NULL;
}

void* thread2()
{
   printf("2");
   return NULL;
}
int main ()
{
   pthread_t t1;
   pthread_t t2;
   pthread_create(&t1,NULL,thread1,NULL);
   pthread_create(&t2,NULL,thread2,NULL);
   pthread_join(t1,NULL);
   return 0;
}
