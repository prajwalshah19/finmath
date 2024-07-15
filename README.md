# finmath
Financial Math Library Written in C and C++. The eventual goal is to write Python binds to use this library in Python. Pull requests are welcome

## Currently Implemented Functions

1. Compound Interest

```
double compound_interest(double principal, double rate, int time, int frequency);
```

2. Black Scholes

```
double black_scholes(OptionType type, double strike, double price, double time, double rate, double volatility);
```

3. Binomial Tree

```
double binomial_option_pricing(OptionType type, double S0, double K, double T, double r, double sigma, int N);
```
