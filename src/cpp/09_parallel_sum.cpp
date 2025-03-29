#include <iostream>
#include <vector>
#include <thread>

void sumRange(const std::vector<int>& v, int start, int end, int& result) {
    result = 0;
    for (int i = start; i < end; ++i) result += v[i];
}

int main() {
    std::vector<int> data(1000, 1); // 1000 ones
    int sum1 = 0, sum2 = 0;
    std::thread t1(sumRange, std::cref(data), 0, 500, std::ref(sum1));
    std::thread t2(sumRange, std::cref(data), 500, 1000, std::ref(sum2));
    t1.join();
    t2.join();
    std::cout << "Total: " << (sum1 + sum2) << "\n"; // Should be 1000
    return 0;
}
