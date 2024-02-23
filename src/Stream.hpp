#ifndef JAVACOMPILER_SRC_STREAM
#define JAVACOMPILER_SRC_STREAM

#include "typedefs.hpp"
#include <istream>

namespace JC
{
    class Stream
    {
        public:

        Stream(std::istream &stream);

        u8 read_u8(); 

        u16 read_u16();

        u32 read_u32();

        private:
        std::istream& m_stream;
        std::size_t m_pos = 0;

        unsigned char get();

        template <typename Integer, std::size_t nbytes>
        Integer read_integer();

        std::istream& stream();
        

    };
}

#endif //JAVACOMPILER_SRC_STREAM
