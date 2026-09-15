#include "temperature_log.h"

#include <assert.h>

int main(void)
{
    assert(temperature_log_create(0) == NULL);

    TemperatureLog *log = temperature_log_create(2);
    assert(log != NULL);

    double average = 0.0;
    assert(!temperature_log_average(log, &average));
    assert(temperature_log_add(log, 10.0));
    assert(temperature_log_add(log, 20.0));
    assert(!temperature_log_add(log, 30.0));
    assert(temperature_log_average(log, &average));
    assert(average == 15.0);

    assert(!temperature_log_add(NULL, 10.0));
    assert(!temperature_log_average(NULL, &average));
    assert(!temperature_log_average(log, NULL));

    temperature_log_destroy(log);
    temperature_log_destroy(NULL);
    return 0;
}
