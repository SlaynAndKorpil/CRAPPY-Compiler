#pragma once
#include <string>

// prints error message
void error(const char* msg);
void error(std::string msg);

// prints only when debugger flag is set
void debug(const char* msg);
void debug(std::string msg);

// prints a message
void message(const char* msg);
void message(std::string msg);