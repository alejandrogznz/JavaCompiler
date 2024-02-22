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
        }

    private:
        unsigned int magic_number;
};
#endif // JAVACOMPILER_SRC_CLASSFILE_HPP
