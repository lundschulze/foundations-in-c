#include "temperature_log.h"

#include <stdint.h>
#include <stdlib.h>

struct TemperatureLog
{
    double *values;
    size_t count;
    size_t capacity;
};

TemperatureLog *temperature_log_create(size_t capacity)
{
    if (capacity == 0 || capacity > SIZE_MAX / sizeof(double))
    {
        return NULL;
    }
    TemperatureLog *log = malloc(sizeof *log);
    if (log == NULL)
    {
        return NULL;
    }
    log->values = malloc(capacity * sizeof *log->values);
    if (log->values == NULL)
    {
        free(log);
        return NULL;
    }
    log->count = 0;
    log->capacity = capacity;
    return log;
}

int temperature_log_add(TemperatureLog *log, double value)
{
    if (log == NULL || log->count == log->capacity)
    {
        return 0;
    }
    log->values[log->count] = value;
    log->count++;
    return 1;
}

int temperature_log_average(const TemperatureLog *log, double *result)
{
    if (log == NULL || result == NULL || log->count == 0)
    {
        return 0;
    }
    double total = 0.0;
    for (size_t index = 0; index < log->count; index++)
    {
        total += log->values[index];
    }
    *result = total / (double)log->count;
    return 1;
}

void temperature_log_destroy(TemperatureLog *log)
{
    if (log != NULL)
    {
        free(log->values);
        free(log);
    }
}
