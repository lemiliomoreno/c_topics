#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
        char *string;
        string = (char *)malloc(200 * sizeof(char));

        if (string == NULL)
        {
                fprintf(stderr, "Error allocating memory");
        }
        else
        {
                strcpy(string, "Hello my friend my name is emilio and im here to crash this program");
        }

        printf("%s\n", string);

        free(string);

        return 0;
}
