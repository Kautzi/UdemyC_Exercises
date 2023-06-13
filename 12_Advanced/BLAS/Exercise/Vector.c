#include <stdlib.h> //for malloc
#include "Vector.h"
#include <math.h>

Vector * createVector(size_t lenght, const float init_value)
{

    Vector * vector = (Vector*)malloc(sizeof(Vector));

    //check if allocation was successfull
    if(vector == NULL)
    {
        return NULL;
    }

    //after allocation momory for a Vector allocate memory for
    //the data member pointer of size lenght
    float * data = (float*)malloc(sizeof(float)*lenght);
    if(data == NULL)
    {
        return NULL;
    }

    //init all data members with init_value
    for(size_t i = 0; i < lenght; i ++)
    {
        data[i]= init_value;
    }

    //after initialisation
    //give the adress of data to the vector member -> data
    vector->data = data;
    vector->length = lenght;

    return vector;
}

void printVector(const Vector * vector)
{
    if(vector == NULL)
    {
        return;
    }

    for(size_t i = 0; i < vector->length; i ++)
    {
        printf("%6.3f,",vector->data[i]);
    }
    printf("\n");
}

Vector *freeVector(Vector *vector)
{

if(vector == NULL)
{
    return NULL;
}

free(vector->data);
vector->data=NULL;

free(vector);
vector=NULL;

return NULL;

}

Vector *addVector(const Vector *vec1, const Vector *vec2)
{

    if((vec1->length != vec2->length) || vec1 == NULL || vec2 == NULL)
    {
        return NULL;
    }

    Vector * add_vec = createVector(vec1->length,0.0f);
    if(add_vec == NULL)
    {
        return NULL;
    }

    for(size_t i = 0; i < add_vec->length; i ++)
    {
        add_vec->data[i] = vec1->data[i] + vec2->data[i];
    }

    return add_vec;
}

Vector *subVector(const Vector *vec1, const Vector *vec2)
{

    if((vec1->length != vec2->length) || vec1 == NULL || vec2 == NULL)
    {
        return NULL;
    }

    Vector * add_vec = createVector(vec1->length,0.0f);
    if(add_vec == NULL)
    {
        return NULL;
    }

    for(size_t i = 0; i < add_vec->length; i ++)
    {
        add_vec->data[i] = vec1->data[i] - vec2->data[i];
    }

    return add_vec;
}

float multiplyVector(const Vector *vec1, const Vector *vec2)
{
 if((vec1->length != vec2->length) || vec1 == NULL || vec2 == NULL)
    {
        return 0.0f;
    }

    float result = 0.0f;

    for(size_t i = 0; i < vec1->length; i ++)
    {
        result += vec1->data[i] * vec2->data[i];
    }

return result;
}

Vector *multiplyScalar(const Vector *vec, const float scalar)
{
    if(vec == NULL)
    {
        return NULL;
    }

    Vector * multi_sclar = createVector(vec->length,0.0f);
    if(multi_sclar == NULL)
    {
        freeVector(multi_sclar);
        return NULL;
    }

    for(size_t i = 0; i < vec->length; i ++)
    {
        multi_sclar->data[i]= vec->data[i] * scalar;
    }

    return multi_sclar;
}

Vector *divideScalar(const Vector *vec, const float scalar)
{
    if(vec == NULL || scalar == 0)
    {
        return NULL;
    }

    Vector * div_sclar = createVector(vec->length,0.0f);
    if(div_sclar == NULL)
    {
        freeVector(div_sclar);
        return NULL;
    }

    for(size_t i = 0; i < vec->length; i ++)
    {
        div_sclar->data[i]= vec->data[i] / scalar;
    }

    return div_sclar;
}

float meanVector(const Vector *vector)
{
    if(vector == NULL)
    {
        return 0;
    }

    float mean = 0;

    for(size_t i = 0; i < vector->length; i ++)
    {
        mean += vector->data[i];
    }

    return mean / (float)vector->length;
}

float minVector(const Vector *vector)
{

    if( vector == NULL)
    {
        return 0.0f;
    }

    float current_min = vector->data[0];

    for(size_t i = 1; i < vector->length; i ++)
    {
        if(vector->data[i] < current_min)
        {
            current_min = vector->data[i];
        }
    }
return current_min;
}

float maxVector(const Vector *vector)
{

    if( vector == NULL)
    {
        return 0.0f;
    }

    float current_max = vector->data[0];

    for(size_t i = 1; i < vector->length; i ++)
    {
        if(vector->data[i] > current_max)
        {
            current_max = vector->data[i];
        }
    }
return current_max;
}

float vectorEuclidNorm(const Vector *vector)
{
    float result=0.0f;
    for(size_t i = 0; i < vector->length; i++)
    {
        result+= powf(vector->data[i],2);

    }
    return sqrtf(result);

}
