/* Bibliography: Raymond, E. (2018). The Lost Art of Structure Packing.
 * Available at: http://www.catb.org/esr/structure-packing/ 
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_STRUCTS (100)

float saved_mem (float packed, float padded);

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
}struct4;
/* So the total size will be 24 bytes */
/* It's the same because C cannot back into the inner struct’s trailing padding */

int main (void)
{
	printf("Size of struct1: %d bytes\n", (int)sizeof(struct1));
        printf("Size of struct1 packed: %d bytes, saved: %.2f%%\n", (int)sizeof(struct2), saved_mem((float)sizeof(struct2), (float)sizeof(struct1)));
	printf("Size of struct2: %d bytes\n", (int)sizeof(struct3));
	printf("Size of struct2 packed: %d bytes, saved: %.2f%%\n", (int)sizeof(struct4), saved_mem((float)sizeof(struct4), (float)sizeof(struct3)));

	/* Imagine we need to allocate the space of 100 structs, the packed structure
	 * will be better because it will allocate less memory, let's try to check for
	 * the memory stored with 100 structures of ps1 and ps2 with Valgrind:
	 * valgrind --leak-check=yes ./structure_padding_and_packing.c
	 * struct 1 will allocate 2400 bytes, meanwhile struct2 will allocate 1600 bytes
	 */
	 
	printf("--------------------\n");

	#if 1
	
	struct1 *ps1 = malloc(MAX_STRUCTS * sizeof *ps1);
	
	if (ps1 == NULL)
	{
		fprintf(stderr, "Error allocating memory in ps1\n");
		exit(EXIT_FAILURE);
	}
	
	printf("*ps1 is a pointer, the allocated memory will be 24 bytes * 100 = 2400 bytes\n");
	
	free(ps1);
	
	#else 
	
	struct2 *ps2 = malloc(MAX_STRUCTS * sizeof *ps2);
	
	if (ps2 == NULL)
	{
		fprintf(stderr, "Error allocating memory in ps2\n");
		exit(EXIT_FAILURE);
	}

	printf("*ps2 is a pointer, the allocated memory will be 16 bytes * 100 = 1600 bytes\n");

	free(ps2);

	#endif
	
        return 0;
}

float saved_mem (float packed, float padded)
{
        return (100 - ((packed / padded) * 100));
}
