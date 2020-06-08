#include "pageRank.hpp"
using namespace std; 


int main(int argc, char *argv[]){
	MPI_Init(&argc, &argv); 
	MPI::Status status; 

	int nrows = atoi(argv[1]);
	int ncols = atoi(argv[2]);

	double beta = 0.85; 
	double epsilon = 0.0001; 
	
	int proc_rank = MPI::COMM_WORLD.Get_rank(); 
	int nb_procs = MPI::COMM_WORLD.Get_size(); 
	int rows_per_proc = nrows / nb_procs;
	int start_position = rows_per_proc * proc_rank; 
	int remaining_rows = nrows % nb_procs;  
	
	if(remaining_rows > 0){
		if(proc_rank == 0 || proc_rank < remaining_rows){
			rows_per_proc += 1;
			if(proc_rank != 0)
				start_position += proc_rank - 1;	
		}
		else{
			start_position += remaining_rows;
		} 		
	}	

    std::vector<std::vector<double> >data;
    std::ifstream file("data.txt");
    int current_row = 0; 
    std::string  line;
    while(current_row < start_position ){
    	std::getline(file,line);
    	current_row++; 
    }
    for(int i = 0; i <rows_per_proc; i++){
    	std::getline(file,line);
        std::vector<double> lineData;
        std::stringstream lineStream(line);

        double value;
        while(lineStream >> value)
        {
            lineData.push_back(value);
        }

        data.push_back(lineData);    	
    }


    CSRMatrix csr(data, rows_per_proc, 4); 	
	std::vector<double> v;
	v.resize(4); 
	power_method(csr, v, epsilon, beta); 

	if(MPI::COMM_WORLD.Get_rank() == 0){
		std::cout << std::endl << "SOLUTION: [ " ; 
		for(int i = 0; i < 4; i++){
			std::cout << v[i] << " "; 
		}	
		std::cout << "]" << std::endl; 		
	}
	MPI_Finalize(); 
}