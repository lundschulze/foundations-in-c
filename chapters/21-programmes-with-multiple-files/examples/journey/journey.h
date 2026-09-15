#ifndef JOURNEY_H
#define JOURNEY_H

typedef struct
{
    const char *destination;
    int passengers;
} Journey;

int journey_is_ready(const Journey *journey);
void journey_print(const Journey *journey);

#endif
