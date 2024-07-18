#ifndef BINOMIAL_TREE_H
#define BINOMIAL_TREE_H

enum class OptionType {CALL, PUT};

double binomial_option_pricing(OptionType type, double S0, double K, double T, double r, double sigma, int N);

#endif
