#include "temperature_log.h"

#include <stdio.h>

int main(void)
{
    TemperatureLog *log = temperature_log_create(3);
    if (log == NULL)
    {
        fputs("Could not create temperature log.\n", stderr);
        return 1;
    }
    if (!temperature_log_add(log, 12.5) ||
        !temperature_log_add(log, 15.0) ||
        !temperature_log_add(log, 17.5))
    {
        fputs("Could not add temperature.\n", stderr);
        temperature_log_destroy(log);
        return 1;
    }
    double average = 0.0;
    if (!temperature_log_average(log, &average))
    {
        fputs("Could not calculate average.\n", stderr);
        temperature_log_destroy(log);
        return 1;
    }
    printf("Average: %.1f\n", average);
    temperature_log_destroy(log);
    return 0;
}
