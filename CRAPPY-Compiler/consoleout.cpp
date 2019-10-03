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

void error(std::string msg) {
    error(msg.c_str());
}

void debug(const char* msg) {
  if (is_flag_set(DEBUGGER_INFORMATION_FLAG)) 
      std::cout << "DEBUG - " << msg << "\n";
}

void debug(std::string msg) {
    debug(msg.c_str());
}

void message(const char* msg) {
  std::cout << msg << "\n";
}

void message(std::string msg) {
    message(msg.c_str());
}
