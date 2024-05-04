#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int computer_score(string word);

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int score1 = computer_score(word1);
    int score2 = computer_score(word2);

    if (score1 == score2 || score2 == score1)
    {
        printf("Tier!");
    }
    printf("Player %c wins!", score1 > score2 ? '1' : '2');

    printf("\n");
}

int computer_score(string word)
{
    int sum = 0;
    int s = strlen(word);
    for (int i = 0; i < s; i++)
    {
        char base = isupper(word[i]) ? 'A' : 'a';
        char letter = word[i];

        int index = word[i] - base;
        if (isalpha(letter))
        {
        sum += POINTS[index];
        }
        sum += 0;
    }
    return sum;
}
