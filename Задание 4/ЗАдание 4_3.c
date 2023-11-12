#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    pthread_t thread_id = pthread_self();

    struct sched_param param;
    int policy;
    pthread_getschedparam(thread_id, &policy, &param);

    printf("Thread ID: %lu, Priority: %d\n", (unsigned long)thread_id, param.sched_priority);

    for (int i = 0; i < 10; i++) {
        printf("Thread: Line %d\n", i + 1);
    }
    return NULL;
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);

    pthread_t thread;
    int result = pthread_create(&thread, NULL, thread_function, NULL);
    
    if (result != 0) {
        perror("Thread creation failed");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        printf("Main: Line %d\n", i + 1);
    }

    pthread_join(thread, NULL);

    return 0;
}
