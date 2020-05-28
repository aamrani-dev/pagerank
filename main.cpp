#include "pageRank.hpp"
using namespace std; 


int main(){
	int n = 4; 
	double beta = 1.0; 
	double epsilon = 0.001; 
	std::vector<std::vector<double>> A{ {11, 12, 0, 2},
										{0, 6, 0, 8}, 
										 {0, 0, 0, 3},
										 {13, 0, 14, 16}
										};

	CSRMatrix csr = CSRMatrix(A, n); 
	csr.print_matrix(); 
	std::vector<double> v;
	power_method(csr, v, epsilon, beta, n); 
	for(int i = 0; i < 4; i++){
		std::cout << v[i] << " "; 
	}
	std::cout << std::endl; 
}