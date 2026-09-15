#include "journey.h"

#include <stdio.h>

static int passenger_count_is_valid(int passengers)
{
    return passengers > 0;
}

int journey_is_ready(const Journey *journey)
{
    return journey != NULL &&
           journey->destination != NULL &&
           passenger_count_is_valid(journey->passengers);
}

void journey_print(const Journey *journey)
{
    if (!journey_is_ready(journey))
    {
        return;
    }
    printf("Destination: %s\n", journey->destination);
    printf("Passengers: %d\n", journey->passengers);
}
