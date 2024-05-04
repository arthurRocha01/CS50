#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int countLetters();
int countWords();
int countSentences();

int main(void)
{
    string text;
    do
    {
        text = get_string("Text: ");
    }
    while (text[0] == 0);
    int letters = countLetters(text);
    int words = countWords(text);
    int sentences = countSentences(text);

    // Avarage number of letter per hundred words
    float L = ((float) letters / words) * 100;
    // Avarage numbe of setences per hundred words
    float S = ((float) sentences / words) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    if (grade >= 16)
    {
    printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }


}

int countLetters(string text)
{
    int sum = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        bool isLetter = (text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z');
        if (isLetter)
        {
            sum++;
        }
    }
    return sum;
}

int countWords (string text)
{
    int sum = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        bool isWord = text[i] == ' ';
        if (isWord)
        {
            sum++;
        }
    }
    return sum += 1;
}

int countSentences(string text)
{
    int sum = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        bool isSentence = text[i] == '.' || text[i] == '!' || text[i] == '?';
        if (isSentence)
        {
            sum++;
        }
    }
    return sum;
}
