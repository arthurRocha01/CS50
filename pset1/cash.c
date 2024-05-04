#include <cs50.h>
#include <math.h>
#include <stdio.h>

int minimunCurrency(float);

int main(void)
{
    float input;
    do
    {
        input = get_float("change: ");
    }
    while (input < 0);

    int coins = minimunCurrency(input);
    printf("%i\n", coins);
}

int minimunCurrency(float value)
{
    int cents = round(value * 100);

        int maximunCoins = 0;
        int amountCoin = 0;

        while (cents > 0)
        {
            if (cents >= 25)
            {
                maximunCoins = cents / 25;
                cents -= maximunCoins * 25;
                amountCoin += maximunCoins;
            }
            else if (cents >= 10)
            {
                maximunCoins = cents / 10;
                cents -= maximunCoins * 10;
                amountCoin += maximunCoins;
            }
            else if (cents >= 5)
            {
                maximunCoins = cents / 5;
                cents -= maximunCoins * 5;
                amountCoin += maximunCoins;
            }
            else if (cents >= 1)
            {
                maximunCoins = cents / 1;
                cents -= maximunCoins * 1;
                amountCoin += maximunCoins;
            }
        }
        return amountCoin;
}
