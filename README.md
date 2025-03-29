# ConcurrencyPrep
A mixed C and C++ concurrency learning repo for Linux systems programming, featuring pthreads (C) and std::thread (C++).

## Topics
### C (pthreads)
- Thread basics (`pthread_create`, `pthread_join`)
- Synchronization (`pthread_mutex_t`)
- Coordination (`pthread_cond_t`)
- Thread pools with pthreads
- Deadlocks and mitigation

### C++ (std::thread)
- Thread basics (`std::thread`)
- Synchronization (`std::mutex`, `std::lock_guard`, `std::unique_lock`)
- Coordination (`std::condition_variable`)
- Async programming (`std::async`, `std::future`)
- Thread safety, deadlocks, and atomics

## Build with CMake
```bash
mkdir build && cd build
cmake ..
make
# Run C executable
./c/01_thread_basics.o
# Run C++ executable
./cpp/01_thread_basics.o

## Compile individual
C
gcc -std=c11 -pthread src_c/01_thread_basics.c -o 01_thread_basics.o
./01_thread_basics.o

C++
g++ -std=c++17 -pthread src_cpp/01_thread_basics.cpp -o 01_thread_basics.o
./01_thread_basics.o

## Compile All files manually
for f in src/c/*.c; do gcc -std=c11 -pthread "$f" -o "${f%.c}.o"; done
for f in src/cpp/*.cpp; do g++ -std=c++17 -pthread "$f" -o "${f%.cpp}.o"; done
