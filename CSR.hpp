#ifndef CSR__HPP
#define CSR_HPP
#include <vector>

class CSRMatrix{
private:
	std::vector<double> values;
	std::vector<int> columns;
	std::vector<int> rows;
	int nb_nonzeros(int row_index); 
	double get_value(int value_index);
	int get_column(int value_index);	
public:
	CSRMatrix(std::vector<std::vector<double>> sparseMatrix, int n); 
	void print_matrix();   
	double scalar_product_csr(std::vector<double> v, int row, double beta); 
}; 


#endif