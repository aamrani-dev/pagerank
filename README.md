# Pagerank implementation using MPI 

This project consits on implementing the pageRank algorithm using the dumping factor. This version is applied to dense matrix by storing the matrix in a CSR matrix. MPI is also used to distribute computations among the differents computers that can be used. 

## Getting Started

Clone the project on your own computer by using git clone command. 

git clone https://github.com/aamrani-dev/pagerank.git

## Prerequisites 

All what you need to compile and run the projet, you need to install first MPICH. A greate tutorial is made by [wesleykendall](https://github.com/wesleykendall/). Follow this [link](https://mpitutorial.com/tutorials/installing-mpich2/) to go to the tutorial page. 

## Compiling and running the tests

First off, store you n * n martix row by row spacing the columns with blank spaces in a file named **data.text**. 

For example for a 3 * 3 matrix the file **data.txt** will looks like: 

1 2 3 
4 5 6
7 8 9 

To compile and run the projetct, a Makefile is provided.

### Compile 

make 

### Run 

make run -np nb_proc=number_of_procs size=n 

where number_of_procs is the number of processors that you would like to use and size the size of the input matrix.





##