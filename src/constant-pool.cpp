#include "constant-pool.hpp"

namespace JC
{
    ConstantPool::ConstantPool()
    {}

    ConstantPool::ConstantPool(JC::Stream &stream, const uint16_t &cp_count)
    {
       for (size_t t = 0; t < cp_count-1; ++t)
       {
           std::cout << std::dec << "Constant Pool Entry #" << t << " ";
           CPEntry * cpentry = CPEntry::getEntry(stream);
       }
    } 
}
