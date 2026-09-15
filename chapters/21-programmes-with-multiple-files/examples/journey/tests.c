#include "journey.h"

#include <assert.h>
#include <stddef.h>

int main(void)
{
    Journey ready = {.destination = "Aurora Station", .passengers = 3};
    Journey no_destination = {.destination = NULL, .passengers = 3};
    Journey no_passengers = {.destination = "Earth", .passengers = 0};

    assert(journey_is_ready(&ready));
    assert(!journey_is_ready(&no_destination));
    assert(!journey_is_ready(&no_passengers));
    assert(!journey_is_ready(NULL));
    return 0;
}
