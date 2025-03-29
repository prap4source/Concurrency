#ifndef PTHREAD_UTILS_H
#define PTHREAD_UTILS_H
#include <stdio.h>
#include <pthread.h>

static pthread_mutex_t print_lock = PTHREAD_MUTEX_INITIALIZER;

void safe_print(const char* msg) {
    pthread_mutex_lock(&print_lock);
    printf("%s", msg);
    pthread_mutex_unlock(&print_lock);
}
#endif
