## Topics
- Thread basics (`std::thread`)
- Synchronization (`std::mutex`, `std::lock_guard`, `std::unique_lock`)
- Coordination (`std::condition_variable`)
- Async programming (`std::async`, `std::future`)
- Thread safety, deadlocks, and atomics

## Build
```bash
mkdir build && cd build
cmake ..
make
./<executable_name>

## Compile Single file
g++ -std=c++17 -pthread src/01_thread_basics.cpp -o 01_thread_basics.o
./01_thread_basics

## For all files
for f in src/cpp/*.cpp; do g++ -std=c++17 -pthread "$f" -o "${f%.cpp}".o; done
