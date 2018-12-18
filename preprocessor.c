#include <stdio.h>
#include <string.h>

/* Defining a single value */
#define VALUE (5 * 10)

/* Defining a function, if x > y, print x, if not, print y */
#define GREATER(x, y) ((x) > (y) ? (x) : (y))

/* Defining a value, with ifndef, define, endif, this is used in the HEADERS
 * like: 
 * #ifndef _HEADER_H_
 * #define _HEADER_H_
 * ...function declarations...
 * #endif
 */
#ifndef NULL
#define NULL (void *)0
#endif //ifndef NULL

#define SIZE_NAME (10)

typedef struct {
        struct {
                char first_name[SIZE_NAME];
                char last_name[SIZE_NAME];
        }name;
        int age;
        int height;
}person;

/* Defining access to a structure with pasting tokens */
#define FIELD(field) Emilio.name.field

int main (void)
{
        /* If 0 won't compile, if 1 will compile */
        #if 0

        printf("First part of the code is being executed: %d\n", VALUE + 1);

        # elif 0

        printf("Second part of the code is being executed: %d\n", GREATER(10, 5));

        #elif 0

        int variable = NULL;
        printf("Third part of the code is being executed: %i\n", variable);

        #else

        person Emilio;
        strcpy(Emilio.name.first_name, "Luis");
        strcpy(Emilio.name.last_name, "Moreno");
        printf("Name of the person: %s %s\n", Emilio.name.first_name, Emilio.name.last_name);
        
        /* Printing values with tokens */
        printf("Name of the person: %s %s\n", FIELD(first_name), FIELD(last_name));
        
        /* They MUST end with #endif */
        #endif

        return 0;
}
