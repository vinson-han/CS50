//Incomplete

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
void mergeSort(pair* p,int left, int right);
void merge(pair * p, int left, int mid, int right);
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
   for (int i = 0; i < candidate_count; i++)
   {
       if(strcmp(candidates[i],name) == 0)
       {
           ranks[rank] = i;
           for (int j = 0; j < rank; j++)
           {  
              if (strcmp(candidates[ranks[j]], name) == 0)
                return false;      
           }
           return true;
       }
   }   
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{   
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i; j < candidate_count; j++)
        {   
            if(i != j)
            {
                //printf("[%i][%i]\n",i,j);
                //printf("rank[i]:%i rank[j]%i\n",ranks[i],ranks[j]);
                preferences[ranks[i]][ranks[j]]++;
            }
            //preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
               if(preferences[i][j] != preferences[j][i] && preferences[i][j] != 0)
               {
                    if(preferences[i][j] > preferences[j][i])
                    {
                        pairs[pair_count].winner = i;
                        pairs[pair_count].loser = j;
                        pair_count++;
                    }
                    else
                    {
                        pairs[pair_count].winner = j;
                        pairs[pair_count].loser = i;
                        pair_count++;
                    }
                        //printf("[%i],[%i]:%i\n",i,j,preferences[i][j]);

               }
        
           
        }
    }
    return;
}


// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    mergeSort(pairs,0,pair_count);

}
void mergeSort(pair* p, int left, int right)
{
    if (left < right)
    {
        //Avoid Over Flow for Larger number
        int m = left+ (right - 1) / 2;
        //Sort first asnd second halves
        mergeSort(p, left, m);
        mergeSort(p, m+1, right);
        
        merge(p, left, m, right);

    }

}
void merge(pair * p, int left, int mid, int right)
{
    int i,j,k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    pair tempL[n1];
    pair tempR[n2];

    for (int i = 0; i < n1; i++)
        tempL[i] = p[left + i];
    for (int j = 0; j < n2; j++)
        tempR[j] = p[mid + 1 + j];
    
    i = 0;
    j = 0;
    k = left;

     while (i < n1 && j < n2) 
    { 
        if (preferences[tempL[i].winner][tempR[i].loser] <= preferences[tempL[i].winner][tempR[i].loser]) 
        { 
            p[k] = tempL[i]; 
            i++; 
        } 
        else
        { 
            p[k] = tenpR[j]; 
            j++; 
        } 
        k++; 
    }
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 


    
}


// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}
