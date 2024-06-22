#include "linear_regression.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

float (* train_data)[2];

size_t train_size;

float randf()
{
	return (float) rand() / (float) RAND_MAX;
}


float cost(float coeff, float bias)
{
	float total_cost = 0;

	for(size_t i = 0; i < train_size; i++)
	{
		float prediction = coeff * train_data[i][0] + bias;
		float error = prediction - train_data[i][1];
		total_cost += error * error;
	}

	return total_cost / (float) train_size;
}


float* train(float coeff, float bias, const float epsilon,const  float rate, size_t iterations)
{
	float* wb_tuple =(float*) malloc(sizeof(float) * 2);

	if(wb_tuple == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n", errno);
		exit(EXIT_FAILURE);
	}

	for(size_t i = 0; i < iterations; i++)
	{
		float dcoeff = (cost(coeff + epsilon, bias) - cost(coeff, bias)) / epsilon;
		float dbias = (cost(coeff, bias + epsilon) - cost(coeff, bias)) / epsilon;
		coeff -= rate * dcoeff;
		bias -= rate * dbias;
	}

	wb_tuple[0] = coeff;
	wb_tuple[1] = bias;

	return wb_tuple;
}
