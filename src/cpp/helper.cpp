#include <cmath>
#include "finmath/helper.h"


// Standard normal cumulative distribution function
double normal_cdf(double x) {
    return 0.5 * std::erfc(-x / std::sqrt(2));
}

// Standard normal probability density function
double normal_pdf(double x) {
    return std::exp(-0.5 * x * x) / std::sqrt(2 * M_PI);
}
