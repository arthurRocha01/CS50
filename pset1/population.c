#include <cs50.h>
#include <stdio.h>

int populationGrowth();

int main(void)
{
    int input;
    int secondInput;
    do
    {
        input = get_int("Start size: ");
    }
    while (input < 9);
    do
    {
        secondInput = get_int("End size: ");
    }
    while (secondInput < input);
    int year = populationGrowth(input, secondInput);
    printf("Years: %i\n", year);
}

int populationGrowth(initialPopulationQuantity, finalPopulationQuantity)
{
    int years = 0;
    int population = initialPopulationQuantity;

    while (population < finalPopulationQuantity)
    {
        // populaçao por ano
        population = population + (population / 3) - (population / 4);

        years++;
    }
    return years;
}
