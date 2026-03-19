#include "../include/benchmark.h"
#include <iostream>
#include <numeric>

void Benchmark::measure(std::vector<long long>& times) {
    long long total = std::accumulate(times.begin(), times.end(), 0LL);

    double avg = (double) total / times.size();

    std::cout << "Total Time: " << total << " ms\n";
    std::cout << "Average Latency: " << avg << " ms\n";
    std::cout << "Throughput: " << times.size() / (total / 1000.0) << " jobs/sec\n";
}