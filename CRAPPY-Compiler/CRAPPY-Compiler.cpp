// CRAPPY-Compiler.cpp : Compiles a CRAPPY script to a binary file that can then be run by the interpreter.
// WORKFLOW -- load file -> mermorize #-commands -> apply markers -> build binary -> generate file --

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <sstream>
#include "compilerflags.h"
#include "fileloader.h"
#include "consoleout.h"

using namespace std;

const float version = 0.1f;

void ini();
void end();
int compile(int len, char* args[]);

int main(int argc, char* argv[]) {
  ini();
  compile(argc, argv);
  end();
}

void ini() {
  message(("\nRunning CRAPPY compiler version " + to_string(version) + "\n").c_str());
}

int compile(int len, char* args[]) {
  try {
    string source_file;
    string bin_file;

    for (int i = 1; i < len; ++i) {
      string arg = args[i];
      if (arg.length() == 2 && arg[0] == '-') {
        // parsing argument as compiler flag
        unsigned int flag = parse_compiler_flag(arg[1]);
        if (flag == HELP_FLAG) throw (
          "Use this compiler to compile a CRAPPY source file into binary.\n"
          "Usage: 'compiler.exe [options] <path to source file> [path for generated binary]'"
          "Option flags:\n"
          "  -H Prints this and exits.\n"
          "  -I Give additional debugging information.\n"
          "  -D Stop compilation when a 'unused #define' warning occures.\n"
          "  -M Stop compilation when a 'unused marker' warning occures.\n\n");
        else if (flag != 0) current_flags |= flag;
        else throw ("Unknown compiler flag: " + arg + "\n");
      } else {
        source_file = arg;
        if (i + 1 < len) bin_file = args[i + 1];
        else bin_file = arg + ".CRAPPYbin";
        break;
      }
    }

    debug(("Compiling " + source_file + " to " + bin_file + "\n").c_str());

    vector<string> lines = load_lines_from_file(source_file);
    cout << lines[1];

  } catch (const char* msg) {
    error(msg);
    return -1;
  } catch (std::exception error) {
    cout << "An unhandeled exception was thrown: " << error.what() << "\n";
  } catch (string msg) {
    error(msg.c_str());
    return -1;
  }
}

void end() {}
