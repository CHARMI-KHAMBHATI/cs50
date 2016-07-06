/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */
 
 #include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "dictionary.h"


// define hashtable size
#define SIZE 1000000

// create nodes for linked list
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

// create hashtable
node* hashtable[SIZE] = {NULL};

// create hash function
int hash(const char* word)
{
    int hash = 0;
    int n;
    for (int i = 0; word[i] != '\0'; i++)
    {
        // alphabet case
        if (isalpha(word[i]))
        {
            n = word [i] - 'a' + 1;
        }

        // comma case
        else
        {
            n = 27;
        }

        hash = ((hash << 3) + n) % SIZE;
    }
    return hash;
}

// create global variable to count size
int dictionarySize = 0;

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // open dictionary
    FILE* file = fopen(dictionary, "r");
    // check for error
    if (file == NULL)
    {
        printf("Dictionary could not load.");
        return false;
    }

    // create an array for word to be stored in
    char word[LENGTH + 1];

    // scan through the file, loading each word into the hash table
    while (fscanf(file, "%s\n", word) != EOF)
    {
        // increase dictionary size
        dictionarySize++;

        // allocate memory for new word
        node* new_node = malloc(sizeof(node));

        // put word in the new node
        strcpy(new_node->word, word);

        // find what index of the array the word should go in
        int index = hash(word);

        // if hashtable is empty at index, insert
        if (hashtable[index] == NULL)
        {
            hashtable[index] = new_node;
            new_node->next = NULL;
        }

        // if hashtable is not empty at index, append
        else
        {
            new_node->next = hashtable[index];
            hashtable[index] = new_node;
        }
    }

    // close file
    fclose(file);

    // return true if successful
    return true;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    // creates a temp variable that stores a lower-cased version of the word
    char temp[LENGTH + 1];
    int len = strlen(word);
    for (int i = 0; i < len; i++)
    {
        temp[i] = tolower(word[i]);
    }
    temp[len] = '\0';

    // find what index of the array the word should be in
    int index = hash(temp);

    // if hashtable is empty at index, return false
    if (hashtable[index] == NULL)
    {
        return false;
    }

    // create cursor to compare to word
    node* cursor = hashtable[index];

    // if hashtable is not empty at index, iterate through words and compare
    while (cursor != NULL)
    {
        if (strcmp(temp, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    // if you don't find the word, return false
    return false;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // if dictionary is loaded, return number of words
    if (dictionarySize > 0)
    {
        return dictionarySize;
    }

    // if dictionary hasn't been loaded, return 0
    else
    {
        return 0;
    }
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // create a variable to go through index
    int index = 0;

    // iterate through entire hashtable array
    while (index < SIZE)
    {
        // if hashtable is empty at index, go to next index
        if (hashtable[index] == NULL)
        {
            index++;
        }

        // if hashtable is not empty, iterate through nodes and start freeing
        else
        {
            while (hashtable[index] != NULL)
            {
                node* cursor = hashtable[index];
                hashtable[index] = cursor->next;
                free(cursor);
            }

            // once hashtable is empty at index, go to next index
            index++;
        }
    }

    // return true if successful
    return true;
}
