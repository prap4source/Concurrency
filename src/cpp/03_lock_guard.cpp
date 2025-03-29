#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void safe_print(int id) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Thread " << id << " safely printing\n";
    // Lock auto-released on scope exit
}

int main() {
    std::thread t1(safe_print, 1);
    std::thread t2(safe_print, 2);
    t1.join();
    t2.join();
    return 0;
}
