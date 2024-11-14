#include "finmath/Regression/OLS.h"
#include <gtest/gtest.h>
#include <vector>
#include <cmath>

// Helper function to compare floating-point numbers
bool approximatelyEqual(double a, double b, double epsilon = 1e-9) {
    return std::fabs(a - b) < epsilon;
}

// Test initialization and coefficient calculation
TEST(OLS, CoefficientCalculation) {
    std::vector<std::vector<double>> X = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}};
    std::vector<double> y = {3, 5, 7, 9, 11};

    OLS model(X, y);

    std::vector<double> coefficients = model.get_coefficients();
    double intercept = model.get_intercept();

    // Expected values
    double expected_intercept = 1.0;
    std::vector<double> expected_coefficients = {1.0, 1.0};

    EXPECT_TRUE(approximatelyEqual(intercept, expected_intercept));
    ASSERT_EQ(coefficients.size(), expected_coefficients.size());
    for (size_t i = 0; i < coefficients.size(); ++i) {
        EXPECT_TRUE(approximatelyEqual(coefficients[i], expected_coefficients[i]));
    }
}

// Test prediction functionality
TEST(OLS, Prediction) {
    std::vector<std::vector<double>> X = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}};
    std::vector<double> y = {3, 5, 7, 9, 11};

    OLS model(X, y);

    // Predict for new values
    std::vector<std::vector<double>> new_X = {{6, 7}, {7, 8}};
    std::vector<double> predictions = model.predict(new_X);

    // Expected predictions
    std::vector<double> expected_predictions = {13.0, 15.0};

    ASSERT_EQ(predictions.size(), expected_predictions.size());
    for (size_t i = 0; i < predictions.size(); ++i) {
        EXPECT_TRUE(approximatelyEqual(predictions[i], expected_predictions[i]));
    }
}


