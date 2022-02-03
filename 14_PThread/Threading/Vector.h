#ifndef VECTOR_H
#define VECTOR_H

#include <stdint.h>
#include <stdlib.h>

/**********************/
/* DEFINES AND TYPES  */
/**********************/

/**
 * Serial: 3593.75 ns
 *      2: 49843.75 ns
 *      4: 102656.25 ns
 *      6: 196406.25 ns
 *      8: 290312.50 ns
 */
#define USE_THREADING
#define NUM_THREADS (uint32_t)(1)

#ifdef USE_THREADING
#include <pthread.h>
#endif

typedef struct
{
    float *data;
    size_t length;
} Vector;

typedef struct
{
    float *data1;
    float *data2;
    float *result;
    size_t length;
} ThreadData_t;

/**********************/
/*   MAIN FUNCTIONS   */
/**********************/

Vector *createVector(const size_t length, const float value);

Vector *freeVector(Vector *vector);

void setVectorValues(Vector *const vector, size_t count, ...);

/**********************/
/*  I/O FUNCTIONS     */
/**********************/

void printVector(const Vector *const vector);

/**********************/
/*  MATH. FUNCTIONS   */
/**********************/

Vector *addVector(const Vector *const vec1, const Vector *const vec2);

Vector *addVectorParallel(const Vector *const vec1, const Vector *const vec2);

Vector *subVector(const Vector *const vec1, const Vector *const vec2);

float multiplyVector(const Vector *const vec1, const Vector *const vec2);

Vector *multiplyScalar(const Vector *const vec, const float scalar);

Vector *divideScalar(const Vector *const vec, const float scalar);

float meanVector(const Vector *const vector);

float minVector(const Vector *const vector);

float maxVector(const Vector *const vector);

float vectorEuclidNorm(const Vector *const vector);

#endif // VECTOR_H
