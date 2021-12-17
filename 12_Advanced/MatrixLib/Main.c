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

    Matrix *m6 = createMatrix(2, 2, 0.0f);
    m6->data[0] = 1;
    m6->data[1] = 2;
    m6->data[2] = 3;
    m6->data[3] = 4;

    Vector *min_axis0 = minMatrix(m6, AXIS_0);
    Vector *max_axis0 = maxMatrix(m6, AXIS_0);

    printVector(min_axis0);
    printVector(max_axis0);

    freeMatrix(m1);
    freeMatrix(m2);
    freeMatrix(m3);
    freeMatrix(m4);
    freeMatrix(m5);
    freeMatrix(m6);

    freeVector(min_axis0);
    freeVector(max_axis0);

    return 0;
}
