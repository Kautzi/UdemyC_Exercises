
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

/* the function gets the row and col coordinate for an 2D array but we have an
1D array so you have to calculate from 2D to 1D and give the 1D adress back

Build of a 2D array

row     col

0       0       1       (2)

1       0       1       2

2       0       (1)       2

3       (0)       1       2

Build of an 1D array

row

0       1       (2)    |   3       4       5    |   6       (7)       8  |   9       10      11

1.EXAMPLE:

(row)i= 2 (col)j= 1
num_cols =3

i * num_col + col => 2 * 3 + 1= 7

2.EXAMPLE

(row)i= 0 (col)j= 2
num_cols =3

i * num_col + j => 0 * 3 + 2 = 2

3. EXAMPLE

(row)i= 3 (col)j= 0
num_cols = 3

i * num_col + j => 3 * 3 + 0 = 9

*/

return i * num_cols + j;


}
//### END => size_t matrixIndex(const size_t num_cols, const size_t i, const size_t j)

size_t matrixNumElements(const Matrix *matrix)
{

return matrix->num_cols * matrix->num_rows;



}
//### END => size_t matrixNumElements(const Matrix *matrix)

bool matrixSameSize(const Matrix *matrix1, const Matrix *matrix2)
{
    if (    matrixNumElements(matrix1) == matrixNumElements(matrix2)    )
    {
        return true;
    }
    else
    {
        return false;
    }



}
//### END => bool matrixSameSize(const Matrix *matrix1, const Matrix *matrix2)

void printMatrix(const Matrix *matrix)
{

    for(size_t i = 0; i < matrix->num_rows; i++)
    {
        if(i == 0 )
        {
            printf("[[");
        }
        else
        {
            printf("  ");
        }
        for( size_t j = 0; j < matrix->num_cols;j++)
        {
            printf("%.5f",matrix->array[matrixIndex(matrix->num_cols, i , j)]);
            if(j < matrix->num_cols-1)
            {
                printf(", ");
            }

            else
            printf("]");
        }
    if(i == matrix->num_rows-1)
    {
    printf("]\n");
    }
    else
    {
    printf("\n");
    }

    }




}
//### END => void printMatrix(const Matrix *matrix)
