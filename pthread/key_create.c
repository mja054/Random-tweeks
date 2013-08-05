#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

pthread_key_t key;
pthread_t t1, t2;

void*
func(void *arg)
{
        int ret;
        char *value = NULL;
        pthread_t thr;

        printf ("In thread1\n");

        thr = pthread_self ();

        ret = memcmp (&t1, &thr, sizeof (pthread_t));
        if (ret) {
                perror ("t1 and thr1 are diff");
                pthread_exit((void*)"t1 failure");
        } else
                printf ("t1 and thr1 are same\n");

        ret = pthread_key_create (&key, NULL);
        if (ret) {
                perror ("pthread_key_create failed");
                pthread_exit((void*)"failure");
        } else
                printf ("t1: pthread_key_create successful\n");

        ret = pthread_setspecific(key, "thread 1");
        if (ret) {
                perror ("pthread_setspecific failed");
                pthread_exit((void*)"failure");
        } else
                printf ("t1: pthread_setspecific successful\n");

        sleep  (5);

        value = (char *) pthread_getspecific(key);
        if (!value) {
                perror ("pthread_getspecific failed");
                pthread_exit((void*)"failure");
        } else
                printf ("t1: thread1 getspecific: %s\n", value);

        pthread_exit((void*)"t1 exiting");
}

void*
func1(void *arg)
{
        int ret;
        char *value = NULL;
        pthread_t thr;

        printf ("In thread 2\n");

        thr = pthread_self ();

        ret = memcmp (&t2, &thr, sizeof (pthread_t));
        if (ret) {
                perror ("t2 and thr2 are diff");
                pthread_exit((void*)"failure");
        } else
                printf ("t2: t2 and thr are same\n");

        ret = pthread_setspecific(key, "thread 2");
        if (ret) {
                perror ("pthread_setspecific failed");
                pthread_exit((void*)"failure");
        } else
                printf ("t2: pthread_setspecific successful\n");

        value = (char *) pthread_getspecific(key);
        if (!value) {
                perror ("pthread_getspecific failed");
                pthread_exit((void*)"failure");
        } else
                printf ("t2: thread2 getspecific: %s\n", value);

        pthread_exit((void*)"t2 done");
}

int
main (int argc, char *argv[])
{
        char *str1 = NULL, *str2 = NULL;

        pthread_create (&t1, NULL, func, NULL);
        sleep(2);
        pthread_create (&t2, NULL, func1, NULL);

        pthread_join (t1, (void **) &str1);
        pthread_join (t2, (void **) &str2);

        printf ("str1: %s\nstr2: %s\n", str1, str2);

        printf ("done \n");

        return 0;
}
