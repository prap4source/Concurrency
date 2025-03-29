#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void print(int id) {
    mtx.lock();
    std::cout << "Thread " << id << " printing\n";
    mtx.unlock();
}

int main() {
    std::thread t1(print, 1);
    std::thread t2(print, 2);
    t1.join();
    t2.join();
    return 0;
}
