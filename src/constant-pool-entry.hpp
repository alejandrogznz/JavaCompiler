#ifndef JAVACOMPILER_SRC_CONSTANT_POOL_ENTRY
#define JAVACOMPILER_SRC_CONSTANT_POOL_ENTRY

#include "typedefs.hpp"
#include "Stream.hpp"
#include <fstream>
#include <iostream>

namespace JC
{
    class CPEntry
    {
        public:
        CPEntry(JC::Stream &stream)
        {
            u8 id = stream.read_u8();
            std::cout << std::dec << int(id) << std::endl;
        }

        static CPEntry* getEntry(JC::Stream &stream)
        {
            u8 id = stream.read_u8();
            switch (id) {
                case 10:
                    std::cout << "CONSTANT_Methodref " << std::endl;
                    break;
                default:
                    std::cout << "Unknown CONSTANT_POOL_ENTRY " << int(id) << ". Exiting" << std::endl;
                    exit(0);

            }
            return nullptr;
        }
        private:
    };
}
#endif //JAVACOMPILER_SRC_CONSTANT_POOL_ENTRY
