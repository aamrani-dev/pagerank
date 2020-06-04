compiler = mpic++
run = mpirun
nb_proc = 4
all: CSR.o main.o pageRank.o
	$(compiler) -o pagerank CSR.o main.o pageRank.o
CSR.o: CSR.cpp
	$(compiler) -c CSR.cpp 
pageRank.o: pageRank.cpp
	$(compiler) -c pageRank.cpp
main.o: main.cpp 
	$(compiler) -c main.cpp
run:
	$(run) -n $(nb_proc) ./pagerank 4 4
clean:
	rm CSR.o main.o pageRank.o pagerank 