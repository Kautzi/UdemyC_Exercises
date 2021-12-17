#ifndef MATRIX_H
#define MATRIX_H

/**********************/
/* DEFINES AND TYPES  */
/**********************/
typedef struct Matrix
{
    float *data;
    size_t num_rows;
    size_t num_cols;
} Matrix;

/**********************/
/*   MAIN FUNCTIONS   */
/**********************/

Matrix *createMatrix(const size_t length, const float value);

Matrix *freeMatrix(Matrix *matrix);

size_t matrixNumElements(const Matrix *const matrix);

/**********************/
/*  I/O FUNCTIONS     */
/**********************/

int readInMatrixData(Matrix *vec, const char *filepath);

int writeOutMatrixData(Matrix *vec, const char *filepath);

void printMatrix(const Matrix *matrix);

/**********************/
/*  MATH. FUNCTIONS   */
/**********************/

Matrix *addMatrix(const Matrix *vec1, const Matrix *vec2);

Matrix *subMatrix(const Matrix *vec1, const Matrix *vec2);

float multiplyMatrix(const Matrix *vec1, const Matrix *vec2);

Matrix *multiplyScalar(const Matrix *vec, const float scalar);

Matrix *divideScalar(const Matrix *vec, const float scalar);

float meanMatrix(const Matrix *matrix, const Axis axis);

float minMatrix(const Matrix *matrix, const Axis axis);

float maxMatrix(const Matrix *matrix, const Axis axis);

#endif // MATRIX_H
