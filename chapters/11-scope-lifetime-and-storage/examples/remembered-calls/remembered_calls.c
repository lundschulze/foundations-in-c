#include <stdio.h>

void report_call(void)
{
    static int calls = 0;

    calls++;
    printf("Call %d\n", calls);
}

int main(void)
{
    report_call();
    report_call();
    report_call();
    return 0;
}

