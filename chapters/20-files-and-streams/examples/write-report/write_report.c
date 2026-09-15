#include <stdio.h>

int main(void)
{
    FILE *report = fopen("journey.txt", "w");
    if (report == NULL)
    {
        perror("journey.txt");
        return 1;
    }
    if (fprintf(report, "Destination: Aurora Station\n") < 0 ||
        fprintf(report, "Passengers: %d\n", 3) < 0)
    {
        fputs("Could not write journey.txt.\n", stderr);
        fclose(report);
        return 1;
    }
    if (fclose(report) == EOF)
    {
        fputs("Could not finish writing journey.txt.\n", stderr);
        return 1;
    }
    puts("Wrote journey.txt");
    return 0;
}
