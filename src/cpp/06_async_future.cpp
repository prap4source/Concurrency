#include <iostream>
#include <future>

int compute(int x) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return x * x;
}

int main() {
    std::future<int> fut = std::async(std::launch::async, compute, 5);
    std::cout << "Computing...\n";
    std::cout << "Result: " << fut.get() << "\n"; // Blocks until ready
    return 0;
}
