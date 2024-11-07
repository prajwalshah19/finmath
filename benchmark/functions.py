import numpy as np
from scipy.special import comb  # For combinations
from scipy.stats import norm  # For normal distribution CDF

def compound_interest(principal, rate, time, frequency):
    if time < 0:
        return 0.0
    return principal * np.power((1 + rate / (100 * frequency)), time * frequency)


class OptionType:
    CALL = 1
    PUT = 2

def binomial_option_pricing(option_type, S0, K, T, r, sigma, N):
    dt = T / N
    u = np.exp(sigma * np.sqrt(dt))
    d = np.exp(-sigma * np.sqrt(dt))
    p = (np.exp(r * dt) - d) / (u - d)
    value = 0.0

    for i in range(N + 1):
        # Node probability
        node_prob = comb(N, i) * (p ** i) * ((1 - p) ** (N - i))
        # Stock price at node
        ST = S0 * (u ** i) * (d ** (N - i))

        if option_type == OptionType.CALL:
            value += np.maximum(ST - K, 0.0) * node_prob
        elif option_type == OptionType.PUT:
            value += np.maximum(K - ST, 0.0) * node_prob

    return value * np.exp(-r * T)


def black_scholes(option_type, strike, price, time, rate, volatility):
    d1 = (np.log(price / strike) + 0.5 * ((rate + np.power(volatility, 2)) * time)) / (volatility * np.sqrt(time))
    d2 = d1 - (volatility * np.sqrt(time))

    if option_type == OptionType.CALL:
        return price * norm.cdf(d1) - strike * np.exp(-rate * time) * norm.cdf(d2)
    else:
        return strike * np.exp(-rate * time) * norm.cdf(-d2) - price * norm.cdf(-d1)

