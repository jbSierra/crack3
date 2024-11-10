#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileutil.h"

// DIRECTIONS
// Choose whether you are doing the 2D array or
// the array of arrays.
// For the 2D array,
//    implement loadFile2D, substringSearch2D, and free2D.
// For the array of arrays, 
//    implement loadFileAA, substringSearchAA, and freeAA.
const int CAPACITY_START = 20;
const int CAP_INCREMENT = 10;

// Load the text file from the given filename.
// Return a pointer to the array of strings.
// Sets the value of size to be the number of valid
// entries in the array (not the total array length).
char ** loadFileAA(char *filename, int *size)
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// TODO
	// Allocate memory for an array of strings (arr).
	// Read the file line by line.
    //   Trim newline.
	//   Expand array if necessary (realloc).
	//   Allocate memory for the string (str).
	//   Copy each line into the string (use strcpy).
	//   Attach the string to the large array (assignment =).
    // Close the file.
	
	// The size should be the number of entries in the array.
	*size = 0;
	
	// Return pointer to the array of strings.
	return NULL;
}

char (*loadFile2D(char *filename, int *size))[COLS]
{
	FILE *in = fopen(filename, "r");
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// TODO
	// Allocate memory for an 2D array, using COLS as the width.

	int capacity = CAPACITY_START;
	*size = 0;
	char (*array)[COLS] = malloc(capacity * sizeof(char[COLS]));
	// buffer
	char buffer[1000];
	// Read the file line by line into a buffer.
	while (fgets(buffer, sizeof(buffer), in)) 
	{
    	//   Trim newline.
		char *nl = strchr(buffer, '\n');
        	if (nl) 
			{
            	*nl = '\0';
        	}
		// check for full array
		if (*size == capacity) 
		{
			// extend array
        	capacity += CAP_INCREMENT; 
            array = realloc(array, capacity * sizeof(char[COLS])); 
		}
	//   Copy each line from the buffer into the array (use strcpy).
	strcpy(array[*size], buffer);
	(*size)++;
	}
    // Close the file.
	fclose(in);
	// The size should be the number of entries in the array.
	// Return pointer to the array.
	return array;
}

// Search the array for the target string.
// Return the found string or NULL if not found.
char * substringSearchAA(char *target, char **lines, int size)
{

	return NULL;
}

char * substringSearch2D(char *target, char (*lines)[COLS], int size)
{
     for (int i = 0; i < size; i++) 
	 {
        // Use strstr 
        if (strstr(lines[i], target) != NULL) 
		{
            // return line if found
            return lines[i]; 
        }
    }
    return NULL;
}

// exact string search
char * exactstringSearch2D(char *target, char (*lines)[33], int size)
{
     for (int i = 0; i < size; i++) 
	 {
        // Use strcmp 
        if (strcmp(lines[i], target) == 0) 
		{
            // return line if found
            return lines[i]; 
        }
    }
    return NULL;
}


// Free the memory used by the array
void freeAA(char ** arr, int size)
{

}

void free2D(char (*arr)[COLS])
{
	free(arr);
}