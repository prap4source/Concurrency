#include <stdio.h>
#include <pthread.h>

void* thread_func(void* arg) {
    long id = (long)arg;
    printf("Thread %ld running\n", id);
    return NULL;
}

int main() {
    pthread_t threads[2];
    for (long i = 0; i < 2; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void*)i);
    }
    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("Main thread done\n");
    return 0;
}
