#include <cmath>
#include <algorithm>
#include <vector>
#include "finmath/Option Pricing/binomial_tree.h"
#include "finmath/Helper/helper.h"

double binomial_option_pricing(OptionType type, double S0, double K, double T, double r, double sigma, int N) {
    double dt = T / N;
    double u = std::exp(sigma * std::sqrt(dt));
    double d = std::exp(-sigma * std::sqrt(dt));
    double p = (std::exp(r * dt) - d) / (u - d);
    double value = 0.0;

    for (int i = 0; i <= N; ++i) {
        double node_prob = combinations(N, i) * std::pow(p, i) * std::pow(1 - p, N - i);
        double ST = S0 * std::pow(u, i) * std::pow(d, N - i);

        if (type == OptionType::CALL) {
            value += std::max(ST - K, 0.0) * node_prob;
        } else if (type == OptionType::PUT) {
            value += std::max(K - ST, 0.0) * node_prob;
        }
    }

    return value * std::exp(-r * T);
}
