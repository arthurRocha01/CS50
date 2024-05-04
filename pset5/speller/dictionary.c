// Implements a dictionary's functionality

#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;
#define S  26
// Hash table
node *table[S];

unsigned int hash_value;
unsigned int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    hash_value = hash(word);
    node *cursor = table[hash_value];

    for (int i = 0; i < strlen(word); i++)
    {
        word[i] = tolower(word[i]);
    }

    while (cursor != NULL)
    {
        if (strcmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned long total = 0;

    for (int i = 0; i < N; i++)
    {
        total = (total * 31) + tolower(*word);
        word++;
    }

    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        node *cursor = malloc(sizeof(node));
        if (cursor == NULL)
        {
            return false;
        }

        strcpy(cursor->word, word);
        hash_value = hash(word);
        cursor->next = table[hash_value];
        table[hash_value] = cursor;
        word_count++;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (word_count > 0)
    {
        return word_count;
    }

    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (unsigned int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }

    return true;
}
