#ifndef HELPER_H
#define HELPER_H

#include <vector>
using namespace std;

double stdev(const vector<double>& x);
vector<double> standardize(const vector<double>& X);

double normal_cdf(double x);
double normal_pdf(double x);
double combinations(int n, int k);

#endif