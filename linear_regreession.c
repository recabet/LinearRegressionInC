#include "linear_regression.h"
#include <stdio.h>
#include <stdlib.h>

float (*train_data)[2];

size_t train_size;


float randf ()
{
	return (float) rand() / (float) RAND_MAX;
}


float cost (float coeff, float bias)
{
	float total_cost = 0;
	for (size_t i = 0; i < train_size; i++)
	{
		float prediction = coeff * train_data[i][0] + bias;
		float error = prediction - train_data[i][1];
		total_cost += error * error;
	}
	return total_cost / (float) train_size;
}


float* train (float coeff, float bias, float epsilon, float rate, size_t iterations)
{
	float *wb_tuple = malloc(sizeof(float) * 2);
	if (wb_tuple == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(1);
	}

	for (size_t i = 0; i < iterations; i++)
	{
		float dcost_dcoeff = (cost(coeff + epsilon, bias) - cost(coeff, bias)) / epsilon;
		float dcost_dbias = (cost(coeff, bias + epsilon) - cost(coeff, bias)) / epsilon;
		coeff -= rate * dcost_dcoeff;
		bias -= rate * dcost_dbias;
	}

	wb_tuple[0] = coeff;
	wb_tuple[1] = bias;
	return wb_tuple;
}
