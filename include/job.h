#ifndef JOB_H
#define JOB_H

#include <functional>
#include <chrono>

class Job {
public:
    int id;
    int priority;
    int execution_time; // ms
    std::function<void()> task;

    std::chrono::steady_clock::time_point arrival_time;

    Job(int id, int priority, int exec_time, std::function<void()> func);

    void execute();
};

#endif
