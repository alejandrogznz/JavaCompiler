#ifndef JAVACOMPILER_SRC_CLASSFILE_HPP
#define JAVACOMPILER_SRC_CLASSFILE_HPP

#include "constant-pool.hpp"
#include "Stream.hpp"
#include "typedefs.hpp"
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
            JC::Stream stream(fs);

            magic_number = stream.read_u32();
            major_version = stream.read_u16();
            minor_version = stream.read_u16();
            cpool_count = stream.read_u16();

            std::cout << std::hex << magic_number << std::endl;
            std::cout << std::hex << major_version << std::endl;
            std::cout << std::hex << minor_version << std::endl;
            std::cout << std::hex << cpool_count << std::endl;
            
            constant_pool = JC::ConstantPool(stream, cpool_count);

        }

    private:

        uint32_t magic_number;
        uint16_t major_version;
        uint16_t minor_version;
        uint16_t cpool_count;
        JC::ConstantPool constant_pool;
};
#endif // JAVACOMPILER_SRC_CLASSFILE_HPP
