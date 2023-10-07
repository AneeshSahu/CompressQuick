all: compress.o
	g++ main.cpp compress.o -o compress 

compress.o: compress.cpp compress.h
	g++ -c compress.cpp 

run: 
	./compress

clean:
	rm -rf compress  compress.o
