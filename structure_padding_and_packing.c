#include <stdio.h>

typedef struct {
        char a;
        char *p;
        int b;
}struct1;

int main (void)
{

        printf("Size of struct1: %d\n", (int)sizeof(struct1));

        return 0;
}
