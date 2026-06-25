#include <stdio.h>
#include "math_utils.h"
#include "string_utils.h"
#include "logger.h"

int main(void)
{
    logger_init();

    int a = add(10, 20);
    int b = multiply(a, 2);

    print_message("Application Started");
    print_number(b);

    logger_log("Execution completed");

    return 0;
}