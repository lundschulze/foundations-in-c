#include "traveller.h"

#include <string.h>

int traveller_create(Traveller *destination, const char *name, int bags)
{
    if (destination == NULL || name == NULL ||
        name[0] == '\0' || bags < 0 || bags > 20)
    {
        return 0;
    }
    size_t length = strlen(name);
    if (length >= TRAVELLER_NAME_CAPACITY ||
        strchr(name, '|') != NULL ||
        strchr(name, '\n') != NULL ||
        strchr(name, '\r') != NULL)
    {
        return 0;
    }
    memcpy(destination->name, name, length + 1);
    destination->bags = bags;
    return 1;
}
