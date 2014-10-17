/*
 * mutex1.cpp
 *
 *  Created on: Sep 29, 2014
 *      Author: ErnieOnTheRun
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *functionC(void *ptr );
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int  counter = 0;

int main()
{
   int rc1, rc2;
   pthread_t thread1, thread2;
   const char *message1 = "Thread 1";
   const char *message2 = "Thread 2";

   /* Create independent threads each of which will execute functionC */

    rc1 = pthread_create( &thread1, NULL, functionC, (void*) message1);

   if(rc1)
   {
      printf("Thread creation failed: %d\n", rc1);
   }

   rc2=pthread_create( &thread2, NULL, functionC, (void*) message2);

   if(rc2)
   {
      printf("Thread creation failed: %d\n", rc2);
   }

   /* Wait till threads are complete before main continues. Unless we  */
   /* wait we run the risk of executing an exit which will terminate   */
   /* the process and all threads before the threads have completed.   */

   pthread_join( thread1, NULL);
   pthread_join( thread2, NULL);

   exit(EXIT_SUCCESS);
}

void *functionC(void *ptr )
{
   pthread_mutex_lock( &mutex1 );
   counter++;
   printf("Counter value: %d\n",counter);
   pthread_mutex_unlock( &mutex1 );
}
