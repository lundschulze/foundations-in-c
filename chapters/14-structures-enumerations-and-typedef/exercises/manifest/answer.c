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
    int identifier;
    int bags;
    enum JourneyStatus status;
} Journey;

static const char *status_text(enum JourneyStatus status)
{
    switch (status)
    {
        case STATUS_WAITING:
            return "waiting";
        case STATUS_READY:
            return "ready";
        case STATUS_DEPARTED:
            return "departed";
    }
    return "unknown";
}

int main(void)
{
    Journey manifest[] = {
        {.name = "Maya", .identifier = 101, .bags = 2, .status = STATUS_WAITING},
        {.name = "Leo", .identifier = 102, .bags = 1, .status = STATUS_READY},
        {.name = "Priya", .identifier = 103, .bags = 3, .status = STATUS_DEPARTED}
    };
    size_t count = sizeof manifest / sizeof manifest[0];

    for (size_t index = 0; index < count; index++)
    {
        printf("%d: %s, %d bag(s), %s\n",
               manifest[index].identifier,
               manifest[index].name,
               manifest[index].bags,
               status_text(manifest[index].status));
    }
    return 0;
}
