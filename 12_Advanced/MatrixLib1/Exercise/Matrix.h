#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h> // for boolean type...
#include <stdint.h> //for uint32_t uint8.t size_t...

//### Type Declaration ###

/* The matrix_t struct holds an 1D array pointer
which is converted to an 2D array*/
typedef struct
{
    float * array;
    size_t num_rows;
    size_t num_cols;

}Matrix;


//### Function Declaration ###

Matrix *createMatrix(const size_t num_rows, const size_t num_cols, const float value);

Matrix *freeMatrix(Matrix *matrix);

size_t matrixIndex(const size_t num_cols, const size_t i, const size_t j);

size_t matrixNumElements(const Matrix *matrix);

bool matrixSameSize(const Matrix *matrix1, const Matrix *matrix2);

void printMatrix(const Matrix *matrix);

#endif /*MATRIX_H*/
