#include <stdio.h>

void print_separator(void)
{
    puts("------------------------");
}

void print_status(void)
{
    puts("System status: ready.");
}

int main(void)
{
    print_separator();
    print_status();
    print_separator();
    return 0;
}

