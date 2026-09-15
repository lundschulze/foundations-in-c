#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char text[80];

    printf("Enter text: ");
    fflush(stdout);

    if (fgets(text, sizeof text, stdin) == NULL)
    {
        puts("No text was read.");
        return 1;
    }

    size_t newline = strcspn(text, "\n");
    bool had_newline = text[newline] == '\n';
    text[newline] = '\0';
    size_t length = strlen(text);

    printf("Text: %s\n", text);
    printf("Length: %zu\n", length);

    if (length > 0)
    {
        printf("First character: %c\n", text[0]);
    }
    else
    {
        puts("First character: (none)");
    }

    if (had_newline)
    {
        puts("The newline fitted in the array.");
    }
    else
    {
        puts("The newline did not fit in the array.");
    }

    return 0;
}

