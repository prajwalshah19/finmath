#include "finmath/Regression/OLS.h"
#include <vector>
#include <Eigen/Dense>

OLS::OLS(const std::vector<std::vector<double>>& X, const std::vector<double>& y) {
    calculate_ols(X, y);
}

void OLS::calculate_ols(const std::vector<std::vector<double>>& X, const std::vector<double>& y) {
    size_t n = X.size();    // Number of observations
    size_t m = X[0].size(); // Number of predictors

    // Create Eigen matrices and vectors
    Eigen::MatrixXd X_eigen(n, m + 1);
    Eigen::VectorXd y_eigen(n);

    for (size_t i = 0; i < n; ++i) {
        X_eigen(i, 0) = 1.0;
        for (size_t j = 0; j < m; ++j) {
            X_eigen(i, j + 1) = X[i][j];
        }
        y_eigen(i) = y[i];
    }

    // Calculate (X^T * X)^(-1) * X^T * y
    Eigen::VectorXd coeffs = (X_eigen.transpose() * X_eigen).ldlt().solve(X_eigen.transpose() * y_eigen);

    intercept = coeffs(0);
    coefficients = std::vector<double>(coeffs.data() + 1, coeffs.data() + coeffs.size());
}

std::vector<double> OLS::get_coefficients() const {
    return coefficients;
}
double OLS::get_intercept() const {
    return intercept;
}

std::vector<double> OLS::predict(const std::vector<std::vector<double>>& X) const {
    std::vector<double> predictions;
    for (const auto& x : X) {
        double prediction = intercept;
        for (size_t i = 0; i < x.size(); ++i) {
            prediction += x[i] * coefficients[i];
        }
        predictions.push_back(prediction);
    }
    return predictions;
}
