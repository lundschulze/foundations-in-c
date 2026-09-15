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

int main(void)
{
    /* TODO: create at least three records and print every member. */
    return 0;
}
