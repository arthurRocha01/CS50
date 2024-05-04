#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    bool isTwoArguments = argc != 2;
    if (isTwoArguments)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Key must be a positive intereger.\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);
    if (key <= 0)
    {
        printf("Key must be a positive integer.\n");
        return 1;
    }
    string plaintext = get_string("plaintext: ");
    string ciphertext = "";
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char letter = plaintext[i];
        char base = isupper(letter) ? 'A' : 'a';
        int ascii = plaintext[i];

        int cifra = (ascii + key - base) % 26 + base;
        if (isalpha(letter))
        {
            printf("%c", cifra);
        }
        else
        {
            printf("%c", letter);
        }
    }
    printf("\n");
    return 0;
}
