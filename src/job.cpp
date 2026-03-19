#include "../include/job.h"
#include <thread>

Job::Job(int id, int priority, int exec_time, std::function<void()> func)
    : id(id), priority(priority), execution_time(exec_time), task(func) {
    arrival_time = std::chrono::steady_clock::now();
}

void Job::execute() {
    std::this_thread::sleep_for(std::chrono::milliseconds(execution_time));
    task();
}