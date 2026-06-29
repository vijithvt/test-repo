#include "pipeline.h"
#include "scheduler.h"
#include "logger.h"

static void step_fetch(Job *job)
{
    logger_log("Fetching data");
    job->state = JOB_FETCHED;
}

static void step_validate(Job *job)
{
    logger_log("Validating data");

    if (job->payload == NULL)
    {
        job->state = JOB_FAILED;
        logger_error("Validation failed");
        return;
    }

    job->state = JOB_VALIDATED;
}

static void step_execute(Job *job)
{
    logger_log("Executing job");

    if (job->state != JOB_VALIDATED)
    {
        logger_error("Job not validated");
        job->state = JOB_FAILED;
        return;
    }

    job->state = JOB_COMPLETED;
}

void pipeline_execute(Job *job)
{
    step_fetch(job);
    step_validate(job);

    if (job->state == JOB_FAILED)
        return;

    step_execute(job);
}

void pipeline_schedule(Job *job)
{
    job->execute = pipeline_execute;
    scheduler_submit(job);
}