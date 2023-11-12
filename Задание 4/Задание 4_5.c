#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    int local_var = 42;
    printf("Thread: Local Variable Address: %p\n", &local_var);
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

    int local_var = 10; 
    printf("Main: Local Variable Address: %p\n", &local_var);

    pthread_join(thread, NULL);

    return 0;
}

