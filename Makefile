all: CSR.o main.o pageRank.o
	g++ -o pagerank CSR.o main.o pageRank.o
CSR.o: CSR.cpp
	g++ -c CSR.cpp 
pageRank.o: pageRank.cpp
	g++ -c pageRank.cpp
main.o: main.cpp 
	g++ -c main.cpp
run:
	./pagerank
clean:
	rm CSR.o main.o pageRank.o pagerank 