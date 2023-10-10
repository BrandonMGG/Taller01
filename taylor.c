#include <stdio.h>
#include <omp.h>

static long num_terms = 10000000;
double x = 1.0;
double factorial = 1.0;
double result = 1.0;
static double reference_e = 2.71828182845904523536028747;
double error;
int main () {
    double sum = 1.0;
    double start_time, run_time;
    int max_threads = omp_get_max_threads();

    for (int i = 1; i <= max_threads; i++) {
        sum = 1.0;
        omp_set_num_threads(i);

        start_time = omp_get_wtime();
#pragma omp parallel
        {
            double local_sum = 0.0;
            double local_term = 1.0;
    #pragma omp single
            printf("num_threads = %d ",omp_get_num_threads());

#pragma omp for
            for (int j = 1; j <= num_terms; j++) {
                local_term *= x / j;
                local_sum += local_term;
            }

#pragma omp atomic
            sum += local_sum;
        }
        error = (sum-reference_e)*100/reference_e;
        run_time = omp_get_wtime() - start_time;
        printf("computed e = %3.15f in %3.30f seconds threads %d %% error = %3.15f \n", sum, run_time, i, error);
    }

    return 0;
}
