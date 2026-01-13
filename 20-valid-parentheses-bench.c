#define MAIN_BENCH
#include "benchmarking.c"
#include "20-valid-parentheses.c"

int main(void)
{
    unsigned int n_tests = 1000000;
    unsigned int i = 0;
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
