#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void flexible_print(int id) {
    std::unique_lock<std::mutex> lock(mtx, std::defer_lock);
    lock.lock(); // Manual lock
    std::cout << "Thread " << id << " with unique lock\n";
    lock.unlock(); // Manual unlock
}

int main() {
    std::thread t1(flexible_print, 1);
    std::thread t2(flexible_print, 2);
    t1.join();
    t2.join();
    return 0;
}
