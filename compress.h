#include<unordered_map>
#include<iostream>
#include<filesystem>

namespace compress{
	int entry(char* path);
	int readfiles(std::filesystem::path path, std::unordered_map<char, int>& count);
}

template<typename K, typename V>
void print_map(std::unordered_map<K, V> const &m)
{
    for (auto const &pair: m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}
