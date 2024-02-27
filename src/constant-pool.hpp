#ifndef JAVACOMPILER_SRC_CONSTANT_POOL
#define JAVACOMPILER_SRC_CONSTANT_POOL

#include "Stream.hpp"
#include "constant-pool-entry.hpp"
#include "typedefs.hpp"
#include <fstream>
#include <vector>
#include <iostream>

namespace JC{
    class ConstantPool
    {
        public:
        ConstantPool();
        
        ConstantPool(JC::Stream &stream, const uint16_t &cp_count);

        private:
        std::vector<CPEntry *> constant_pool;

    };
}

#endif // JAVACOMPILER_SRC_CONSTANT_POOL
