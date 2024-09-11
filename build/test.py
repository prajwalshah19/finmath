import finmath_bindings as finmath

# Test compound interest function
ci = finmath.compound_interest(1000, 0.05, 10, 4)
print("Compound Interest:", ci)

# Test Black-Scholes function with CALL option
# Use finmath.OptionType.CALL instead of 0
bs = finmath.black_scholes(finmath.OptionType.CALL, 100, 95, 1, 0.05, 0.2)
print("Black Scholes Price (CALL):", bs)

# Test Binomial Option Pricing with PUT option
bp = finmath.binomial_option_pricing(finmath.OptionType.PUT, 100, 95, 1, 0.05, 0.2, 100)
print("Binomial Option Price (PUT):", bp)
