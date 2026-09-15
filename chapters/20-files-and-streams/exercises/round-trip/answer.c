#include <stdio.h>

int main(void)
{
    const char *path = "private-travel-log.txt";
    const char *records[] = {
        "Aurora Station|3\n",
        "Harbour Point|1\n",
        "Earth|2\n"
    };
    size_t count = sizeof records / sizeof records[0];
    FILE *output = fopen(path, "w");

    if (output == NULL)
    {
        perror(path);
        return 1;
    }
    for (size_t index = 0; index < count; index++)
    {
        if (fputs(records[index], output) == EOF)
        {
            fputs("Could not write the travel log.\n", stderr);
            fclose(output);
            return 1;
        }
    }
    if (fclose(output) == EOF)
    {
        fputs("Could not finish the travel log.\n", stderr);
        return 1;
    }

    FILE *input = fopen(path, "r");
    if (input == NULL)
    {
        perror(path);
        return 1;
    }
    char line[100];
    while (fgets(line, sizeof line, input) != NULL)
    {
        fputs(line, stdout);
    }
    int read_failed = ferror(input);
    int close_failed = fclose(input) == EOF;
    if (read_failed || close_failed)
    {
        fputs("Could not read the complete travel log.\n", stderr);
        return 1;
    }
    if (remove(path) != 0)
    {
        perror(path);
        return 1;
    }
    return 0;
}
