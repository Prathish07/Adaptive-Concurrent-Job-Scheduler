# Adaptive Concurrent Job Scheduler (C++)

A high-performance multi-threaded job scheduling system built in C++ that simulates real-world operating system scheduling behavior with adaptive optimization strategies.

---

## Features

- Thread Pool with concurrent task execution  
- Multiple Scheduling Algorithms:
  - First Come First Serve (FCFS)
  - Priority Scheduling
  - Shortest Job First (SJF)
- Adaptive Scheduling Strategy (dynamic switching based on system load)
- Performance Benchmarking:
  - Latency
  - Throughput
  - Total Execution Time
- Stress-tested with high-load job simulations (1000+ tasks)

---

## System Architecture
Jobs → Scheduler → Thread Pool → Execution → Benchmarking

---

## Tech Stack

- C++17  
- Multithreading (`std::thread`)  
- Synchronization (`std::mutex`, `std::condition_variable`)  
- System Design Concepts  

---

## How to Run

### 1. Compile

```bash
g++ -std=c++17 src/*.cpp -Iinclude -o build/scheduler.exe
```

### 2. Run

```bash
./build/scheduler.exe
```
