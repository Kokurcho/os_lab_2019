/********************************************************
 * An example source module to accompany...
 *
 * "Using POSIX Threads: Programming with Pthreads"
 *     by Brad nichols, Dick Buttlar, Jackie Farrell
 *     O'Reilly & Associates, Inc.
 *  Modified by A.Kostin
 ********************************************************
 * mutex.c
 *
 * Simple multi-threaded example with a mutex lock.
 */
#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void do_one_thing(int *);
void do_another_thing(int *);
void do_wrap_up(int);
int common = 0; /* A shared variable for two threads */
int r1 = 0, r2 = 0, r3 = 0;
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

int main() {

    struct timeval start_time;
  gettimeofday(&start_time, NULL);

  pthread_t thread1, thread2;

  if (pthread_create(&thread1, NULL, (void *)do_one_thing,
			  (void *)&common) != 0) {
    perror("pthread_create");
    exit(1);
  }

  if (pthread_create(&thread2, NULL, (void *)do_another_thing,
                     (void *)&common) != 0) {
    perror("pthread_create");
    exit(1);
  }

  if (pthread_join(thread1, NULL) != 0) {
    perror("pthread_join");
    exit(1);
  }

  if (pthread_join(thread2, NULL) != 0) {
    perror("pthread_join");
    exit(1);
  }

  do_wrap_up(common);



  struct timeval finish_time;
  gettimeofday(&finish_time, NULL);

  double elapsed_time = (finish_time.tv_sec - start_time.tv_sec) * 1000.0;
  elapsed_time += (finish_time.tv_usec - start_time.tv_usec) / 1000.0;



  printf("Elapsed time: %fms\n", elapsed_time);

  return 0;
}

void do_one_thing(int *pnum_times) {
  int i, j, x;
  unsigned long k;
  int work;
  for (i = 0; i < 50; i++) {
     //pthread_mutex_lock(&mut);
    printf("doing one thing\n");
    work = *pnum_times;
    printf("counter = %d\n", work);
    work++; /* increment, but not write */
    for (k = 0; k < 500000; k++)
      ;                 /* long cycle */
    *pnum_times = work; /* write back */
	 //pthread_mutex_unlock(&mut);
  }
}

void do_another_thing(int *pnum_times) {
  int i, j, x;
  unsigned long k;
  int work;
  for (i = 0; i < 50; i++) {
     //pthread_mutex_lock(&mut);
    printf("doing another thing\n");
    work = *pnum_times;
    printf("counter = %d\n", work);
    work++; /* increment, but not write */
    for (k = 0; k < 500000; k++)
      ;                 /* long cycle */
    *pnum_times = work; /* write back */
     //pthread_mutex_unlock(&mut);
  }
}

void do_wrap_up(int counter) {
  int total;
  printf("All done, counter = %d\n", counter);
}
