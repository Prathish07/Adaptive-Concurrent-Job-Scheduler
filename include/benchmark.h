#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <vector>
#include <chrono>

class Benchmark {
public:
    static void measure(std::vector<long long>& times);
};

#endif
