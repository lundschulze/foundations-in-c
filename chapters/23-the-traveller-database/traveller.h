#ifndef MOSTLY_HARMLESS_TRAVELLER_H
#define MOSTLY_HARMLESS_TRAVELLER_H

#define TRAVELLER_NAME_CAPACITY 40

typedef struct
{
    char name[TRAVELLER_NAME_CAPACITY];
    int bags;
} Traveller;

int traveller_create(Traveller *destination, const char *name, int bags);

#endif
