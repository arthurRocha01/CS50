#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            // printf("index: %i\n--------\n", i);
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        int first_preference = ranks[i];
        for (int j = i + 1; j < candidate_count; j++)
        {
            int less_preferred = ranks[j];
            // printf("%i\n", first_preference);
            preferences[first_preference][less_preferred]++;
            // printf("preferences[%i][%i]\n", first_preference, less_preferred);
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    int index = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            int preference_diff = preferences[i][j] - preferences[j][i];
            if (preference_diff > 0)
            {
                pairs[index].winner = i;
                pairs[index].loser = j;
                index++;
                pair_count++;
            }
        }
    }

    // for (int i = 0; i < pair_count; i++)
    // {
    //     printf("Pair: %s > %s\n", candidates[pairs[i].winner], candidates[pairs[i].loser]);
    // }
    return;
}

int pair_weight(i)
{
    int pair_winner = pairs[i].winner;
    int pair_loser = pairs[i].loser;
    return preferences[pair_winner][pair_loser];
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        for (int j = 0; j < pair_count; j++)
        {
            int votes1 = preferences[pairs[j].winner][pairs[j].loser];
            int votes2 = preferences[pairs[j+1].winner][pairs[j+1].loser];

            if (votes1 < votes2)
            {
                pair temp = pairs[j];
                pairs[j] = pairs[j+1];
                pairs[j+1] = temp;
            }
        }
    }
    return;

    // for (int i = 0; i < pair_count; i++)
    // {
    //     printf("Pair %i: %i > %i\n", i, pairs[i].winner, pairs[i].loser);
    // }
    // return;
}

// Lock pairs into the candidate graph in order, without creating cycles

bool has_cycle(int winner, int loser)
{
    if (winner == loser)
    {
        return true;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[loser][i])
        {
            if (has_cycle(winner, i))
            {
                return true;
            }
        }
    }
    return false;
}

void lock_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        int winner = pairs[i].winner;
        int loser = pairs[i].loser;
        if (!has_cycle(winner, loser))
        {
            locked[winner][loser] = true;
        }
    }

    // for (int i = 0; i < pair_count; i++)
    // {
    //     for (int j = 0; j < candidate_count; j++)
    //     {
    //         printf("%i  ", locked[i][j] == true ? 1 : 0);
    //     }
    //     printf("\n");
    // }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        bool is_winner = true;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == true)
            {
                is_winner = false;
                break;
            }
        }
        if (is_winner)
        {
            printf("%s\n", candidates[i]);
            return;
        }
    }
}

