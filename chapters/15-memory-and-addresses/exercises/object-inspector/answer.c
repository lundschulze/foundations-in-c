#include <stdio.h>

int main(void)
{
    char letter = 'C';
    int answer = 42;
    double ratio = 1.5;

    printf("char: value=%c size=%zu address=%p\n",
           letter, sizeof letter, (void *)&letter);
    printf("int: value=%d size=%zu address=%p\n",
           answer, sizeof answer, (void *)&answer);
    printf("double: value=%.1f size=%zu address=%p\n",
           ratio, sizeof ratio, (void *)&ratio);
    return 0;
}
