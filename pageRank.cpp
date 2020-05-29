#include <iostream>
#include<vector> 
#include <math.h>
#include "pageRank.hpp"



// initialization of the dominant eigenvector. 

void initialize_b(std::vector<double>& b, int n){
	for(int i= 0; i < n; i++){
		b.push_back(1.0); 
	}
}




// Computes a step in the power iteration method.

bool step(CSRMatrix A, std::vector<double>& b, double epsilon, double beta){
	int n = b.size();
	std::vector<double> b_t(n);
	b_t = b; 
	double value; 
	bool converge = true; 
	double max; 

	b[0] = A.scalar_product_csr(b_t, 0, beta); 

	max = b[0]; 

	for(int i = 1 ; i < n; i++){
		b[i] =  A.scalar_product_csr(b_t, i, beta);
		if(b[i] > max){
			max = b[i] ; 
		}
	}
	for (int i = 0; i< n; i++){
		b[i] = b[i]/max; 
		if(converge && abs(b[i]- b_t[i]) >= epsilon)
			converge = false; 
	}
	return converge; 

}

// It's computes the dominant eigenvector of a given Matrix A by using the power iteration method. 

void power_method(CSRMatrix A,std::vector<double>& b, double epsilon, double beta, int n){
	initialize_b(b, n);
	bool converge = false;
	int i = 0;
	while(!converge){
		converge = step(A,b, epsilon,beta) ; 
	}
}
