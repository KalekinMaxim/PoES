#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg) {
    int local_var = 42;
    printf("Thread: Local Variable Address: %p\n", &local_var);

    struct sched_param param;
    int policy;
    pthread_getschedparam(pthread_self(), &policy, &param);
    printf("Thread: Priority: %d\n", param.sched_priority);

    return NULL;
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);

    pthread_t thread;
    pthread_attr_t attr;
    
    pthread_attr_init(&attr);

    struct sched_param param;
    param.sched_priority = 20; // Приоритет 20
    pthread_attr_setschedparam(&attr, &param);

    size_t stack_size = 4096; // Размер стека 4KB
    pthread_attr_setstacksize(&attr, stack_size);

    int result = pthread_create(&thread, &attr, thread_function, NULL);

    if (result != 0) {
        perror("Thread creation failed");
        return 1;
    }

    int local_var = 10;
    printf("Main: Local Variable Address: %p\n", &local_var);

    struct sched_param main_param;
    int main_policy;
    pthread_getschedparam(pthread_self(), &main_policy, &main_param);
    printf("Main: Priority: %d\n", main_param.sched_priority);

    pthread_join(thread, NULL);

    pthread_attr_destroy(&attr);

    return 0;
}