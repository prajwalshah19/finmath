import timeit
import functions  # Import your Python functions
import finmath_bindings as finmath  # Import the C/C++ bindings from finmath

# Define test parameters
principal = 1000
rate = 5
time = 10
frequency = 4

strike = 95
price = 100
time_to_maturity = 1
rate_of_interest = 0.05
volatility = 0.2
option_type = finmath.OptionType.CALL
N = 1000

# Test cases for timing
def test_python_compound_interest():
    return functions.compound_interest(principal, rate, time, frequency)

def test_c_compound_interest():
    return finmath.compound_interest(principal, rate, time, frequency)

def test_python_black_scholes():
    return functions.black_scholes(functions.OptionType.CALL, strike, price, time_to_maturity, rate_of_interest, volatility)

def test_c_black_scholes():
    return finmath.black_scholes(finmath.OptionType.CALL, strike, price, time_to_maturity, rate_of_interest, volatility)

def test_python_binomial_tree():
    return functions.binomial_option_pricing(functions.OptionType.CALL, price, strike, time_to_maturity, rate_of_interest, volatility, N)

def test_c_binomial_tree():
    return finmath.binomial_option_pricing(finmath.OptionType.CALL, price, strike, time_to_maturity, rate_of_interest, volatility, N)

# Number of executions for accurate comparison
executions = 100

# Timing the compound interest function in Python
python_ci_time = timeit.timeit(test_python_compound_interest, number=executions)
print(f"Python compound_interest: {python_ci_time:.6f} seconds")

# Timing the compound interest function in C/C++ (finmath)
c_ci_time = timeit.timeit(test_c_compound_interest, number=executions)
print(f"C/C++ compound_interest (finmath): {c_ci_time:.6f} seconds")

# Calculate and print the performance improvement for compound interest
ci_improvement = ((python_ci_time - c_ci_time) / python_ci_time) * 100
print(f"Compound Interest Performance Improvement: {ci_improvement:.2f}%")

# Timing the Black-Scholes function in Python
python_bs_time = timeit.timeit(test_python_black_scholes, number=executions)
print(f"Python black_scholes: {python_bs_time:.6f} seconds")

# Timing the Black-Scholes function in C/C++ (finmath)
c_bs_time = timeit.timeit(test_c_black_scholes, number=executions)
print(f"C/C++ black_scholes (finmath): {c_bs_time:.6f} seconds")

# Calculate and print the performance improvement for Black-Scholes
bs_improvement = ((python_bs_time - c_bs_time) / python_bs_time) * 100
print(f"Black-Scholes Performance Improvement: {bs_improvement:.2f}%")

# Timing the binomial tree function in Python
python_binomial_time = timeit.timeit(test_python_binomial_tree, number=executions)
print(f"Python binomial_option_pricing: {python_binomial_time:.6f} seconds")

# Timing the binomial tree function in C/C++ (finmath)
c_binomial_time = timeit.timeit(test_c_binomial_tree, number=executions)
print(f"C/C++ binomial_option_pricing (finmath): {c_binomial_time:.6f} seconds")

# Calculate and print the performance improvement for Binomial Tree
binomial_improvement = ((python_binomial_time - c_binomial_time) / python_binomial_time) * 100
print(f"Binomial Tree Performance Improvement: {binomial_improvement:.2f}%")


