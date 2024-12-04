#ifndef PCA_H
#define PCA_H

#include <vector>

std::vector<double> compute_mean(const std::vector<std::vector<double>>& data);

std::vector<std::vector<double>> center_data(const std::vector<std::vector<double>>& data, const std::vector<double>& mean);

std::vector<std::vector<double>> compute_covariance_matrix(const std::vector<std::vector<double>>& data);

void compute_eigen(const std::vector<std::vector<double>>& cov_matrix, std::vector<double>& eigenvalues, std::vector<std::vector<double>>& eigenvectors);

std::vector<std::vector<double>> perform_pca(const std::vector<std::vector<double>>& data, int num_components);

#endif
