// https://www.itl.nist.gov/div898/handbook/eda/section3/eda35c.htm
// https://medium.com/@krzysztofdrelczuk/acf-autocorrelation-function-simple-explanation-with-python-example-492484c32711

// takes in 2 vectors<double> for measurement and time, and lag
// returns a list of lag at each

// max lag returns the first

#include "finmath/TimeSeries/autocorrelation.h"

#include <vector>
#include <iostream>
#include <cmath>
#include <numeric>

using namespace std;

vector<double> autocorrelation(std::vector<double> &values, double max_lag) {
    if (values == null) {
        std::cerr << "Values cannot be null." << std::endl;
        return null;
    }

    if (max_lag < 0) {
        std::cerr << "mag_lag must be greater than 0." << std::endl;
        return null;
    }

    int n = values.size();

    if (max_lag >= n) {
        std::cerr << "mag_lag must be less than size of datapoints" << std::endl;
        return null;
    }

    std::Vector<double> result(max_lag+1, 0.0);


    double mean = std::accumulate(values.begin(), values.end(), 0.0) / n;

    double variance = 0.0;
    for (const auto& value: values) {
        variance += (value - mean) * (value - mean);
    }

    if (variance == 0.0) {
        std::cerr << "Variance is zero; autocorrelation cannot be computed." << std::endl;
        return {};
    }

    for (int lag = 0; lag <= max_lag; lag++) {
        double cov = 0.0;
        for (int i = 0; i < n - lag; i++) {
            cov += (values[i] - mean) * (values[i+lag] - mean)
        }
        result[lag] = cov/variance;
    }


    return result;
}

// TODO: update to use FFT
std::vector<double> autocorrelation_irregular(const std::vector<double>&values, const std::vector<double>& times, double max_lag, double step_size) {
    if (values.empty() || times.empty()) {
        std::cerr << "Values and times cannot be empty." << std::endl;
        return {};
    }

    if (values.size() != times.size()) {
        std::cerr << "Values and times must have the same size." << std::endl;
        return {};
    }

    if (max_lag < 0 || step_size <= 0) {
        std::cerr << "max_lag must be greater than 0 and step_size must be positive." << std::endl;
        return {};
    }

    std::vector<double> result;

    // Calculate mean
    double mean = std::accumulate(values.begin(), values.end(), 0.0) / values.size();

    // Calculate variance
    double variance = 0.0;
    for (const auto& value : values) {
        variance += (value - mean) * (value - mean);
    }

    if (variance == 0.0) {
        std::cerr << "Variance is zero; autocorrelation cannot be computed." << std::endl;
        return {};
    }

    // Compute autocorrelation for each time lag
    for (double lag = 0.0; lag <= max_lag; lag += step_size) {
        double cov = 0.0;
        double weight_sum = 0.0;

        for (size_t i = 0; i < times.size(); ++i) {
            for (size_t j = 0; j < times.size(); ++j) {
                double time_diff = std::abs(times[i] - times[j]);
                if (std::abs(time_diff - lag) <= step_size / 2.0) {
                    cov += (values[i] - mean) * (values[j] - mean);
                    weight_sum += 1.0;
                }
            }
        }

        if (weight_sum > 0) {
            result.push_back(cov / (variance * weight_sum));
        } else {
            result.push_back(0.0);  // No matching pairs for this lag
        }
    }

    return result;
}


