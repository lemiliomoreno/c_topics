#include <stdio.h>

/* This struct will be stored like (in 64-bit OS): */
typedef struct {
        char a;         /* 1 byte  */
        /* char pad1[7];   7 bytes */
        char *p;        /* 8 bytes */
        int b;          /* 8 bytes */
}struct1;
/* So the total size will be 24 bytes */

/* We can try to pack the structure: */
typedef struct {
        char *p;        /* 8 bytes */
        int b;          /* 4 bytes */
        char a;         /* 1 byte  */
        /* char pad1[3]    3 bytes */
}struct2;
/* So the total size will be 16 bytes */

/* Lets see another example (with a inner structure): */
typedef struct {
        char b;                 /* 1 byte  */
        /* char pad1[7]            7 bytes */
        struct {
                char *p;        /* 8 bytes */
                int a;          /* 4 bytes */
                /* char pad2[4]    4 bytes */
        }inner;
}struct3;
/* So the total size will be 24 bytes */

/* And when we try to pack it: */
typedef struct {
        struct {
                char *p;        /* 8 bytes */
                int a;          /* 4 bytes */
                /* char pad1[4]    4 bytes */
        }inner;
        char b;                 /* 1 byte */
        /* char pad1[7]            7 bytes */
}
/* So the total size will be 24 bytes bytes */
/* It's the same because C cannot back into the inner struct’s trailing padding */

int main (void)
{
        printf("Size of struct1: %d bytes\n", (int)sizeof(struct1));
        printf("Size of struct1 packed: %d bytes\n", (int)sizeof(struct2));
        printf("Size of struct2: %d bytes\n", (int)sizeof(struct3));
        printf("Size of struct2 packed: %d bytes\n", (int)sizeof(struct4));
        return 0;
}

