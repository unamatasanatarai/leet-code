#ifndef BENCHMARKING
#define BENCHMARKING

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static inline uint64_t rdtsc(void) {
    unsigned int lo, hi;
    __asm__ volatile ("rdtsc" : "=a"(lo), "=d"(hi));
    return ((uint64_t)hi << 32) | lo;
}

static int cmp_u64(const void *a, const void *b) {
    uint64_t x = *(const uint64_t *)a;
    uint64_t y = *(const uint64_t *)b;
    return (x > y) - (x < y);
}

void analyze_ticks(uint64_t ticks[], size_t n) {
    if (n == 0) return;

    // Sort (modifies array)
    qsort(ticks, n, sizeof(uint64_t), cmp_u64);

    uint64_t min = ticks[0];
    uint64_t max = ticks[n - 1];

    double sum = 0.0;
    for (size_t i = 0; i < n; i++)
        sum += ticks[i];
    double mean = sum / n;

    double median;
    if (n % 2 == 0)
        median = (ticks[n/2 - 1] + ticks[n/2]) / 2.0;
    else
        median = ticks[n/2];

    // 5% trimmed mean
    size_t trim = n / 20;
    double t_sum = 0.0;
    for (size_t i = trim; i < n - trim; i++)
        t_sum += ticks[i];
    double trimmed_mean = t_sum / (n - 2 * trim);

    printf("Samples:        %zu\n", n);
    printf("Min ticks:      %llu\n", (unsigned long long)min);
    printf("Max ticks:      %llu\n", (unsigned long long)max);
    printf("Mean:           %.2f\n", mean);
    printf("Median:         %.2f\n", median);
    printf("Trimmed mean:   %.2f\n", trimmed_mean);
}

#endif
