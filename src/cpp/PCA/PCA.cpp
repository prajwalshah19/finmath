#include "finmath/PCA/pca.h"
#include <numeric>
#include <cmath>
#include <algorithm>
#include <iostream>

std::vector<double> compute_mean(const std::vector<std::vector<double>>& data) {
    int rows = data.size();
    int cols = data[0].size();
    std::vector<double> mean(cols, 0.0);

    for (const auto& row : data) {
        for (int j = 0; j < cols; ++j) {
            mean[j] += row[j];
        }
    }

    for (double& val : mean) {
        val /= rows;
    }

    return mean;
}

std::vector<std::vector<double>> center_data(const std::vector<std::vector<double>>& data, const std::vector<double>& mean) {
    std::vector<std::vector<double>> centered_data = data;

    for (auto& row : centered_data) {
        for (size_t j = 0; j < row.size(); ++j) {
            row[j] -= mean[j];
        }
    }

    return centered_data;
}

std::vector<std::vector<double>> compute_covariance_matrix(const std::vector<std::vector<double>>& data) {
    int rows = data.size();
    int cols = data[0].size();

    std::vector<std::vector<double>> cov_matrix(cols, std::vector<double>(cols, 0.0));

    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < cols; ++j) {
            for (int k = 0; k < rows; ++k) {
                cov_matrix[i][j] += data[k][i] * data[k][j];
            }
            cov_matrix[i][j] /= (rows - 1);
        }
    }

    return cov_matrix;
}

void compute_eigen(const std::vector<std::vector<double>>& cov_matrix, std::vector<double>& eigenvalues, std::vector<std::vector<double>>& eigenvectors) {
    std::cerr << "Eigenvalue decomposition is not implemented. Please use an external library like Eigen or LAPACK.\n";
}

std::vector<std::vector<double>> perform_pca(const std::vector<std::vector<double>>& data, int num_components) {
    std::vector<double> mean = compute_mean(data);
    std::vector<std::vector<double>> centered_data = center_data(data, mean);

    std::vector<std::vector<double>> cov_matrix = compute_covariance_matrix(centered_data);

    std::vector<double> eigenvalues;
    std::vector<std::vector<double>> eigenvectors;
    compute_eigen(cov_matrix, eigenvalues, eigenvectors);

    std::cerr << "PCA transformation is not fully implemented. Use external libraries for eigenvalue decomposition and transformation.\n";

    return centered_data;
}
