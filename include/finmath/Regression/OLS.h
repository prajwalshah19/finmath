// OLS.h
#ifndef FINMATH_OLS_H
#define FINMATH_OLS_H

#include <vector>

class OLS {
public:
    OLS(const std::vector<std::vector<double>>& X, const std::vector<double>& y);
    std::vector<double> get_coefficients() const;
    double get_intercept() const;
    std::vector<double> predict(const std::vector<std::vector<double>>& X) const;

private:
    std::vector<double> coefficients;
    double intercept;
    void calculate_ols(const std::vector<std::vector<double>>& X, const std::vector<double>& y);
};

#endif // FINMATH_OLS_H
