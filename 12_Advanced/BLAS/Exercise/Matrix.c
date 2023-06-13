
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

free(matrix->array);
matrix->array=NULL;

//and then free matrix

free(matrix);
matrix = NULL;


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
    if (    (matrix1->num_rows ==  matrix2->num_rows) && (matrix1->num_cols ==  matrix2->num_cols)   )
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

bool matrixMultiplyPossible(const Matrix *matrix1, const Matrix *matrix2)
{
/*The matrix multiplication is only defined for
the case that num_cols of matrix 1 == num_row of matrix2
*/
    if(matrix1->num_cols == matrix2->num_rows)
    {
        return true;
    }

    else
    {
        return false;
    }



}
//### END => matrixMultiplyPossible(const Matrix *matrix1, const Matrix *matrix2)

Matrix *addMatrix(const Matrix *matrix1, const Matrix *matrix2)
{
    Matrix* added_matrix = createMatrix(matrix1->num_rows,matrix1->num_cols,0);
    if(matrixSameSize(matrix1,matrix2))
    {


        for(size_t i = 0; i <  matrix1->num_rows; i++ )
        {
            for(size_t j = 0; j < matrix1->num_cols; j++)
            {
                const size_t idx = matrixIndex(added_matrix->num_cols,i,j); // helper variable

                added_matrix->array[idx]= matrix1->array[idx] + matrix2->array[idx];
            }
        }
    }
    else
    {
        freeMatrix(added_matrix);
        return NULL;
    }

    return added_matrix;

}
//### END => Matrix *addMatrix(const Matrix *matrix1, const Matrix *matrix2)

Matrix *subMatrix(const Matrix *matrix1, const Matrix *matrix2)
{
Matrix* subtracted_matrix = createMatrix(matrix1->num_rows,matrix1->num_cols,0);
    if(matrixSameSize(matrix1,matrix2))
    {


        for(size_t i = 0; i <  matrix1->num_rows; i++ )
        {
            for(size_t j = 0; j < matrix1->num_cols; j++)
            {
                const size_t idx = matrixIndex(subtracted_matrix->num_cols,i,j);

                subtracted_matrix->array[idx]= matrix1->array[idx] - matrix2->array[idx];
            }
        }
    }
    else
    {
        freeMatrix(subtracted_matrix);
        return NULL;
    }

    return subtracted_matrix;




}
//### END => Matrix *subMatrix(const Matrix *matrix1, const Matrix *matrix2)

Matrix *multiplyMatrix(const Matrix *matrix1, const Matrix *matrix2)
{

if( matrixMultiplyPossible(matrix1,matrix2) )
{
//create a result matrix with num rows of first matrix and num cols of second matrix

Matrix * result_matrix = createMatrix(matrix1->num_rows,matrix2->num_cols,0);

for( size_t i = 0; i < matrix1->num_rows; i ++)
{
    for(size_t j = 0; j < matrix2->num_cols; j++)
    {
        const size_t index_ij = matrixIndex(matrix2->num_cols,i,j);

        result_matrix->array[index_ij]= 0.0f;

        for(size_t k = 0; k < matrix2->num_rows; k ++)
        {
            const size_t index_ik = matrixIndex(matrix2->num_cols,i,k);

            const size_t index_kj = matrixIndex(matrix2->num_cols,k,j);

            result_matrix->array[index_ij]= result_matrix->array[index_ij] + matrix1->array[index_ik] * matrix2->array[index_kj];

        }
    }

}


return result_matrix;
}

return NULL;
}
//### END => Matrix *multiplyMatrix(const Matrix *matrix1, const Matrix *matrix2)

Matrix *multiplyMatrixByScalar(const Matrix *matrix, const float scalar)
{
    if(matrix == NULL)
    {
        return NULL;
    }

    Matrix* scalar_matrix = createMatrix(matrix->num_cols,matrix->num_rows,0);
    if(scalar_matrix == NULL)
    {
        return NULL;
    }

    for(size_t i = 0 ; i < (matrix->num_cols * matrix->num_rows); i++)
    {
        scalar_matrix->array[i]= matrix->array[i] * scalar;
    }

return scalar_matrix;

}
//### END => Matrix *multiplyMatrixByScalar(const Matrix *matrix, const float scalar)


Matrix *divideMatrixByScalar(const Matrix *matrix, const float scalar)
{
    if(scalar == 0)
    {
        printf("\nDivision by 0 is not allowed!!\n");
        return NULL;
    }

    if(matrix == NULL)
    {
        return NULL;
    }

    Matrix* scalar_matrix = createMatrix(matrix->num_cols,matrix->num_rows,0);
    if(scalar_matrix == NULL)
    {
        return NULL;
    }

    for(size_t i = 0 ; i < (matrix->num_cols * matrix->num_rows); i++)
    {
        scalar_matrix->array[i]= matrix->array[i] / scalar;
    }

return scalar_matrix;



}
//### END => Matrix *divideMatrixByScalar(const Matrix *matrix, const float scalar)

