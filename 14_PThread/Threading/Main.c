#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Serial: 9ms
 *      2: 4ms
 *      4: 3ms
 *      6: 2ms
 *      8: 1ms
 */
#define USE_THREADING
#define NUM_THREADS (uint32_t)(8)
#define LENGTH (size_t)(1e07)
#ifndef NDEBUG
#define NUM_RUNS (uint32_t)(10)
#else
#define NUM_RUNS (uint32_t)(1e3)
#endif
// #define TEST_SERIAL

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
    const time_t start = time(NULL);
    for (uint32_t run_idx = 0; run_idx < NUM_RUNS; run_idx++)
    {
        volatile float sum = serial_sum(arr, LENGTH);
#ifndef NDEBUG
        assert(sum == 0.0F);
#else
        (void)sum;
#endif
    }
    const time_t end = time(NULL);
    total_time = (difftime(end, start) * 1000.0F) / (double)(NUM_RUNS);

    printf("Serial - Mean execution time: %.2lf ms\n", total_time);

    total_time = 0.0;
#endif

    const time_t start = time(NULL);
    for (uint32_t run_idx = 0; run_idx < NUM_RUNS; run_idx++)
    {
        volatile float sum = parallel_sum(arr, LENGTH);
#ifndef NDEBUG
        assert(sum == 0.0F);
#else
        (void)sum;
#endif
    }
    const time_t end = time(NULL);
    total_time = (difftime(end, start) * 1000.0F) / (double)(NUM_RUNS);

    printf("Parall - Mean execution time: %.2lf ms\n", total_time);

    free(arr);
    arr = NULL;

    return 0;
}
