//
// Created by Recabet on 12/06/24.
//

#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

#include <stddef.h>

extern float (* train_data)[2];

extern size_t train_size;

float randf();

float cost(float coeff, float bias);

float* train(float coeff, float bias,float  epsilon, float rate, size_t iterations);


#endif //LINEAR_REGRESSION_H
