#include "linear_regression.h"
#include <stdio.h>
#include <stdlib.h>

//Some example usage

int main(int argc, char** argv)
{
	//Example  starting weight and bias.
	srand(69);
	float k = randf() * 10;
	float b = randf() * 10;
	//Example data
	float example_data[][2] = {{0, 0},
							   {1, 2.3},
							   {2, 4.2},
							   {3, 7.3},
							   {4, 10.2}};

	train_size = sizeof(example_data) / sizeof(example_data[0]);
	train_data = malloc(train_size * sizeof(example_data[0]));
	if(train_data == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return 1;
	}
	// Copy example data to train_data
	for(size_t i = 0; i < train_size; i++)
	{
		train_data[i][0] = example_data[i][0];
		train_data[i][1] = example_data[i][1];
	}

	float* result = train(k, b, 1e-2, 1e-2, 5000);

	if(result != NULL)
	{
		printf("Coefficient: %f, Bias: %f\n", result[0], result[1]);
		free(result);
	}
	else
	{
		fprintf(stderr, "Training failed\n");
	}

	free(train_data);

	return 0;
}

