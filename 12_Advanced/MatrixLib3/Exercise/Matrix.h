
#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h> // for boolean type...
#include <stdint.h> //for uint32_t uint8.t size_t...
#include "Vector.h"
//### Type Declaration ###

/* The matrix_t struct holds an 1D array pointer
which is converted to an 2D array*/
typedef struct
{
    float * array;
    size_t num_rows;
    size_t num_cols;

}Matrix;

typedef enum
{
    AXIS_0,
    AXIS_1,
} Axis;




//### Function Declaration ###

Matrix *createMatrix(const size_t num_rows, const size_t num_cols, const float value);

Matrix *freeMatrix(Matrix *matrix);

size_t matrixIndex(const size_t num_cols, const size_t i, const size_t j);

size_t matrixNumElements(const Matrix *matrix);

bool matrixSameSize(const Matrix *matrix1, const Matrix *matrix2);

void printMatrix(const Matrix *matrix);

bool matrixMultiplyPossible(const Matrix *matrix1, const Matrix *matrix2);

Matrix *addMatrix(const Matrix *matrix1, const Matrix *matrix2);

Matrix *subMatrix(const Matrix *matrix1, const Matrix *matrix2);

Matrix *multiplyMatrix(const Matrix *matrix1, const Matrix *matrix2);

Matrix *multiplyMatrixByScalar(const Matrix *matrix, const float scalar);

Matrix *divideMatrixByScalar(const Matrix *matrix, const float scalar);

Vector *minMatrix(const Matrix *matrix, const Axis axis);

Vector *maxMatrix(const Matrix *matrix, const Axis axis);

Vector *meanMatrix(const Matrix *matrix, const Axis axis);

#endif /*MATRIX_H*/
