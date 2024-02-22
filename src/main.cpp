#include <iostream>
#include <fstream>
#include <arpa/inet.h>
#include "ClassFile.hpp"
int main() 
{
    std::ifstream fs("Test.class", std::ios::in | std::ios::binary);
    ClassFile classFile("Test.class");
    char * word = new char[4];
    fs.read(word, 4);
    unsigned int * magic_number = reinterpret_cast<unsigned int *>(word);
    std::cout << std::hex << htonl(*magic_number) << std::endl;

    fs.close();
    return 0;
}
	
