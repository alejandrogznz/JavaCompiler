#ifndef JAVACOMPILER_SRC_INPUTUTIL_HPP
#define JAVACOMPILER_SRC_INPUTUTIL_HPP

#include <arpa/inet.h>

unsigned int readUIntFromFile(std::ifstream &fs)
{
    unsigned int res;
    char * buf = new char[4];
    fs.read(buf, 4);
    res = *(reinterpret_cast<unsigned int *>(buf));
    delete buf;
    return htonl(res);
}

#endif // JAVACOMPILER_SRC_INPUTUTIL_HPP
