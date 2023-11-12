#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    char **strings = (char **)arg;
    for (int i = 0; strings[i] != NULL; i++) {
        printf("Thread: %s\n", strings[i]);
    }
    return NULL;
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);

    char *thread1_strings[] = {"Thread 1 Line 1", "Thread 1 Line 2", "Thread 1 Line 3", NULL};
    char *thread2_strings[] = {"Thread 2 Line 1", "Thread 2 Line 2", "Thread 2 Line 3", NULL};
    char *thread3_strings[] = {"Thread 3 Line 1", "Thread 3 Line 2", "Thread 3 Line 3", NULL};
    char *thread4_strings[] = {"Thread 4 Line 1", "Thread 4 Line 2", "Thread 4 Line 3", NULL};

    pthread_t thread1, thread2, thread3, thread4;

    pthread_create(&thread1, NULL, thread_function, (void *)thread1_strings);
    pthread_create(&thread2, NULL, thread_function, (void *)thread2_strings);
    pthread_create(&thread3, NULL, thread_function, (void *)thread3_strings);
    pthread_create(&thread4, NULL, thread_function, (void *)thread4_strings);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);

    return 0;
}
