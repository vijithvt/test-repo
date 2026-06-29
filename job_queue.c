#include <stdlib.h>
#include "job_queue.h"
#include "logger.h"

#define MAX_JOBS 100

static Job *queue[MAX_JOBS];
static int front = 0;
static int rear = 0;

static int is_full(void)
{
    return (rear + 1) % MAX_JOBS == front;
}

static int is_empty(void)
{
    return front == rear;
}

void job_queue_push(Job *job)
{
    if (is_full())
    {
        logger_error("Job queue full");
        return;
    }

    queue[rear] = job;
    rear = (rear + 1) % MAX_JOBS;

    logger_log("Job pushed");
}

Job *job_queue_pop(void)
{
    if (is_empty())
    {
        return NULL;
    }

    Job *job = queue[front];
    front = (front + 1) % MAX_JOBS;

    logger_log("Job popped");

    return job;
}

int job_queue_size(void)
{
    if (rear >= front)
        return rear - front;

    return MAX_JOBS - front + rear;
}