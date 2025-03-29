#ifndef THREAD_UTILS_H
#define THREAD_UTILS_H
#include <iostream>
#include <mutex>

static std::mutex cout_mtx;

inline void safe_cout(const std::string& msg) {
    std::lock_guard<std::mutex> lock(cout_mtx);
    std::cout << msg;
}
#endif
