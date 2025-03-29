#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock1, lock2;

void* task1(void* arg) {
    pthread_mutex_lock(&lock1);
    sleep(1); // Simulate work
    pthread_mutex_lock(&lock2);
    printf("Task 1 done\n");
    pthread_mutex_unlock(&lock2);
    pthread_mutex_unlock(&lock1);
    return NULL;
}

void* task2(void* arg) {
    pthread_mutex_lock(&lock2);
    sleep(1); // Simulate work
    pthread_mutex_lock(&lock1);
    printf("Task 2 done\n");
    pthread_mutex_unlock(&lock1);
    pthread_mutex_unlock(&lock2);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_mutex_init(&lock1, NULL);
    pthread_mutex_init(&lock2, NULL);
    pthread_create(&t1, NULL, task1, NULL);
    pthread_create(&t2, NULL, task2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_mutex_destroy(&lock1);
    pthread_mutex_destroy(&lock2);
    return 0;
}
// Fix: Consistent lock order (e.g., always lock1 then lock2)
