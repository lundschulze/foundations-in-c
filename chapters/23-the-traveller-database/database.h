#ifndef MOSTLY_HARMLESS_DATABASE_H
#define MOSTLY_HARMLESS_DATABASE_H

#include "traveller.h"

#include <stddef.h>

typedef struct
{
    Traveller *records;
    size_t count;
    size_t capacity;
} Database;

int database_create(Database *database, size_t capacity);
void database_destroy(Database *database);
int database_add(Database *database, const char *name, int bags);
void database_print(const Database *database);
int database_save(const Database *database, const char *path);
int database_load(Database *database, const char *path);

#endif
