#include "consoleout.h"
#include <iostream>
//#include <windows.h>
#include "compilerflags.h"

// FIXME first check OS and then adapt color settings

void error(const char* msg) {
  // This is only win specific
  //HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  //SetConsoleTextAttribute(hConsole, 0xFF0000);
  std::cout << "\nERROR\n" << msg << "\n\n";
}

void debug(const char* msg) {
  if (is_flag_set(DEBUGGER_INFORMATION_FLAG)) 
      std::cout << "DEBUG - " << msg << "\n";
}

void message(const char* msg) {
  std::cout << msg;
}
