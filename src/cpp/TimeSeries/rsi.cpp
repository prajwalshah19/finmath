#include "finmath/TimeSeries/rsi.h"

#include<numeric>
#include<cmath>
#include<algorithm>

double compute_avg_gain(const std::vector<double>& price_changes, size_t window_size)
{
    double total_gain = 0.0;

    for(double change : price_changes)
    {
        if(change > 0)
        {
            total_gain += change;
        }
    }
    return total_gain / window_size;
}

double compute_avg_loss(const std::vector<double>& price_changes, size_t window_size)
{
    double total_loss = 0.0;

    for(double change : price_changes)
    {
        if(change < 0)
        {
            total_loss += std::abs(change);
        }
    }
    return total_loss / window_size;
}

std::vector<double> compute_rsi(const std::vector<double>& prices, size_t window_size)
{
    std::vector<double> rsi_values; 
    std::vector<double> price_changes;

    for(size_t i = 1; i < prices.size(); i++)
    {
        price_changes.push_back(prices[i] - prices[i-1]);
    }

    double avg_gain = compute_avg_gain(price_changes, window_size);
    double avg_loss = compute_avg_loss(price_changes, window_size);

    double rs = (avg_loss == 0) ? 0 : avg_gain / avg_loss;  // Avoid division by zero;

    double rsi = 100.0 - (100.0 / (1.0 + rs));
    rsi_values.push_back(rsi);

    for(size_t i = 0; i < price_changes.size(); i++)
    {
        double change = price_changes[i];
        avg_gain = (avg_gain * (window_size - 1)) + (change > 0 ? change : 0) / window_size;
        avg_loss = (avg_loss * (window_size - 1)) + (change < 0 ? std::abs(change) : 0) / window_size;

        rs = (avg_loss == 0) ? 0 : avg_gain / avg_loss;  // Avoid division by zero
        rsi = (avg_loss == 0) ? 100.0 : 100.0 - (100.0 / (1.0 + rs));
        rsi_values.push_back(rsi);
    }

    return rsi_values;
}