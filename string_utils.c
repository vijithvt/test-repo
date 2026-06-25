#include <stdio.h>
#include <string.h>
#include "string_utils.h"
#include "logger.h"

void print_message(const char *message)
{
    printf("Message: %s\n", message);
    logger_log("Message printed");
}

int string_length(const char *text)
{
    return strlen(text);
}

void print_number(int value)
{
    printf("Value: %d\n", value);
}

void uppercase(char *text)
{
    while (*text)
    {
        if (*text >= 'a' && *text <= 'z')
        {
            *text = *text - 32;
        }
        text++;
    }
}