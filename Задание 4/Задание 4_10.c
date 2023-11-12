#include <stdio.h>
#include <pthread.h>

pthread_mutex_t parent_mutex;
pthread_mutex_t child_mutex;

void *child_thread(void *arg) {
    for (int i = 0; i < 10; i++) {

        pthread_mutex_lock(&parent_mutex);

        printf("Child: Line %d\n", i + 1);

        pthread_mutex_unlock(&parent_mutex);

        pthread_mutex_lock(&child_mutex);
        pthread_mutex_unlock(&child_mutex);
    }
    return NULL;
}

int main() {
    pthread_mutex_init(&parent_mutex, NULL);
    pthread_mutex_init(&child_mutex, NULL);

    pthread_t thread;
    int result = pthread_create(&thread, NULL, child_thread, NULL);

    if (result != 0) {
        perror("Thread creation failed");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&parent_mutex);

        printf("Main: Line %d\n", i + 1);

        pthread_mutex_unlock(&parent_mutex);

        pthread_mutex_unlock(&child_mutex);

        pthread_mutex_lock(&child_mutex);
        pthread_mutex_unlock(&child_mutex);
    }

    pthread_join(thread, NULL);

    pthread_mutex_destroy(&parent_mutex);
    pthread_mutex_destroy(&child_mutex);

    return 0;
}


