// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>
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
const unsigned int N = 10000;

// Represents a hash table
node *table[N];
int words;

// Returns true if word is in dictionary, else false. Finding a word in a dictionary (case-insensitively)
bool check(const char *word)
{
    unsigned int h = hash(word);
    //creating traversal node-pointer cursor pointing at the list's head
    node *cursor = table[h];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
//Sourse: by SocratesSatisfied (https://www.reddit.com/r/cs50/comments/eo4zro/good_hash_function_for_speller/fn7grov/) 
//Original Source: djib2 by Dan Bernstein (http://www.cse.yorku.ca/~oz/hash.html)
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c = *word;
    c = tolower(c);
    while (*word != 0)
    {
        hash = ((hash << 5) + hash) + c;
        c = *word++;
        c = tolower(c);
    }   
    return hash % N;
}

// Loads dictionary, returning true if successful, else false (while reading dictionary, writes words into hashtable)
bool load(const char *dictionary)
{
    //opening dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    //setting tablepointers to null
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    
    char word[LENGTH + 1];
    words = 0;
  
    //reading strings one at a time
    while (fscanf(file, "%s\n", word) != EOF)
    {
        //creating a new node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        //assigning node's value (copying a word from a dictionary)
        strcpy(n->word, word);
        
        //hashing word to obtain a hash value
        unsigned int h = hash(word);
        
        //checking if it's the first node in a linked list
        if (table[h] == NULL)
        {
            //assigning head pointer to a new node and its next pointer
            n->next = NULL;
            table[h] = n;
        }
        //if there is a linked list already, inserting a new node to the beginning of a linked list
        else
        {
            n->next = table[h];
            table[h] = n;    
        }
        //counting number of words added
        words ++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary 
unsigned int size(void)
{
    return words;
}

// Unloads dictionary from memory, returning true if successful, else false (free memory)
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        //variable cursor pointing at the first element of linked list
        node *cursor = table[i];
    
        // handling base case
        while (cursor != NULL)
        {
            //variable tmp pointing at the same location
            node *tmp = cursor;
            //freeing tmp node only after moving cursor to the next node
            cursor = cursor->next;
            free(tmp);
        }
        table[i] = NULL;
    }
    
    return true;
}
