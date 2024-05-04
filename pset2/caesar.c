#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {

        int key = atoi(argv[1]);
        if (key >= 0)
        {
            for (int i = 0, n = strlen(argv[1]); i < n; i++)
            {
                if (!isdigit(argv[1][i]))
                {
                    printf("Key must be a positive intereger.\n");
                    return 1;
                }
            }

            string plaintext = get_string("plaintext: ");
            printf("ciphertext: ");
            for (int i = 0, n = strlen(plaintext); i < n; i++)
            {
                char letter = plaintext[i];
                char base = isupper(letter) ? 'A' : 'a';
                int valueAscci = plaintext[i];

                int cifra = (valueAscci + key - base) % 26 + base;
                isalpha(letter) ? printf("%c", cifra) : printf("%c", letter);
            }
            printf("\n");
            return 0;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
