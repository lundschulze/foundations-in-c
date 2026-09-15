#include <stdio.h>

enum JourneyStatus
{
    STATUS_WAITING,
    STATUS_READY,
    STATUS_DEPARTED
};

typedef struct
{
    char name[40];
    enum JourneyStatus status;
} Journey;

static const char *status_text(enum JourneyStatus status)
{
    switch (status)
    {
        case STATUS_WAITING:
            return "Waiting for departure";
        case STATUS_READY:
            return "Ready to depart";
        case STATUS_DEPARTED:
            return "Already departed";
    }
    return "Unknown status";
}

int main(void)
{
    Journey journey = {.name = "Priya", .status = STATUS_READY};
    printf("%s: %s.\n", journey.name, status_text(journey.status));
    return 0;
}
