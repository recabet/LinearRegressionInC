#include "linear_regression.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

float (*train_data)[2];

size_t train_size;

float randf(void)
{
    return (float) rand() / (float) RAND_MAX;
}


float cost(const float coeff, const float bias)
{
    float total_cost = 0;

    for (size_t i = 0; i < train_size; i++)
    {
        const float prediction = coeff * train_data[i][0] + bias;
        const float error = prediction - train_data[i][1];
        total_cost += error * error;
    }

    return total_cost / (float) train_size;
}

float* fit(float coeff, float bias, const float epsilon, const float rate, const size_t iterations)
{
    float* wb_tuple = (float *) malloc(sizeof(float) * 2);

    if (wb_tuple == NULL)
    {
        perror("Linear regression");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < iterations; i++)
    {
        const float dcoeff = (cost(coeff + epsilon, bias) - cost(coeff, bias)) / epsilon;
        const float dbias = (cost(coeff, bias + epsilon) - cost(coeff, bias)) / epsilon;
        coeff -= rate * dcoeff;
        bias -= rate * dbias;
    }

    wb_tuple[0] = coeff;
    wb_tuple[1] = bias;

    return wb_tuple;
}
