#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Timer.h"

/**
 * Serial: 9137.66 us
 *      2: 4825.89 us
 *      4: 2577.69 us
 *      6: 1817.76 us
 *      8: 1446.42 us
 */
#define USE_THREADING
#define NUM_THREADS (uint32_t)(8)
#define LENGTH (size_t)(1e07)
#ifndef NDEBUG
#define NUM_RUNS (uint32_t)(10)
#else
#define NUM_RUNS (uint32_t)(5000)
#endif
#define TEST_SERIAL

#ifdef USE_THREADING
#include <pthread.h>
#endif

typedef struct
{
    float *arr;
    size_t length;
    float *sum;
} ThreadData_t;

float serial_sum(const float *const arr, const size_t length)
{
    if (arr == NULL)
    {
        return 0.0F;
    }

    float result = 0.0F;

    for (size_t i = 0; i < length; i++)
    {
        result += arr[i];
    }

    return result;
}

void *_parallel_sum(void *args)
{
    ThreadData_t *const thread_data = (ThreadData_t *)(args);

    *thread_data->sum = serial_sum(thread_data->arr, thread_data->length);

    return NULL;
}

float parallel_sum(const float *const arr, const size_t length)
{
    if (arr == NULL)
    {
        return 0.0F;
    }

    pthread_t threads[NUM_THREADS];
    ThreadData_t thread_datas[NUM_THREADS];
    float sums[NUM_THREADS];

    const size_t slice_length = length / NUM_THREADS;

    for (uint32_t t = 0; t < NUM_THREADS; ++t)
    {
        const size_t offset = t * slice_length;

        thread_datas[t].arr = (float *)&arr[offset];
        thread_datas[t].length = slice_length;
        thread_datas[t].sum = &sums[t];

        pthread_create(&threads[t], NULL, &_parallel_sum, (void *)(&thread_datas[t]));
    }

    for (uint32_t t = 0; t < NUM_THREADS; ++t)
    {
        pthread_join(threads[t], NULL);
    }

    float result = 0.0F;

    for (uint32_t t = 0; t < NUM_THREADS; ++t)
    {
        result += sums[t];
    }

    return result;
}

int main()
{
    float *arr = (float *)malloc(LENGTH * sizeof(float));

    for (size_t i = 0; i < LENGTH; i++)
    {
        if ((i % 2) == 0)
        {
            arr[i] = 1.0F;
        }
        else
        {
            arr[i] = -1.0F;
        }
    }

    double total_time = 0.0;

#ifdef TEST_SERIAL
    for (uint32_t run_idx = 0; run_idx < NUM_RUNS; run_idx++)
    {
        cpptiming::Timer t2;
        volatile float sum = serial_sum(arr, LENGTH);
        total_time += t2.elapsed_time<cpptiming::microsecs, double>();

#ifndef NDEBUG
        assert(sum == 0.0F);
#else
        (void)sum;
#endif
    }

    printf("Serial - Mean execution time: %.2lf us\n", total_time / (double)(NUM_RUNS));
#endif

    total_time = 0.0;

    for (uint32_t run_idx = 0; run_idx < NUM_RUNS; run_idx++)
    {
        cpptiming::Timer t2;
        volatile float sum = parallel_sum(arr, LENGTH);
        total_time += t2.elapsed_time<cpptiming::microsecs, double>();

#ifndef NDEBUG
        assert(sum == 0.0F);
#else
        (void)sum;
#endif
    }

    printf("Parallel - Mean execution time: %.2lf us\n", total_time / (double)(NUM_RUNS));

    return 0;
}
