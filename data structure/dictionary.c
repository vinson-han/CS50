
// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"


unsigned int globalCounter = 0;
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1000;
// Number
// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{   
    
    
    char * wordt = malloc(sizeof(word));
    strcpy(wordt,word);
    for(int i = 0; wordt[i];i++)
        wordt[i] = tolower(wordt[i]);

    unsigned int x = hash(wordt);
    //printf("%s\n", table[hash(temp)]->word);
    for(node *temp = table[x];;temp = temp->next)
    {
        if((strcmp(temp->word,wordt) == 0))
        {
            free(wordt);
            return true;
        }
        else
        {
            if(temp->next == NULL)
            {
                free(wordt);
                return false;
            }
        }
    }
    free(wordt);
    return false;
}

// Hashes word to a number
//http://www.cse.yorku.ca/~oz/hash.html
//Source of hash function
unsigned int hash(const char *word)
{
    // TODO
    unsigned int hashcode = 1000;
    unsigned long c;
    while((c = *word++))
    {
        hashcode = ((hashcode << 5) + hashcode) + c; /* hash * 33 + c */
    }
    return hashcode % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{   
    const char *string = dictionary;
    FILE * file = fopen(dictionary, "r");

    if(file == NULL)
    {
        return false;
    }
    char word[LENGTH+1];
    int count =0;
   
    while(fscanf(file,"%s",word) != EOF)
    {   
        globalCounter++;       
        node *n = malloc(sizeof(node));
        
        if(n == NULL)
        {   
            printf("Memorry Error\n");
            fclose(file);
            return false;
        }
        strcpy(n->word,word);
        int x = hash(word);
        if(table[x] == NULL)
            table[x] = n;
        else
        {
            n->next = table[x];
            table[x] = n;
        }
       
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return globalCounter+1;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    

    for(int i = 0; i < N; i++){
        if(table[i] != NULL)
        {    
            for(node *current = table[i];;current = current->next)
            {
                free(current);
                if(current->next == NULL)
                    break;  
            }
        }
    }
    return true;
}
