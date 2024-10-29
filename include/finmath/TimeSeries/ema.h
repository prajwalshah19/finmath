#ifndef EMA_H
#define EMA_H

#include<vector>

// Function to compute the Exponential Moving Average (EMA)
std::vector<double> compute_ema(const std::vector<double>& prices, size_t window);

#endif