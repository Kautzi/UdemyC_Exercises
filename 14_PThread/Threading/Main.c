#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Matrix.h"
#include "Timer.h"
#include "Vector.h"

int main()
{
    Vector *v1 = createVector(16384, +1.0f);
    Vector *v2 = createVector(16384, +1.0f);

    double total_time = 0.0;
    uint32_t num_runs = 100000;

    // for (uint32_t run_idx = 0; run_idx < num_runs; run_idx++)
    // {
    //     const clock_t time_start = clock();
    //     Vector *v3 = addVector(v1, v2);
    //     const clock_t time_end = clock();

    //     total_time += get_timing_nanoseconds(&time_start, &time_end);
    //     freeVector(v3);
    // }

    // printf("Serial - Mean execution time: %.2lf ns\n", total_time / (double)(num_runs));

    total_time = 0.0;
    num_runs = 100000;

    for (uint32_t run_idx = 0; run_idx < num_runs; run_idx++)
    {
        const clock_t time_start = clock();
        Vector *v3 = addVectorParallel(v1, v2);
        const clock_t time_end = clock();

        total_time += get_timing_nanoseconds(&time_start, &time_end);
        freeVector(v3);
    }

    printf("Parallel - Mean execution time: %.2lf ns\n", total_time / (double)(num_runs));

    freeVector(v1);
    freeVector(v2);

    return 0;
}
