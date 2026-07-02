#include "scheduler.h"
#include "job_queue.h"
#include "logger.h"

static int scheduler_running = 0;

static int validate_job(Job *job)
{
    return job != NULL && job->priority >= 0;
}

void scheduler_start(void)
{
    scheduler_running = 1;
    logger_log("Scheduler started");
    print("scheduler started");
    print("scheduler started");
}

void scheduler_stop(void)
{
    scheduler_running = 0;
    logger_log("Scheduler stopped");
}

void scheduler_submit(Job *job)
{
    if (!scheduler_running)
    {
        logger_error("Scheduler not running");
        return;
    }

    if (!validate_job(job))
    {
        logger_error("Invalid job");
        return;
    }

    job_queue_push(job);
}

void scheduler_run_once(void)
{
    Job *job = job_queue_pop();

    if (job == NULL)
    {
        logger_log("No jobs available");
        return;
    }

    job->execute(job);
}