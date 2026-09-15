#include "database.h"
#include "traveller.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

static int write_text(const char *path, const char *text)
{
    FILE *output = fopen(path, "w");
    if (output == NULL)
    {
        return 0;
    }
    int ok = fputs(text, output) != EOF;
    if (fclose(output) == EOF)
    {
        ok = 0;
    }
    return ok;
}

int main(void)
{
    Traveller traveller;
    assert(traveller_create(&traveller, "Maya Chen", 2));
    assert(!traveller_create(&traveller, "", 2));
    assert(!traveller_create(&traveller, "Maya|Dent", 2));
    assert(!traveller_create(&traveller, "Maya\nDent", 2));
    assert(!traveller_create(&traveller, "Maya Chen", -1));
    assert(!traveller_create(&traveller, "Maya Chen", 21));

    Database database = {.records = NULL, .count = 0, .capacity = 0};
    assert(database_create(&database, 2));
    assert(database_add(&database, "Maya Chen", 2));
    assert(database_add(&database, "Leo Martins", 1));
    assert(!database_add(&database, "Priya Shah", 3));

    const char *valid_path = "test-valid.txt";
    assert(database_save(&database, valid_path));
    Database loaded = {.records = NULL, .count = 0, .capacity = 0};
    assert(database_create(&loaded, 2));
    assert(database_load(&loaded, valid_path));
    assert(loaded.count == 2);
    assert(strcmp(loaded.records[0].name, "Maya Chen") == 0);
    assert(loaded.records[1].bags == 1);

    const char *bad_path = "test-malformed.txt";
    assert(write_text(bad_path, "Maya Chen|2x\n"));
    assert(!database_load(&loaded, bad_path));
    assert(loaded.count == 2);
    assert(strcmp(loaded.records[0].name, "Maya Chen") == 0);

    database_destroy(&loaded);
    database_destroy(&database);
    assert(remove(valid_path) == 0);
    assert(remove(bad_path) == 0);
    return 0;
}
