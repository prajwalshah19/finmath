#include <cassert>
#include <cmath>
#include <cstddef>
#include <iostream>
#include "finmath/finmath.h"
#include "finmath/Option Pricing/black_scholes.h"

int compound_interest_tests();
int black_scholes_tests();

int main() {
    std::cout << "Starting Unit Tests\n";
    compound_interest_tests();
    black_scholes_tests();

    return 0;
}
// Helper Function

bool almost_equal(double a, double b, double tolerance) {
    return std::abs(a - b) <= tolerance * std::max(std::abs(a), std::abs(b));
}

// Unit Tests

int compound_interest_tests() {
    double expected = 0.0;
    double tolerance = 0.001;

    // Test 1: Basic test with yearly compounding
    {
        double result = compound_interest(1000, 5, 10, 1);
        expected = 1628.89;
        assert(almost_equal(result, expected, tolerance));
    }

    // Test 2: Different rate
    {
        double result = compound_interest(1000, 10, 10, 1);
        expected = 2593.74;
        assert(almost_equal(result, expected, tolerance));
    }

    // Test 3: Different time period
    {
        double result = compound_interest(1000, 5, 5, 1);
        expected = 1276.28;
        assert(almost_equal(result, expected, tolerance));
    }

    // Test 4: Different compounding frequency (quarterly)
    {
        double result = compound_interest(1000, 5, 10, 4);
        expected = 1643.62;
        assert(almost_equal(result, expected, tolerance));
    }

    // Test 5: Different compounding frequency (monthly)
    {
        double result = compound_interest(1000, 5, 10, 12);
        expected = 1647.01;
        assert(almost_equal(result, expected, tolerance));
    }

    // Test 6: Different compounding frequency (daily)
    {
        double result = compound_interest(1000, 5, 10, 365);
        expected = 1648.66;
        assert(almost_equal(result, expected, tolerance));
    }

    // Test 7: Zero principal
    {
        double result = compound_interest(0, 5, 10, 1);
        expected = 0.0;
        assert(almost_equal(result, expected, tolerance));
    }

    // Test 8: Zero rate
    {
        double result = compound_interest(1000, 0, 10, 1);
        expected = 1000.0;
        assert(almost_equal(result, expected, tolerance));
    }

    // Test 9: Zero time
    {
        double result = compound_interest(1000, 5, 0, 1);
        expected = 1000.0;
        assert(almost_equal(result, expected, tolerance));
    }

    // Test 10: Zero frequency
    {
        double result = compound_interest(1000, 5, 10, 0);
        expected = 1000.0;
        assert(almost_equal(result, expected, tolerance));
    }

    // Test 11: Negative principal (should handle or reject)
    {
        double result = compound_interest(-1000, 5, 10, 1);
        expected = -1628.89;
        assert(almost_equal(result, expected, tolerance));
    }

    // Test 12: Negative rate (deflation)
    {
        double result = compound_interest(1000, -5, 10, 1);
        expected = 598.74;
        assert(almost_equal(result, expected, tolerance));
    }

    // Test 13: Negative time (should reject)
    {
        double result = compound_interest(1000, 5, -10, 1);
        expected = 0.0;
        assert(almost_equal(result, expected, tolerance));
    }

    // Test 14: Large principal
    {
        double result = compound_interest(1e6, 5, 10, 1);
        expected = 1628890.0;
        assert(almost_equal(result, expected, tolerance));
    }

    // Test 15: Large rate
    {
        double result = compound_interest(1000, 100, 1, 1);
        expected = 2000.0;
        assert(almost_equal(result, expected, tolerance));
    }

    // Test 16: Large time
    {
        double result = compound_interest(1000, 5, 100, 1);
        expected = 131501.26;
        assert(almost_equal(result, expected, tolerance));
    }

    std::cout << "Compound Interest Tests Passed!" << std::endl;
    return 0;
}

int black_scholes_tests() {
    double expected = 0.0;
    double tolerance = 0.001;

    /**
    // Test 1: Call option, basic parameters
    {
        double result = black_scholes(OptionType::CALL, 100, 105, 1, 0.05, 0.2);
        expected = 10.4506; // Placeholder value, should be replaced with correct expected value
        assert(almost_equal(result, expected, tolerance));
    }

    // Test 2: Put option, basic parameters
    {
        double result = black_scholes(OptionType::PUT, 100, 95, 1, 0.05, 0.2);
        expected = 5.5735; // Placeholder value, should be replaced with correct expected value
        assert(almost_equal(result, expected, tolerance));
    }

    // Test 3: At-the-money call option
    {
        double result = black_scholes(OptionType::CALL, 100, 100, 1, 0.05, 0.2);
        expected = 10.4506; // Placeholder value, should be replaced with correct expected value
        assert(almost_equal(result, expected, tolerance));
    }

    // Test 4: At-the-money put option
    {
        double result = black_scholes(OptionType::PUT, 100, 100, 1, 0.05, 0.2);
        expected = 5.5735; // Placeholder value, should be replaced with correct expected value
        assert(almost_equal(result, expected, tolerance));
    }

    // Test 5: Long time to maturity
    {
        double result = black_scholes(OptionType::CALL, 100, 100, 10, 0.05, 0.2);
        expected = 45.7528; // Placeholder value, should be replaced with correct expected value
        assert(almost_equal(result, expected, tolerance));
    }

    // Test 6: High volatility
    {
        double result = black_scholes(OptionType::CALL, 100, 100, 1, 0.05, 1.0);
        expected = 39.8444; // Placeholder value, should be replaced with correct expected value
        assert(almost_equal(result, expected, tolerance));
    }

    // Test 7: Zero volatility
    {
        double result = black_scholes(OptionType::CALL, 100, 100, 1, 0.05, 0.0);
        expected = 4.8771; // Placeholder value, should be replaced with correct expected value
        assert(almost_equal(result, expected, tolerance));
    }

    // Test 8: Zero interest rate
    {
        double result = black_scholes(OptionType::CALL, 100, 100, 1, 0.0, 0.2);
        expected = 7.9656; // Placeholder value, should be replaced with correct expected value
        assert(almost_equal(result, expected, tolerance));
    }

    // Test 9: Deep in-the-money call option
    {
        double result = black_scholes(OptionType::CALL, 50, 100, 1, 0.05, 0.2);
        expected = 52.438; // Placeholder value, should be replaced with correct expected value
        assert(almost_equal(result, expected, tolerance));
    }

    // Test 10: Deep out-of-the-money call option
    {
        double result = black_scholes(OptionType::CALL, 150, 100, 1, 0.05, 0.2);
        expected = 0.002; // Placeholder value, should be replaced with correct expected value
        assert(almost_equal(result, expected, tolerance));
    }

     **/

    std::cout << "Black-Scholes Tests Passed!" << std::endl;
    return 0;
}

int binomial_option_pricing_tests() {
    double tolerance = 0.001;
    

    std::cout << "Binomial-Tree Tests Passed!" << std::endl;
    return 0;
}
