#include "Stream.hpp"

namespace JC
{
    Stream::Stream(std::istream &stream)
        :m_stream(stream)
    {}

    u8 Stream::read_u8()
    {
        return stream().get();
    }
    
    u16 Stream::read_u16()
    { 
        return read_integer<u16, 2>();
    }

    u32 Stream::read_u32()
    {
        return read_integer<u32, 4>();
    }

    char * Stream::read_string(size_t n)
    {
        char * result = new char[n + 1];
        result[n] = 0;
        for (int i = 0; i < n; ++i)
        {
            result[i] = get();
        }
        std::cout << result << std::endl;
        return result;
    }

    unsigned char Stream::get()
    {
        unsigned char result = stream().get();
        if (!stream().eof())
        {
            ++m_pos;
        }
        return result;
    }

    template <typename Integer, std::size_t nbytes>
    Integer Stream::read_integer()
    {
        Integer result = 0;
        for (std::size_t i = 0; i < nbytes; ++i)
        {
            result <<= 8;
            result |= get();
        }

        if (stream().eof()) 
        {
            throw std::runtime_error("Unexpected EOF");
        }

        return result;
    } 

    std::istream& Stream::stream()
    {
        return m_stream;
    }
}
