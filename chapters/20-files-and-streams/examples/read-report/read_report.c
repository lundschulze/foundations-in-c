#include <stdio.h>

int main(void)
{
    FILE *report = fopen("journey.txt", "r");
    if (report == NULL)
    {
        perror("journey.txt");
        return 1;
    }
    char line[100];
    while (fgets(line, sizeof line, report) != NULL)
    {
        fputs(line, stdout);
    }
    int read_failed = ferror(report);
    if (fclose(report) == EOF)
    {
        perror("journey.txt");
        return 1;
    }
    if (read_failed)
    {
        fputs("Could not read the complete report.\n", stderr);
        return 1;
    }
    return 0;
}
