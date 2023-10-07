#include"compress.h"
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<iostream>
#include<unordered_map>
#include<fstream>
#include<filesystem>

int compress::entry(char* pathchar){
	std::unordered_map<char,int> count;
	std::filesystem::path path(pathchar);
	compress::readfiles(path, count);
	print_map(count);
	return 0;
}

int compress::readfiles(std::filesystem::path path, std::unordered_map<char,int>& count){
	struct stat s; 
	if(stat(path.c_str(),&s) !=0 ){
		std::cout << "File/Folder doesnt exist" ;
		return 1;
	}

	// happy path. 
	if(S_ISREG(s.st_mode)) {
		// Just a file
		std::ifstream file; 
		file.open(path);
		if (file.is_open()){
			char c;
			while (file.get(c)){
				// If key doesnt exist, it is auto added
				count[c]++;
			}
		}
		file.close();
	}
	else if(S_ISDIR(s.st_mode)){
		// Directory
		// Recursively comb through file
		for (auto const& dir_entry: std::filesystem::directory_iterator(path)){
			compress::readfiles(dir_entry, count);		
		}
	}
	else{
		return 3;
	}
	return 0;

}
