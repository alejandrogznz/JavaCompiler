#ifndef JAVACOMPILER_SRC_CLASSFILE_HPP
#define JAVACOMPILER_SRC_CLASSFILE_HPP

#include "InputUtil.hpp"

#include <iostream>
#include <string>
#include <fstream>

class ClassFile
{
    public:
        ClassFile()
        {

        }

        ClassFile(std::string filename)
        {
            std::cout << "Generating ClassFile from: " << filename << std::endl; 

            std::ifstream fs("Test.class", std::ios::in | std::ios::binary);
            
            magic_number = readUIntFromFile(fs);
            std::cout << std::hex << magic_number << std::endl;
        }

    private:

        unsigned int magic_number;
        
};
#endif // JAVACOMPILER_SRC_CLASSFILE_HPP
