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
        CPEntry(JC::Stream &stream);

        static CPEntry* getEntry(JC::Stream &stream);
        private:

    };
}
#endif //JAVACOMPILER_SRC_CONSTANT_POOL_ENTRY
