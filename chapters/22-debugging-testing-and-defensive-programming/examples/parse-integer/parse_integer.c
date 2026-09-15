#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char line[100];
    if (fgets(line, sizeof line, stdin) == NULL)
    {
        fputs("No input was available.\n", stderr);
        return 1;
    }
    if (strchr(line, '\n') == NULL && !feof(stdin))
    {
        fputs("The input line is too long.\n", stderr);
        return 1;
    }
    char *end = NULL;
    errno = 0;
    long value = strtol(line, &end, 10);
    if (end == line)
    {
        fputs("No integer was found.\n", stderr);
        return 1;
    }
    while (isspace((unsigned char)*end))
    {
        end++;
    }
    if (*end != '\0' || errno == ERANGE ||
        value < INT_MIN || value > INT_MAX)
    {
        fputs("The value is not a valid int.\n", stderr);
        return 1;
    }
    printf("Value: %d\n", (int)value);
    return 0;
}
