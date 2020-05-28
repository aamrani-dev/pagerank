#include "CSR.hpp"
#include <iostream>
#include <vector>


CSRMatrix::CSRMatrix(std::vector<std::vector<double>> sparseMatrix, int n){
	rows.push_back(0); 
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(sparseMatrix[i][j]!=0){
				values.push_back(sparseMatrix[i][j]); 
				columns.push_back(j); 
			}
		}
		rows.push_back(columns.size()); 
	}
} 

int CSRMatrix::nb_nonzeros(int row_index){
	return this->rows[row_index+1] - this->rows[row_index]; 
}


double CSRMatrix::get_value(int value_index){
	return this->values[value_index]; 
}

int CSRMatrix::get_column(int value_index){
	return this->columns[value_index]; 
} 

void CSRMatrix::print_matrix(){
	std::cout << "values: [ " ; 
	for(int i = 0; i < values.size(); i++)
		std::cout << values[i] << " " ; 
	std::cout << "]" << std::endl; 
	
	std::cout << "columns: [ " ;
	for(int i = 0; i < columns.size(); i++)
		std::cout << columns[i] << " " ; 
	std::cout << "]" << std::endl; 
	
	std::cout << "rows: [ " ; 
	for(int i = 0; i < rows.size(); i++)
		std::cout << rows[i] << " " ; 
	std::cout << "]" << std::endl; 				

} 	

double CSRMatrix::scalar_product_csr(std::vector<double> v, int row, int& value_index, double beta){
	int n = v.size(); 
	int nb_nonzeros = this->nb_nonzeros(row);
	double sum=0.0;  
	for(int j = 0; j < n; j++){
		if(columns[value_index] != j){
			sum+= (1-beta)/n * v[j]; 
		}
		else{
			sum += (beta*values[value_index] + (1-beta)/n)* v[columns[value_index]];
			value_index++;  
		}
	}
	return sum;	
}