Vector *minMatrix(const Matrix *matrix, const Axis axis)
{

    if(matrix == NULL)
    {
        return NULL;
    }

//now with the switch operation decide if the iteration goes about the rows or cols
// AXIS_0 means operation on each col
//AXIS_1 means operation on each row
    switch(axis)
    {
        case AXIS_0:
        {
            Vector* col_vector = createVector(matrix->num_rows,0.0f); //holds all elements of a col
            Vector* col_min = createVector(matrix->num_cols,0.0f); // holds all mins of the matrix

            for(size_t i = 0; i < matrix->num_cols; i++)
                {
                    for(size_t j = 0; j < matrix->num_rows;j++)
                    {
                        col_vector->data[j]=matrix->array[matrixIndex(matrix->num_cols,j,i)];
                    }
                col_min->data[i]=minVector(col_vector);
                }
            return col_min;
            break;
        }

        case AXIS_1:
        {
             Vector* row_vector = createVector(matrix->num_cols,0.0f); //holds all elements of a col
            Vector* row_min = createVector(matrix->num_rows,0.0f); // holds all mins of the matrix

            for(size_t i = 0; i < matrix->num_rows; i++)
                {
                    for(size_t j = 0; j < matrix->num_cols;j++)
                    {
                        row_vector->data[j]=matrix->array[matrixIndex(matrix->num_cols,i,j)];
                    }
                row_min->data[i]=minVector(row_vector);
                }
            return row_min;
            break;
        }

        default:
        return NULL;
        break;
    }


}

Vector *maxMatrix(const Matrix *matrix, const Axis axis)
{
 if(matrix == NULL)
    {
        return NULL;
    }

//now with the switch operation decide if the iteration goes about the rows or cols
// AXIS_0 means operation on each col
//AXIS_1 means operation on each row
    switch(axis)
    {
        case AXIS_0:
        {
            Vector* col_vector = createVector(matrix->num_rows,0.0f); //holds all elements of a col
            Vector* col_min = createVector(matrix->num_cols,0.0f); // holds all mins of the matrix

            for(size_t i = 0; i < matrix->num_cols; i++)
                {
                    for(size_t j = 0; j < matrix->num_rows;j++)
                    {
                        col_vector->data[j]=matrix->array[matrixIndex(matrix->num_cols,j,i)];
                    }
                col_min->data[i]=maxVector(col_vector);
                }
            return col_min;
            break;
        }

        case AXIS_1:
        {
             Vector* row_vector = createVector(matrix->num_cols,0.0f); //holds all elements of a col
            Vector* row_min = createVector(matrix->num_rows,0.0f); // holds all mins of the matrix

            for(size_t i = 0; i < matrix->num_rows; i++)
                {
                    for(size_t j = 0; j < matrix->num_cols;j++)
                    {
                        row_vector->data[j]=matrix->array[matrixIndex(matrix->num_cols,i,j)];
                    }
                row_min->data[i]=maxVector(row_vector);
                }
            return row_min;
            break;
        }

        default:
        return NULL;
        break;
    }




}

Vector *meanMatrix(const Matrix *matrix, const Axis axis)
{

if(matrix == NULL)
    {
        return NULL;
    }

//now with the switch operation decide if the iteration goes about the rows or cols
// AXIS_0 means operation on each col
//AXIS_1 means operation on each row
    switch(axis)
    {
        case AXIS_0:
        {
            Vector* col_vector = createVector(matrix->num_rows,0.0f); //holds all elements of a col
            Vector* col_min = createVector(matrix->num_cols,0.0f); // holds all mins of the matrix

            for(size_t i = 0; i < matrix->num_cols; i++)
                {
                    for(size_t j = 0; j < matrix->num_rows;j++)
                    {
                        col_vector->data[j]=matrix->array[matrixIndex(matrix->num_cols,j,i)];
                    }
                col_min->data[i]=meanVector(col_vector);
                }
            return col_min;
            break;
        }

        case AXIS_1:
        {
             Vector* row_vector = createVector(matrix->num_cols,0.0f); //holds all elements of a col
            Vector* row_min = createVector(matrix->num_rows,0.0f); // holds all mins of the matrix

            for(size_t i = 0; i < matrix->num_rows; i++)
                {
                    for(size_t j = 0; j < matrix->num_cols;j++)
                    {
                        row_vector->data[j]=matrix->array[matrixIndex(matrix->num_cols,i,j)];
                    }
                row_min->data[i]=meanVector(row_vector);
                }
            return row_min;
            break;
        }

        default:
        return NULL;
        break;
    }


}

Matrix *matrixTranspose(const Matrix *matrix)
{



}

bool matrixMultiplyByVectorPossible(const Matrix *matrix, const Vector *vector)
{



}

Vector *multiplyMatrixByVector(const Matrix *matrix, const Vector *vector)
{



}
