#include <float.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "Vector.h"

/**********************/
/*   MAIN FUNCTIONS   */
/**********************/

Vector *createVector(const size_t length, const float value)
{
    Vector *result = (Vector *)malloc(sizeof(Vector));

    if (result == NULL)
    {
        return NULL;
    }

    float *data = (float *)malloc(length * sizeof(float));

    if (data == NULL)
    {
        free(result);
        return NULL;
    }

    for (size_t i = 0; i < length; i++)
    {
        data[i] = value;
    }


    result->data = data;
    result->length = length;

    return result;
}

Vector *freeVector(Vector *vector)
{
    if (vector == NULL)
    {
        return NULL;
    }

    if (vector->data != NULL)
    {
        free(vector->data);
        vector->data = NULL;
    }

    free(vector);

    return NULL;
}

void setVectorValues(Vector *const vector, size_t count, ...)
{
    va_list args;
    va_start(args, count);

    size_t range = (count > vector->length) ? vector->length : count;

    for (size_t i = 0; i < range; i++)
    {
        vector->data[i] = (float)va_arg(args, double);
    }

    va_end(args);
}

/**********************/
/*  I/O FUNCTIONS     */
/**********************/

void printVector(const Vector *const vector)
{
    if (vector->data == NULL)
    {
        return;
    }

    printf("[");

    for (size_t i = 0; i < vector->length - 1; i++)
    {
        printf("%f, ", vector->data[i]);
    }

    printf("%f]\n\n", vector->data[vector->length - 1]);
}

/**********************/
/*  MATH. FUNCTIONS   */
/**********************/

Vector *addVector(const Vector *const vec1, const Vector *const vec2)
{
    if ((vec1 == NULL) || (vec2 == NULL) || (vec1->length != vec2->length))
    {
        return NULL;
    }

    Vector *result = createVector(vec1->length, 0.0);

    for (size_t i = 0; i < vec1->length; i++)
    {
        result->data[i] = vec1->data[i] + vec2->data[i];
    }

    return result;
}

void *_addVectorParallel(void *args)
{
    ThreadData_t *const thread_data = (ThreadData_t *)(args);

    for (size_t i = 0; i < thread_data->length; i++)
    {
        thread_data->result[i] = thread_data->data1[i] + thread_data->data2[i];
    }

    pthread_exit(NULL);
}

Vector *addVectorParallel(const Vector *const vec1, const Vector *const vec2)
{
    if ((vec1 == NULL) || (vec2 == NULL) || (vec1->length != vec2->length))
    {
        return NULL;
    }

    Vector *result = createVector(vec1->length, 0.0);

    pthread_t threads[NUM_THREADS];
    ThreadData_t thread_datas[NUM_THREADS];

    const size_t slice_length = vec1->length / NUM_THREADS;

    for (uint32_t t = 0; t < NUM_THREADS; ++t)
    {
        size_t offset = t * slice_length;

        thread_datas[t].data1 = &vec1->data[offset];
        thread_datas[t].data2 = &vec2->data[offset];
        thread_datas[t].result = &result->data[offset];
        thread_datas[t].length = slice_length;

        pthread_create(&threads[t], NULL, &_addVectorParallel, (void *)(&thread_datas[t]));
    }

    for (uint32_t t = 0; t < NUM_THREADS; ++t)
    {
        pthread_join(threads[t], NULL);
    }

    return result;
}

Vector *subVector(const Vector *const vec1, const Vector *const vec2)
{
    if ((vec1 == NULL) || (vec2 == NULL) || (vec1->length != vec2->length))
    {
        return NULL;
    }

    Vector *result = createVector(vec1->length, 0.0);

    for (size_t i = 0; i < vec1->length; i++)
    {
        result->data[i] = vec1->data[i] - vec2->data[i];
    }

    return result;
}

float multiplyVector(const Vector *const vec1, const Vector *const vec2)
{
    if ((vec1 == NULL) || (vec2 == NULL) || (vec1->length != vec2->length))
    {
        return 0.0f;
    }

    float result = 0.0f;

    for (size_t i = 0; i < vec1->length; i++)
    {
        result += vec1->data[i] * vec2->data[i];
    }

    return result;
}

Vector *multiplyVectorByScalar(const Vector *const vec, const float scalar)
{
    if (vec == NULL)
    {
        return NULL;
    }

    Vector *result = createVector(vec->length, 0.0);

    for (size_t i = 0; i < vec->length; i++)
    {
        result->data[i] = vec->data[i] * scalar;
    }

    return result;
}

Vector *divideVectorByScalar(const Vector *const vec, const float scalar)
{
    if ((vec == NULL) || (scalar == 0.0f))
    {
        return NULL;
    }

    Vector *result = createVector(vec->length, 0.0);

    for (size_t i = 0; i < vec->length; i++)
    {
        result->data[i] = vec->data[i] / scalar;
    }

    return result;
}

float meanVector(const Vector *const vector)
{
    float sum = 0.0f;

    for (size_t i = 0; i < vector->length; i++)
    {
        sum += vector->data[i];
    }

    return (float)(sum) / (float)(vector->length);
}

float minVector(const Vector *const vector)
{
    if (vector->length == 0)
    {
        return FLT_MAX;
    }

    float current_min = vector->data[0];

    for (size_t i = 1; i < vector->length; i++)
    {
        if (vector->data[i] < current_min)
        {
            current_min = vector->data[i];
        }
    }

    return current_min;
}

float maxVector(const Vector *const vector)
{
    if (vector->length == 0)
    {
        return FLT_MIN;
    }

    float current_max = vector->data[0];

    for (size_t i = 1; i < vector->length; i++)
    {
        if (vector->data[i] > current_max)
        {
            current_max = vector->data[i];
        }
    }

    return current_max;
}

float vectorEuclidNorm(const Vector *const vector)
{
    if (vector == NULL)
    {
        return 0.0f;
    }

    float sum = 0.0f;

    for (size_t i = 0; i < vector->length; i++)
    {
        sum += powf(vector->data[i], 2.0f);
    }

    return sqrtf(sum);
}
