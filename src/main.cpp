#include "../include/thread_pool.h"
#include "../include/scheduler.h"
#include "../include/benchmark.h"

#include <iostream>
#include <vector>
#include <chrono>
#include <mutex>
#include <atomic>
#include <cstdlib>
#include <thread>
#include <mutex>

int main() {

    // Config
    const int NUM_THREADS = 4;
    const int NUM_JOBS = 1000;

    ThreadPool pool(NUM_THREADS);

    Scheduler scheduler(SchedulingType::SJF);

    // Seed random generator
    srand(time(0));

    // Create jobs (Stress Test)
    for (int i = 0; i < NUM_JOBS; i++) {
        scheduler.addJob(Job(
            i,
            rand() % 10,          // priority
            rand() % 500 + 50,   // execution time (50–550 ms)
            [i]() {
                std::cout << "Job " << i << " executed\n";
            }
        ));
    }

    // Adaptive strategy (optional)
    scheduler.adaptStrategy(NUM_JOBS);

    // Get scheduled order
    auto jobs = scheduler.getScheduledJobs();

    // Benchmark data
    std::vector<long long> execution_times;
    std::mutex mtx;

    // Track completion
    std::atomic<int> completed_jobs(0);

    // Start global timer
    auto global_start = std::chrono::steady_clock::now();

    for (auto &job : jobs) {

        pool.enqueue([&job, &execution_times, &mtx, &completed_jobs]() {

            auto start = std::chrono::steady_clock::now();

            job.execute();

            auto end = std::chrono::steady_clock::now();

            long long duration =
                std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

            // Thread-safe push
            {
                std::lock_guard<std::mutex> lock(mtx);
                execution_times.push_back(duration);
            }

            completed_jobs++;
        });
    }

    // Wait until all jobs complete
    while (completed_jobs < NUM_JOBS) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    auto global_end = std::chrono::steady_clock::now();

    long long total_time =
        std::chrono::duration_cast<std::chrono::milliseconds>(global_end - global_start).count();

    std::cout << "\n=== Execution Summary ===\n";
    std::cout << "Total Jobs: " << NUM_JOBS << "\n";
    std::cout << "Total Wall Time: " << total_time << " ms\n";

    // Benchmark results
    Benchmark::measure(execution_times);

    return 0;
}