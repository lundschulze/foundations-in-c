#include <stdio.h>

int main(void)
{
    int travellers = 5;
    int meals_per_traveller = 3;
    int spare_meals = 2;
    int total_meals = travellers * meals_per_traveller + spare_meals;

    printf("Meals required: %i\n", total_meals);
    return 0;
}
