#include <iostream>
#include <thread>
#include <mutex>
#include <queue>

template<typename T>
class ThreadSafeQueue {
    std::queue<T> q;
    std::mutex mtx;
public:
    void push(T value) {
        std::lock_guard<std::mutex> lock(mtx);
        q.push(value);
    }
    bool pop(T& value) {
        std::lock_guard<std::mutex> lock(mtx);
        if (q.empty()) return false;
        value = q.front();
        q.pop();
        return true;
    }
};

void producer(ThreadSafeQueue<int>& q) {
    for (int i = 0; i < 5; ++i) q.push(i);
}

void consumer(ThreadSafeQueue<int>& q) {
    int value;
    while (q.pop(value)) std::cout << "Consumed: " << value << "\n";
}

int main() {
    ThreadSafeQueue<int> q;
    std::thread p(producer, std::ref(q));
    std::thread c(consumer, std::ref(q));
    p.join();
    c.join();
    return 0;
}
