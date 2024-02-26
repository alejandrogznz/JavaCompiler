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
        ClassFile();

        ClassFile(std::string filename);

    private:

        uint32_t magic_number;
        uint16_t major_version;
        uint16_t minor_version;
        uint16_t cpool_count;
        JC::ConstantPool constant_pool;
};
#endif // JAVACOMPILER_SRC_CLASSFILE_HPP
