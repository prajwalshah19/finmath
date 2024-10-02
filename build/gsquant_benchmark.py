import pandas as pd
import timeit
import gs_quant.timeseries as ts
import finmath

# Example data for 1000 days
prices = pd.Series(ts.generate_series(1000))

# gs_quant implementation timing
def test_gs_quant():
    return ts.volatility(prices, ts.Window(22, 0))


# C++ implementation timing
def test_cpp_implementation():
    return finmath.rolling_volatility(prices.tolist(), 22)

# Number of executions for timing
executions = 100

# Compare execution times
gs_time = timeit.timeit(test_gs_quant, number=executions)
cpp_time = timeit.timeit(test_cpp_implementation, number=executions)
improvement_percentage = ((gs_time - cpp_time) / gs_time) * 100

print(f"gs_quant implementation: {gs_time:.6f} seconds")
print(f"C++ implementation: {cpp_time:.6f} seconds")
print(f"Performance improvement from using finmath: {improvement_percentage:.2f}%")
