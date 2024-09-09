#include "ClassFile.hpp"
#include "Interpreter.hpp"

int main() {
  // Implement the Java Classfile class that reads in the
  // Java methods in the class file
  ClassFile classFile("Test.class");
  // Interpret the classfile object line by line
  JC::interpretClassFile(classFile);
  return 0;
}
