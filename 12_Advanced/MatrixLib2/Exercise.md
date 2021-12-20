# Exercise

Implement the following functions for a **matrix** library:

```cpp
bool matrixMultiplyPossible(const Matrix *const matrix1, const Matrix *const matrix2);

Matrix *addMatrix(const Matrix *matrix1, const Matrix *matrix2);

Matrix *subMatrix(const Matrix *matrix1, const Matrix *matrix2);

Matrix *multiplyMatrix(const Matrix *matrix1, const Matrix *matrix2);

Matrix *multiplyMatrixByScalar(const Matrix *matrix, const float scalar);

Matrix *divideMatrixByScalar(const Matrix *matrix, const float scalar);
```

- addMatrix
  - Add two matrices, check if the dimensions match with **matrixSameSize**
- subMatrix
  - Subtract two matrices, check if the dimensions match with **matrixSameSize**
- multiplyMatrix
  - Multiply two matrices, check if the dimensions match with **matrixMultiplyPossible**
- multiplyMatrixByScalar
  - Multiply matrix element-wise with a scalar value
- divideMatrixByScalar
  - Divide matrix element-wise with a scalar value, check for division-by-zero

Hint:
You can use the **vector** library as a starting point!

## Main Function

```cpp
#include <stdio.h>
#include <stdlib.h>

#include "Matrix.h"
#include "Vector.h"

int main()
{
    Matrix *m1 = createMatrix(3, 3, -1.0f);
    Matrix *m2 = createMatrix(3, 3, +1.0f);
    printMatrix(m1);
    printMatrix(m2);

    Matrix *m3 = addMatrix(m1, m2);
    Matrix *m4 = subMatrix(m3, m1);
    printMatrix(m3);
    printMatrix(m4);

    Matrix *m5 = multiplyMatrix(m1, m2);
    printMatrix(m5);

    Matrix *m6 = createMatrix(2, 3, 0.0f);
    printMatrix(m6);

    freeMatrix(m1);
    freeMatrix(m2);
    freeMatrix(m3);
    freeMatrix(m4);
    freeMatrix(m5);
    freeMatrix(m6);

    return 0;
}
```

## Expected Console Output

![alt](../../media/12_Matrix2.png)
