#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	float a;
	float b;
	float c;
	float first_result;
	float second_result;
}equation;

void cuadratic (equation *pEquation);
void fill_structure(char *filename, equation *pEq);
int get_total(char *filename);

long TOTAL;

int main (int argc, char *argv[])
{
	if (argc < 2 || argc > 2)
	{
		fprintf(stderr, "Error\nUsage: %s filename.txt\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	TOTAL = get_total(argv[1]);

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

int get_total(char *filename)
{
	FILE *command;
	char command_to_run[50];
	char total_lines[6];
	int len;
	long total;
	
	len = sprintf(command_to_run, "wc %s", filename);

	if (len >= sizeof(command_to_run))
	{
		fprintf(stderr, "Filename is larger than buffer\n");
		exit(EXIT_FAILURE);
	}
	
	command = popen(command_to_run, "r");

	if (command == NULL)
	{
		fprintf(stderr, "Error running command: %s\n", command_to_run);
                exit(EXIT_FAILURE);
	}

	fgets(total_lines, sizeof(total_lines) - 1, command);

	pclose(command);

	total = strtol(total_lines, NULL, 10);

	return total;
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
			inside_sqrt *= (-1);
			pEquation->first_result = sqrt(inside_sqrt) / (2 * a);
			pEquation->second_result = pEquation->first_result * (-1);
			printf("%i.- %3.0fx^2 + %3.0fx + %3.0f = 0 -> x1 = %3.4f + %3.4fi, x2 = %3.4f + %3.4fi\n", counter + 1, pEquation->a, pEquation->b, pEquation->c, b / (2 * a), pEquation->first_result, b / (2 * a), pEquation->second_result);

		}
		else
		{
			pEquation->first_result = ((b * (-1)) + sqrt(inside_sqrt)) / (2 * a);	
			pEquation->second_result = ((b * (-1)) - sqrt(inside_sqrt)) / (2 * a);
			printf("%i.- %3.0fx^2 + %3.0fx + %3.0f = 0 -> x1 = %3.4f, x2 = %3.4f\n", counter + 1, pEquation->a, pEquation->b, pEquation->c, pEquation->first_result, pEquation->second_result);

		}
	
		pEquation++;
	}
}

