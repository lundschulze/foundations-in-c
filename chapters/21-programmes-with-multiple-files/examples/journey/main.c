#include "journey.h"

int main(void)
{
    Journey journey = {.destination = "Aurora Station", .passengers = 3};

    journey_print(&journey);
    return journey_is_ready(&journey) ? 0 : 1;
}
