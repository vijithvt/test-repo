#include "math_utils.h"

static int square(int value)
{
    return value * value;
}

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    int result = 0;

    for (int i = 0; i < b; i++)
    {
        result = add(result, a);
    }

    return result;
}

int calculate_score(int value)
{
    return square(value) + multiply(value, 2);
}