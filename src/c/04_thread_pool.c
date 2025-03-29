#include <stdio.h>
#include <pthread.h>

int item = 0;
pthread_mutex_t lock;
pthread_cond_t cond;

void* producer(void* arg) {
    pthread_mutex_lock(&lock);
    item = 42;
    printf("Produced: %d\n", item);
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* consumer(void* arg) {
    pthread_mutex_lock(&lock);
    while (item == 0) {
        pthread_cond_wait(&cond, &lock);
    }
    printf("Consumed: %d\n", item);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t prod, cons;
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);
    pthread_create(&cons, NULL, consumer, NULL);
    pthread_create(&prod, NULL, producer, NULL);
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);
    return 0;
}
