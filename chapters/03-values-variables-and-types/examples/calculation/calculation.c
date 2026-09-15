#include <stdio.h>

int main(void)
{
    int passengers = 6;
    int bags_per_passenger = 2;
    int spare_bags = 3;
    int total_bags = passengers * bags_per_passenger + spare_bags;

    printf("Total bags: %i\n", total_bags);
    return 0;
}
