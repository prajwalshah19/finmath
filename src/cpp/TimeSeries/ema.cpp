#include "finmath/TimeSeries/ema.h"

std::vector<double> compute_ema(const std::vector<double>& prices, size_t window)
{
    std::vector<double> ema(prices.size(), 0.0);
    double multiplier = 2.0 / (window + 1);

    ema[0] = prices[0];

    for(size_t i = 1; i < prices.size(); i++)
    {
        ema[i] = ((prices[i] - ema[i - 1]) * multiplier) + ema[i - 1];
    }

    return ema;

}
