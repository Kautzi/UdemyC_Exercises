#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h> //for size_t

//### Typedef ###

typedef struct Vector
{
    float *data;
    size_t length;
} Vector;

//### END Typedef ###

//### functions ###

/*create Vector function:
allocates dynamical memory for a Vector with lenght length
and initialise the data array with the value of init_value
*/

Vector * createVector(size_t lenght, const float init_value);
//### END createVector() ###

/*printVector function:
prints the Vector created with createVector() function
*/

void printVector(const Vector* vector);
//### END printVector() ###

Vector *freeVector(Vector *vector);

Vector *addVector(const Vector *vec1, const Vector *vec2);

Vector *subVector(const Vector *vec1, const Vector *vec2);

float multiplyVector(const Vector *vec1, const Vector *vec2);

Vector *multiplyScalar(const Vector *vec, const float scalar);

Vector *divideScalar(const Vector *vec, const float scalar);

float meanVector(const Vector *vector);

float minVector(const Vector *vector);

float maxVector(const Vector *vector);

float vectorEuclidNorm(const Vector *vector);

#endif /* VECTOR_H */
