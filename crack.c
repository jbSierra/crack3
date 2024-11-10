#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"

#if __has_include("fileutil.h")
#include "fileutil.h"
#endif

#define PASS_LEN 50     // Maximum length any password will be.
#define HASH_LEN 33     // Length of hash plus one for null.


int main(int argc, char *argv[])
{
    if (argc < 3) 
    {
        printf("Usage: %s hash_file dictionary_file\n", argv[0]);
        exit(1);
    }

    // TODO: Read the hashes file into an array.
    //   Use either a 2D array or an array of arrays.
    //   Use the loadFile function from fileutil.c
    //   Uncomment the appropriate statement.
    char password[PASS_LEN];
    int numHashes = 0;
    int size;
    // 2D Array
    char (*hashes)[HASH_LEN] = loadFile2D(argv[1], &size);
    //char **hashes = loadFile(argv[1], &size);
    
    // CHALLENGE1: Sort the hashes using qsort.
    
    // TODO
    // Open the password file for reading.
    FILE *dictionary = fopen(argv[2], "r");

    // TODO
    // For each password, hash it, then use the array search
    while (fgets(password, sizeof(password), dictionary))
    {
        //Trim newline.
		char *nl = strchr(password, '\n');
        	if (nl) 
			{
            	*nl = '\0';
        	}
        // hash
        char *hashedPassword = md5(password, strlen(password));
    
        // function from fileutil.h to find the hash.
        char *exists = exactstringSearch2D(hashedPassword, hashes, size);
        // If you find it, display the password and the hash.
        if (exists != NULL)
        {
        printf("Password: %s\nHash: %s\n", password, exists);
        // Keep track of how many hashes were found.
        numHashes++;
        }
    }
    // CHALLENGE1: Use binary search instead of linear search.

    // TODO
    // When done with the file:
    //   Close the file
    fclose(dictionary);
    //   Display the number of hashes found.
    printf("%d hashes found\n", numHashes);
    //   Free up memory.
    free2D(hashes);
}
