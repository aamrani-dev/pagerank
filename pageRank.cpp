#include <iostream>
#include<vector> 
#include <math.h>
#include "pageRank.hpp"

using namespace std; 

// initialization of the dominant eigenvector. 

void initialize_b(std::vector<double>& b){
	int size = b.size(); 
	for(int i= 0; i < size; i++){
		b[i] = 1.0; 
	}
}


// Computes a step in the power iteration method.
std::vector<int> rows_set(int n){
	std::vector<int> v;
	for(int i = 0; i < n; i++)
		v.push_back(i); 
	return v; 
}
bool step(CSRMatrix A, std::vector<double>& b, double epsilon, double beta){
	int proc_rank = MPI::COMM_WORLD.Get_rank();
	int nrows = A.get_nrows();

	bool converge = true;
	int n = b.size();  
	
	std::vector<double> b_t;
	b_t.resize(n); 
	b_t = b;

	std::vector<double> sub_b; 
	sub_b.resize(nrows); 
  
	double global_max;
	double local_max; 

	for(int i = 0 ; i < nrows; i++){
		sub_b[i] =  A.scalar_product_csr(b,i,beta);
	}

	MPI::COMM_WORLD.Allgather(&sub_b[0], nrows, MPI::DOUBLE, &b[0], nrows, MPI::DOUBLE); 

	local_max  = sub_b[0]; 
	for(int i =  0; i < nrows; i++){
		if(local_max < sub_b[i])
			local_max = sub_b[i] ; 
	}

	MPI::COMM_WORLD.Allreduce(&local_max, &global_max, 1, MPI::DOUBLE, MPI::MAX); 


	for (int i = 0; i< n; i++){
		b[i] = b[i]/global_max; 
		if(converge && abs(b[i]- b_t[i]) >= epsilon){
			converge = false; 
		}
	}		

	return converge; 

}

// It computes the dominant eigenvector of a given Matrix A by using the power iteration method. 

void power_method(CSRMatrix A,std::vector<double>& b, double epsilon, double beta){
	initialize_b(b);
	bool converge = false;
	while(!converge ){
		converge = step(A, b, epsilon, beta) ; 
	}
}