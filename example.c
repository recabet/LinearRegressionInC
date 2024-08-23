#include "linear_regression.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	srand(69);  /* Set random seed for reproducibility */

	/* Example starting weight and bias */
	float initial_coefficient = randf() * 10;
	float initial_bias = randf() * 10;

	/* Example data */
	float example_data[][2] = {
		{0, 0},
		{1, 2.3},
		{2, 4.2},
		{3, 7.3},
		{4, 10.2}
	};

	/* Set up training data */
	train_size = sizeof(example_data) / sizeof(example_data[0]);
	train_data = malloc(train_size * sizeof(example_data[0]));
	if (train_data == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		return 1;
	}
	/* Copy example data to train_data */
	for (size_t i = 0; i < train_size; i++) {
		train_data[i][0] = example_data[i][0];
		train_data[i][1] = example_data[i][1];
	}

	/* Train the model */
	float* result = train(initial_coefficient, initial_bias, 1e-2, 1e-2, 5000);

	if (result != NULL) {
		printf("Optimal Coefficient: %f, Optimal Bias: %f\n", result[0], result[1]);
		free(result);
	} else {
		fprintf(stderr, "Training failed\n");
	}

	free(train_data);

	return 0;
}
