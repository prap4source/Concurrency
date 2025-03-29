#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> counter(0);

void increment(int n) {
    for (int i = 0; i < n; ++i) counter.fetch_add(1, std::memory_order_relaxed);
}

int main() {
    std::thread t1(increment, 1000);
    std::thread t2(increment, 1000);
    t1.join();
    t2.join();
    std::cout << "Counter: " << counter.load() << "\n"; // Should be 2000
    return 0;
}
