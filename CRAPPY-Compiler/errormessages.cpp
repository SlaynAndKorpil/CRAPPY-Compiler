#include "errormessages.h"
#include <iostream>

void print_compiler_error(const char* error, unsigned long long line) {
  std::cout << "An error occured in line " << line << ":\n";
  std::cout << error;
}
