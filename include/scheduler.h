#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "job.h"
#include <queue>
#include <vector>

enum class SchedulingType {
    FCFS,
    PRIORITY,
    SJF
};

class Scheduler {
private:
    SchedulingType type;

    std::vector<Job> job_list;

public:
    Scheduler(SchedulingType type);

    void addJob(const Job& job);
    std::vector<Job> getScheduledJobs();

    void adaptStrategy(int queue_size);
};

#endif
