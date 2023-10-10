#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000
#define MAX_THREADS 8
#define NUM_ITERATIONS 10

int main() {

    int i, j, nthreads;
    double *x, *y, *z;
    double alpha = 2.0;
    double beta = 3.0;
    double *start_time, *end_time;


    const int cache_line_size = 64;

    x = (double *)malloc(N * sizeof(double));
    y = (double *)malloc(N * sizeof(double));
    z = (double *)malloc(N * sizeof(double));


    for (i = 0; i < N; i++) {
        x[i] = rand() / (double)RAND_MAX;
        y[i] = rand() / (double)RAND_MAX;
    }

    for (nthreads = 1; nthreads <= MAX_THREADS; nthreads++) {

        start_time = (double *)malloc(NUM_ITERATIONS * sizeof(double));
        end_time = (double *)malloc(NUM_ITERATIONS * sizeof(double));

        for (j = 0; j < NUM_ITERATIONS; j++) {

            start_time[j] = omp_get_wtime();
#pragma omp parallel for num_threads(nthreads)
            for (i = 0; i < N; i++) {
                z[i] = alpha * x[i] + beta * y[i];
            }

            end_time[j] = omp_get_wtime();
        }

        double avg_time = 0.0;
        for (j = 0; j < NUM_ITERATIONS; j++) {
            avg_time += (end_time[j] - start_time[j]);
        }
        avg_time /= NUM_ITERATIONS;

        printf("num_threads = %d in %3.15f seconds\n", nthreads, avg_time);

        free(start_time);
        free(end_time);
    }

    free(x);
    free(y);
    free(z);

    return 0;
}