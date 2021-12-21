# Exercise

Implement the following functions for our **vector**:

```cpp
float vectorEuclidNorm(const Vector *vector);
```

- vectorEuclidNorm
  - Example for 2d vector: $\vec{v} = \begin{pmatrix}x \\ y\end{pmatrix} = \sqrt{x^2 + y^2}$
  - Generalized formula: $\vec{v} = \begin{pmatrix}x_1 \\ \vdots \\ x_n\end{pmatrix} = \sqrt{\sum_{i = 1}^n x_i^2}$

Implement the following functions for our **matrix**:

```cpp
Matrix *matrixTranspose(const Matrix *matrix);

bool matrixMultiplyByVectorPossible(const Matrix *matrix, const Vector *vector);

Vector *multiplyMatrixByVector(const Matrix *matrix, const Vector *vector);
```

- matrixTranspose
  - Adapt the transpose function from the main course to our matrix data structure
- multiplyMatrixByVector
  - $\underset{m\times 1}{\vec{v_{2}} } =  \underset{m\times n}{M_1} \times 
\underset{n\times 1}{\vec{v_{1}}}$
  - More information: [see here](https://mathinsight.org/matrix_vector_multiplication)

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
    Vector *v1 = createVector();
    

    freeMatrix(m1);
    freeMatrix(m2);
    freeMatrix(m3);
    freeMatrix(m4);
    freeMatrix(m5);
    freeMatrix(m6);

    freeVector(min_axis0);
    freeVector(max_axis0);
    freeVector(mean_axis0);
    freeVector(mean_axis1);

    return 0;
}
```
