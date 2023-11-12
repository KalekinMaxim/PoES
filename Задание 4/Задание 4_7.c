#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaphore;

void *child_thread(void *arg) {
    sem_wait(&semaphore);

    printf("Child Thread: Received a signal, Thread ID: %lu\n", (unsigned long)pthread_self());

    return NULL;
}

int main() {
    sem_init(&semaphore, 0, 0);

    pthread_t thread;
    int result = pthread_create(&thread, NULL, child_thread, NULL);

    if (result != 0) {
        perror("Thread creation failed");
        return 1;
    }

    sem_post(&semaphore);

    pthread_join(thread, NULL);

    sem_destroy(&semaphore);

    return 0;
}