#ifndef JAVACOMPILER_SRC_CONSTANT_POOL_ENTRY
#define JAVACOMPILER_SRC_CONSTANT_POOL_ENTRY

#include "typedefs.hpp"
#include "Stream.hpp"
#include <fstream>
#include <iostream>
#include <vector>

namespace JC
{
    class CPEntry
    {
        public:

        CPEntry(u8 tag);

        CPEntry(JC::Stream &stream);

        static CPEntry* getEntry(JC::Stream &stream);

        private:
        u8 tag;
    };

    class MethodRef: public CPEntry
    {
        public:
        MethodRef(u8 tag, Stream &stream);

        private:
        u16 class_index;
        u16 name_and_type_index;
    };


    class FieldRef: public CPEntry
    {
        public:
        FieldRef(u8 tag, Stream &stream);

        private:
        u16 class_index;
        u16 name_and_type_index;
    };
    
    class ConstantString: public CPEntry
    {
        public:
        ConstantString(u8 tag, Stream &stream);

        private:
        u16 string_index;
    };

    class ConstantClass: public CPEntry
    {
        public:
        ConstantClass(u8 tag, Stream &stream);

        private:
        u16 name_index;
    };

    class ConstantUtf8: public CPEntry
    {
        public:
        ConstantUtf8(u8 tag, Stream &stream);

        private:
        u16 length;
        char * bytes;
    };
}
#endif //JAVACOMPILER_SRC_CONSTANT_POOL_ENTRY
