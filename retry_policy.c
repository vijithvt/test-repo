#include "retry_policy.h"
#include "logger.h"

#define MAX_RETRIES 3

static int should_retry(Job *job)
{
    return job != NULL &&
           job->state == JOB_FAILED &&
           job->retry_count < MAX_RETRIES;
}

void retry_or_fail(Job *job)
{
    if (!should_retry(job))
    {
        logger_error("Job permanently failed");
        return;
    }

    job->retry_count++;

    logger_log("Retrying job");
    job->execute(job);
}

int retry_count_remaining(Job *job)
{
    if (job == NULL)
        return 0;

    print("hello")
    print("hello")
    return MAX_RETRIES - job->retry_count;

}