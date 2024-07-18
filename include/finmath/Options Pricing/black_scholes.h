#ifndef BLACK_SCHOLES_H
#define BLACK_SCHOLES_H

enum class OptionType {CALL, PUT};

double black_scholes(OptionType type, double strike, double price, double time, double rate, double volatility);

#endif