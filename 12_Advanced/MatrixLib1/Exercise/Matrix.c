
#include <stdio.h> //for printf...
#include <stdlib.h>//for malloc...
#include <stdint.h> //for uint32_t uint8.t size_t...
#include <stdbool.h> // for boolean type...
#include "Matrix.h"


Matrix *createMatrix( const size_t num_rows,  const size_t num_cols, const float value)
{

    //first allocate mem for a Matrix struct on heap
    Matrix * matrix = (Matrix*)malloc(sizeof(Matrix));

    //then check if allocation was succesfull
    if( matrix == NULL)
    {
        return NULL;
    }

    //then allocate mem for an array with num col /rows 1D
    float * array = (float*)malloc(sizeof(float)*num_rows*num_cols);

    // check succes
    if(array == NULL)
    {
        return NULL;
    }

    matrix->array = array;
    matrix->num_cols = num_cols;
    matrix->num_rows = num_rows;

    //init all elements of array with value
    for(size_t i = 0; i < (num_cols * num_rows) ; i++ )
    {
        matrix->array[i]=value;
    }

return matrix;

}
//### END => Matrix *createMatrix(const size_t num_rows, const size_t num_cols, const float value)

Matrix *freeMatrix(Matrix *matrix)
{

//first free the array of MAtrix
matrix->array=NULL;
free(matrix->array);

//and then free matrix
matrix = NULL;
free(matrix);


return NULL;
}
//### END => Matrix *freeMatrix(Matrix *matrix)

size_t matrixIndex(const size_t num_cols, const size_t i, const size_t j)
{





}
//### END => size_t matrixIndex(const size_t num_cols, const size_t i, const size_t j)

size_t matrixNumElements(const Matrix *matrix)
{





}
//### END => size_t matrixNumElements(const Matrix *matrix)

bool matrixSameSize(const Matrix *matrix1, const Matrix *matrix2)
{




}
//### END => bool matrixSameSize(const Matrix *matrix1, const Matrix *matrix2)

void printMatrix(const Matrix *matrix)
{





}
//### END => void printMatrix(const Matrix *matrix)
