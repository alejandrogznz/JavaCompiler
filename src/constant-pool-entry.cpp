#include "constant-pool-entry.hpp"

namespace JC {
CPEntry::CPEntry(u8 tag) : tag(tag) {}

CPEntry::CPEntry(JC::Stream &stream) {
  u8 id = stream.read_u8();
  std::cout << std::dec << int(id) << std::endl;
}

CPEntry *CPEntry::getEntry(JC::Stream &stream) {
  std::vector<CPEntry *> constant_pool;
  u8 id = stream.read_u8();
  switch (id) {
  case 12:
    std::cout << "Constant_NameAndType" << std::endl;
    constant_pool.push_back(new Constant_NameAndType(id, stream));
    break;
  case 10:
    std::cout << "CONSTANT_Methodref " << std::endl;
    constant_pool.push_back(new MethodRef(id, stream));
    break;
  case 9:
    std::cout << "CONSTANT_Fieldref " << std::endl;
    constant_pool.push_back(new FieldRef(id, stream));
    break;
  case 8:
    std::cout << "CONSTANT_String" << std::endl;
    constant_pool.push_back(new ConstantString(id, stream));
    break;
  case 7:
    std::cout << "CONSTANT_Class" << std::endl;
    constant_pool.push_back(new ConstantClass(id, stream));
    break;
  case 1:
    std::cout << "CONSTANT_Utf8" << std::endl;
    constant_pool.push_back(new ConstantUtf8(id, stream));
    break;
  default:
    std::cout << "Unknown CONSTANT_POOL_ENTRY " << int(id) << ". Exiting"
              << std::endl;
    exit(0);
  }
  return nullptr;
}

MethodRef::MethodRef(u8 tag, Stream &stream) : CPEntry(tag) {
  class_index = stream.read_u16();
  name_and_type_index = stream.read_u16();
}

FieldRef::FieldRef(u8 tag, Stream &stream) : CPEntry(tag) {
  class_index = stream.read_u16();
  name_and_type_index = stream.read_u16();
}

ConstantString::ConstantString(u8 tag, Stream &stream) : CPEntry(tag) {
  string_index = stream.read_u16();
}

ConstantClass::ConstantClass(u8 tag, Stream &stream) : CPEntry(tag) {
  name_index = stream.read_u16();
}

ConstantUtf8::ConstantUtf8(u8 tag, Stream &stream) : CPEntry(tag) {
  length = stream.read_u16();
  bytes = stream.read_string(length);
}

Constant_NameAndType::Constant_NameAndType(u8 tag, Stream &stream)
    : CPEntry(tag) {
  name_index = stream.read_u16();
  descriptor_index = stream.read_u16();
}
} // namespace JC
