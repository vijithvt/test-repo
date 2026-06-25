#include <stdio.h>
#include "math_utils.h"
#include "logger.h"

static double average(int a, int b)
{
    return (a + b) / 2.0;
}

void analyze_data(int x, int y)
{
    int total = add(x, y);
    int score = calculate_score(total);
    double avg = average(x, y);

    printf("Average: %.2f\n", avg);
    printf("Score: %d\n", score);

    logger_log("Analysis completed");
}

int find_max(int a, int b)
{
    if (a > b)
        return a;

    return b;
}