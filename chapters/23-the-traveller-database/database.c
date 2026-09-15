#include "database.h"

#include <errno.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int database_create(Database *database, size_t capacity)
{
    if (database == NULL || capacity == 0 ||
        capacity > SIZE_MAX / sizeof(Traveller))
    {
        return 0;
    }
    Traveller *records = malloc(capacity * sizeof *records);
    if (records == NULL)
    {
        return 0;
    }
    database->records = records;
    database->count = 0;
    database->capacity = capacity;
    return 1;
}

void database_destroy(Database *database)
{
    if (database != NULL)
    {
        free(database->records);
        database->records = NULL;
        database->count = 0;
        database->capacity = 0;
    }
}

int database_add(Database *database, const char *name, int bags)
{
    if (database == NULL || database->records == NULL ||
        database->count >= database->capacity)
    {
        return 0;
    }
    Traveller record;
    if (!traveller_create(&record, name, bags))
    {
        return 0;
    }
    database->records[database->count] = record;
    database->count++;
    return 1;
}

void database_print(const Database *database)
{
    if (database == NULL)
    {
        return;
    }
    for (size_t index = 0; index < database->count; index++)
    {
        printf("%zu: %s, %d bag%s\n",
               index + 1,
               database->records[index].name,
               database->records[index].bags,
               database->records[index].bags == 1 ? "" : "s");
    }
}

int database_save(const Database *database, const char *path)
{
    if (database == NULL || path == NULL)
    {
        return 0;
    }
    FILE *output = fopen(path, "w");
    if (output == NULL)
    {
        return 0;
    }
    int ok = 1;
    for (size_t index = 0; index < database->count; index++)
    {
        if (fprintf(output, "%s|%d\n",
                    database->records[index].name,
                    database->records[index].bags) < 0)
        {
            ok = 0;
            break;
        }
    }
    if (fclose(output) == EOF)
    {
        ok = 0;
    }
    return ok;
}

static int parse_record(char *line, char **name, int *bags)
{
    char *separator = strchr(line, '|');
    if (separator == NULL || separator == line ||
        strchr(separator + 1, '|') != NULL)
    {
        return 0;
    }
    *separator = '\0';
    char *number = separator + 1;
    char *end = NULL;
    errno = 0;
    long parsed = strtol(number, &end, 10);
    if (end == number || *end != '\0' || errno == ERANGE ||
        parsed < 0 || parsed > 20 || parsed > INT_MAX)
    {
        return 0;
    }
    *name = line;
    *bags = (int)parsed;
    return 1;
}

int database_load(Database *database, const char *path)
{
    if (database == NULL || path == NULL || database->capacity == 0)
    {
        return 0;
    }
    Database temporary = {.records = NULL, .count = 0, .capacity = 0};
    if (!database_create(&temporary, database->capacity))
    {
        return 0;
    }
    FILE *input = fopen(path, "r");
    if (input == NULL)
    {
        database_destroy(&temporary);
        return 0;
    }

    int ok = 1;
    char line[100];
    while (fgets(line, sizeof line, input) != NULL)
    {
        char *newline = strchr(line, '\n');
        if (newline == NULL)
        {
            ok = 0;
            break;
        }
        *newline = '\0';
        if (newline > line && newline[-1] == '\r')
        {
            newline[-1] = '\0';
        }
        char *name = NULL;
        int bags = 0;
        if (!parse_record(line, &name, &bags) ||
            !database_add(&temporary, name, bags))
        {
            ok = 0;
            break;
        }
    }
    if (ferror(input))
    {
        ok = 0;
    }
    if (fclose(input) == EOF)
    {
        ok = 0;
    }
    if (!ok)
    {
        database_destroy(&temporary);
        return 0;
    }

    database_destroy(database);
    *database = temporary;
    return 1;
}
