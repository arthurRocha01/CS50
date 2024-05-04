#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string key = argv[1];
        if (strlen(key) != 26)
        {
            printf("A chave deve conter 26 caracteres.\n");
            return 1;
        }

        for (int i = 0, n = strlen(key); i < n; i++)
        {
            if (!isalpha(key[i]))
            {
                printf("Uso: ./ chave de substituição\n");
                return 1;
            }

            for (int j = i + 1, m = strlen(key); j < m; j++)
            {
                if (key[i] == key[j])
                {
                    printf("Uso: ./ chave de substituição\n");
                    return 1;
                }
            }
        }

        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");

        for (int i = 0, len = strlen(plaintext); i < len; i++)
        {
            char current_char = plaintext[i];

            if (isalpha(current_char))
            {
                char base = isupper(current_char) ? 'A' : 'a';
                int index = current_char - base;
                char cipher_char = key[index];

                printf("%c", isupper(current_char) ? toupper(cipher_char) : tolower(cipher_char));
            }
            else
            {
                printf("%c", current_char);
            }
        }

        printf("\n");
        return 0;
    }
    else
    {
        printf("Uso: ./ chave de substituição\n");
        return 1;
    }
}
