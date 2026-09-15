#include "database.h"

#include <stdio.h>

int main(void)
{
    const char *path = "travellers-practice.txt";
    Database original = {.records = NULL, .count = 0, .capacity = 0};
    Database loaded = {.records = NULL, .count = 0, .capacity = 0};
    int status = 1;

    if (!database_create(&original, 3) ||
        !database_create(&loaded, 3))
    {
        fputs("Could not create the databases.\n", stderr);
        goto cleanup;
    }
    if (!database_add(&original, "Maya Chen", 2) ||
        !database_add(&original, "Leo Martins", 1) ||
        !database_add(&original, "Priya Shah", 3))
    {
        fputs("Could not add the travellers.\n", stderr);
        goto cleanup;
    }
    if (!database_save(&original, path))
    {
        fputs("Could not save the records.\n", stderr);
        goto cleanup;
    }
    if (!database_load(&loaded, path))
    {
        fputs("Could not load the records.\n", stderr);
        goto cleanup;
    }

    database_print(&loaded);
    if (loaded.count != 3)
    {
        fputs("The round trip changed the record count.\n", stderr);
        goto cleanup;
    }
    puts("Database round trip verified.");
    status = 0;

cleanup:
    database_destroy(&loaded);
    database_destroy(&original);
    if (remove(path) != 0 && status == 0)
    {
        perror(path);
        status = 1;
    }
    return status;
}
