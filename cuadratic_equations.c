#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TOTAL (5)

typedef struct {
	float a;
	float b;
	float c;
	float first_result;
	float second_result;
}equation;

void cuadratic (equation *pEquation);
void fill_structure(char *filename, equation *pEq);

int main (int argc, char *argv[])
{
	if (argc < 2 || argc > 2)
	{
		fprintf(stderr, "Error\nUsage: %s filename.txt\n", argv[0]);
		exit(EXIT_FAILURE);
	}

 	equation *eqs = malloc(TOTAL * sizeof(*eqs));
 
	if (eqs == NULL)
	{
		fprintf(stderr, "Error allocating memory\n");
		exit(EXIT_FAILURE);
	}

	fill_structure(argv[1], eqs);

	cuadratic(eqs);

	free(eqs);

	return EXIT_SUCCESS;
}

void fill_structure(char *filename, equation *pEq)
{
	FILE *fp = fopen(filename, "r");

	if (fp == NULL)
	{
		fprintf(stderr, "Error opening file: %s\n", filename);
		exit(EXIT_FAILURE);
	}

	int i = 0, counter = 1;

	while(i <= TOTAL)
	{
		fscanf(fp, "%f", &pEq->a);
		fscanf(fp, "%f", &pEq->b);
		fscanf(fp, "%f", &pEq->c);
		counter++;
		pEq++;
		if ((counter % 3) == 0)
		{
			i++;
		}
	}
	
	fclose(fp);
}

void cuadratic (equation *pEquation)
{
	float a, b, c, inside_sqrt;
	int counter;

	for(counter = 0; counter < TOTAL; counter++)
	{
		a = pEquation->a;
		b = pEquation->b;
		c = pEquation->c;
	
		inside_sqrt = (b * b) - (4 * a * c);
	
		if (inside_sqrt < 0)
		{
			pEquation->first_result = 0;
			pEquation->second_result = 0;
		}
		else
		{
			pEquation->first_result = ((b * (-1)) + sqrt(inside_sqrt)) / (2 * a);	
			pEquation->second_result = ((b * (-1)) - sqrt(inside_sqrt)) / (2 * a);
		}
	
		printf("%i.- %3.0fx^2 + %3.0fx + %3.0f = 0 -> x1 = %3.4f, x2 = %3.4f\n", counter + 1, pEquation->a, pEquation->b, pEquation->c, pEquation->first_result, pEquation->second_result);
		pEquation++;
	}
}

