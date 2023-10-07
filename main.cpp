#include<iostream>
#include<unistd.h>
#include"compress.h"

int main(int argc, char** argv) {
	int opt;
	while((opt = getopt(argc, argv, "hcd")) != -1){
		switch(opt)
		{
			case 'h':
				std::cout << "Usage ./compress <options> <directory> " << std::endl
				<< "Options" << std::endl << "-c for compress " << std::endl 
				<< "-d for decompress" << std::endl;
				break;
			case 'c':
				std::cout << "Compress" << std::endl;
				if (argc != 3){
					return 1;
				}
				compress::entry(argv[2]);
				break;
			case 'd': 
				std::cout << "Decompress" << std::endl;
				break;
			default: 
				std::cout << "Unsupported!" << std::endl;
				return 1;
		}
	}
	return 0;
}


