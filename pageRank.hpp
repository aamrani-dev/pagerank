#ifndef PAGERANK_HPP
#define PAGERANK_HPP

#include <vector>
#include <iostream>
#include "CSR.hpp"


std::vector<double> spmv_csr_product(CSRMatrix A, std::vector<double> v); 
void initialize_b(std::vector<double>& b, int n); 
double scalar_product(std::vector<double> u, std::vector<double> v); 
bool step(CSRMatrix A, std::vector<double>& b, double epsilon);
void power_method(CSRMatrix A,std::vector<double>& b, double epsilon, double beta, int n);
// double scalar_product_csr(CSRMatrix A, std::vector<double> v, int row, int& value_index, double beta);


#endif
