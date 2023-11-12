#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void cleanup_handler(void *arg) {
    printf("Child Thread: Cleanup function executed, Thread ID: %lu\n", (unsigned long)pthread_self());
}

void *child_thread(void *arg) {
    pthread_cleanup_push(cleanup_handler, NULL);

    sleep(2);
    printf("Child Thread: Received a cancel request, Thread ID: %lu\n", (unsigned long)pthread_self());
    pthread_testcancel();

    pthread_cleanup_pop(1);

    return NULL;
}

int main() {
    pthread_t thread;
    int result = pthread_create(&thread, NULL, child_thread, NULL);

    if (result != 0) {
        perror("Thread creation failed");
        return 1;
    }

    sleep(2);

    pthread_cancel(thread);

    pthread_join(thread, NULL);

    return 0;
}
