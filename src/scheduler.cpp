#include "../include/scheduler.h"
#include <algorithm>

Scheduler::Scheduler(SchedulingType type) : type(type) {}

void Scheduler::addJob(const Job& job) {
    job_list.push_back(job);
}

std::vector<Job> Scheduler::getScheduledJobs() {

    if (type == SchedulingType::FCFS) {
        return job_list;
    }

    else if (type == SchedulingType::PRIORITY) {
        std::sort(job_list.begin(), job_list.end(),
                  [](Job &a, Job &b) {
                      return a.priority > b.priority;
                  });
    }

    else if (type == SchedulingType::SJF) {
        std::sort(job_list.begin(), job_list.end(),
                  [](Job &a, Job &b) {
                      return a.execution_time < b.execution_time;
                  });
    }

    return job_list;
}

void Scheduler::adaptStrategy(int queue_size) {

    if (queue_size > 20)
        type = SchedulingType::SJF;

    else if (queue_size > 10)
        type = SchedulingType::PRIORITY;

    else
        type = SchedulingType::FCFS;
}