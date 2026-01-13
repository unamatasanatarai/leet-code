#define MAIN_BENCH
#include "benchmarking.c"
#include "20-valid-parentheses.c"
/*
 * Min ticks:      80
 * Max ticks:      1775
 * Mean:           123.64
 * Median:         97.00
 * Trimmed mean:   111.61
 */
int main(void)
{
    int n_tests = 1000;
    int i = 0;
    unsigned long long rdtscs[n_tests];

    while (i < n_tests)
    {
        uint64_t start = rdtsc();
        isValid("{({({({({({[[[[[]]]]))");
        uint64_t end = rdtsc();
        rdtscs[i] = (unsigned long long)(end - start);
        i++;
    }

    analyze_ticks(rdtscs, n_tests);

    return 0;
}
