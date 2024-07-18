#include <cmath>
#include "finmath/Helper/helper.h"


// Standard normal cumulative distribution function
double normal_cdf(double x) {
    return 0.5 * std::erfc(-x / std::sqrt(2));
}

// Standard normal probability density function
double normal_pdf(double x) {
    return std::exp(-0.5 * x * x) / std::sqrt(2 * M_PI);
}

// Function to compute combinations (n choose k)
double combinations(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    double c = 1;
    for (int i = 1; i <= k; ++i) {
        c *= (n - (k - i));
        c /= i;
    }
    return c;
}
