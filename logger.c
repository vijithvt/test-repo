#include <stdio.h>
#include <time.h>
#include "logger.h"

static void write_timestamp(void)
{
    time_t now = time(NULL);
    printf("[%ld] ", (long)now);
}

void logger_init(void)
{
    write_timestamp();
    printf("Logger initialized\n");
}

void logger_log(const char *message)
{
    write_timestamp();
    printf("LOG: %s\n", message);
}

void logger_error(const char *message)
{
    write_timestamp();
    printf("ERROR: %s\n", message);
}