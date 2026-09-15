#ifndef TEMPERATURE_LOG_H
#define TEMPERATURE_LOG_H

#include <stddef.h>

typedef struct TemperatureLog TemperatureLog;

TemperatureLog *temperature_log_create(size_t capacity);
int temperature_log_add(TemperatureLog *log, double value);
int temperature_log_average(const TemperatureLog *log, double *result);
void temperature_log_destroy(TemperatureLog *log);

#endif
