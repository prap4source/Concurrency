#include <iostream>
#include <thread>

void task(int id) {
    std::cout << "Thread " << id << " running\n";
}

int main() {
    std::thread t1(task, 1);
    std::thread t2(task, 2);
    t1.join(); // Wait for t1
    t2.detach(); // Let t2 run independently
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Ensure t2 prints
    std::cout << "Main thread done\n";
    return 0;
}
