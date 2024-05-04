#include <cs50.h>
#include <math.h>
#include <stdio.h>

int lunhCheckCard();
int countDigitCard();
int selectCardDigit();

int main(void)
{
    long input;
    do
    {
        input = get_long("card: ");
    }
    while (countDigitCard(input) <= 10);
        return lunhCheckCard(input);
}

int countDigitCard(long number) // retorna a quantidade de digítos do cartão
{
    int count = 1;
    while (number > 0)
    {
        number /= 10;
        count++;
    }
    return count;
}

int selectCardDigit(long card, int index) // retorna os dois primeiros digítos do cartão
{
    int size = countDigitCard(card) - index;

    int count = 1;
    while (count < size)
    {
        card /= 10;
        count++;
    }
    return card;
}

int lunhCheckCard(long card) // algoritimo de validação de cartaoes de credito
{
    int oddPosition = 1;
    int evenPosition = 10;
    int sumPair = 0;
    int sumOdd = 0;

    long control = card;
    while (control > 0)
    {
        // multiplica todos os digítos pares e a soma deles
        int pair = (control / evenPosition) % 10;
        pair *= 2;
        if (pair > 9)
        {
            pair -= 9;
        }
        sumPair += pair;

        // soma todos os digítos ímpares
        int odd = (control / oddPosition) % 10;
        sumOdd += odd;

        // lógica
        evenPosition *= 10;
        oddPosition *= 10;
        control /= 10;
    }

    // informações do cartão
    int sumTotal = sumPair + sumOdd;
    int sizeCard = countDigitCard(card);
    int firstDigit = selectCardDigit(card, 1);
    int firstTwoDigits = selectCardDigit(card, 2);

    // verifica se o cartão é valído
    bool VALID = sumTotal % 10 == 0 && sizeCard >= 13;
    if (VALID)
    {
        // verifica as bandeiras dos cartões
        bool isAMEX = firstTwoDigits == 34 || firstTwoDigits == 37;
        bool isMASTERCARD = firstTwoDigits >= 50 && firstTwoDigits <= 55;
        bool isVISA = firstDigit == 4;
        if (isAMEX && VALID)
        {
            printf("AMEX\n");
        }
        else if (isMASTERCARD && VALID)
        {
            printf("MASTERCARD\n");
        }
        else if (isVISA && VALID)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}
