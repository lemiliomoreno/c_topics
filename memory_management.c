#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH (4)
#define MAX_LENGTH (200)

int main (void)
{
        /* Declaring a new pointer of type char */
        /* Allocating memory for 200 records of size of char, before they used: (char*)malloc(sizeof(char)), this is wrong
         * because it's redundant and you don't longer needed, also is more portable and no need maintenance, any type the
         * variable is, the allocated memory will be suficient
         */
        char *string  = malloc(MIN_LENGTH * sizeof *string);

        /* Always check if the allocation was succesfull */
        if (string == NULL)
        {
                fprintf(stderr, "Error allocating memory");
                exit(EXIT_FAILURE);
        }
        
        strcpy(string, "Hello");
        printf("String with malloc(%i): %s\n", MIN_LENGTH, string);

        /* Re-allocating memory of string */
        string = realloc(string, MAX_LENGTH * sizeof *string);
        
        /* Always check if allocation worked */
        if (string == NULL)
        {
                fprintf(stderr, "Error re-allocating memory");
                exit(EXIT_FAILURE);
        }
        
        strcpy(string, "Hello my name is Emilio and I came to write a very long string.");
        
        printf("String with re-alloc(%i): %s\n", MAX_LENGTH, string);
        
        /* The memory MUST be free before exiting the program */
        free(string);

        return 0;
}
