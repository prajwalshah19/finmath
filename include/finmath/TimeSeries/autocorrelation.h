#ifndef FINMATH_AUTOCORRELATION_H
#define FINMATH_AUTOCORRELATION_H

#include <vector>

// Function to compute autocorrelation given values, and max lag (assumes times associated with values are in consistent time intervals)
std::vector<double> autocorrelation(std::vector<double> &values, double max_lag);


// Function to compute autocorrelation given values, times, max_lag, and step_size of lag

std::vector<double> autocorrelation_irregular(const std::vector<double>&values, const std::vector<double>& times, double max_lag, double step_size);
#endif //FINMATH_AUTOCORRELATION_H
