// CRAPPY-Compiler.cpp : Compiles a CRAPPY script to a binary file that can then be run by the interpreter.
// WORKFLOW -- load file -> memorize #-commands -> apply markers -> build binary -> generate file --

#include <iostream>
#include <vector>
#include "compilerflags.h"
#include "fileloader.h"
#include "consoleout.h"
#include "CompileTimeException.h"
#include "metainfo.h"


const char* version = "0.0.0";

void ini();
int compile(int len, char* args[]);
void end();

int main(int argc, char* argv[]) {
    ini();
    compile(argc, argv);
    end();
}

void ini() {
    message("\nRunning CRAPPY compiler version " + std::string(version) + "\n");
}

int compile(int len, char* args[]) {
    try {
        std::string source_file;
        std::string bin_file;

        for (int i = 1; i < len; ++i) {
            std::string arg = args[i];
            if (arg.length() == 2 && arg[0] == '-') {
                // parsing argument as compiler flag
                unsigned int flag = parse_compiler_flag(arg[1]);
                switch (flag) {
                case HELP_FLAG:
                    // prints help msg
                    message(
                        "Use this compiler to compile a CRAPPY source file into binary.\n"
                        "Usage: 'compiler.exe [options] <path to source file> [path for generated binary]'\n"
                        "Option flags:\n"
                        "  -H Prints this and exits.\n"
                        "  -I Give additional debugging information.\n"
                        "  -D Stop compilation when a 'unused #define' warning occures.\n"
                        "  -M Stop compilation when a 'unused marker' warning occures.\n\n");
                    return 0;
                case 0:
                    // when flag unknown
                    compile_time_exception((R"(Unknown compiler flag: )" + arg + "\n").c_str());
                default:
                    // add flag
                    set_flag(flag);
                }
            } else {
                source_file = arg;
                if (i + 1 < len) bin_file = args[i + 1];
                else bin_file = arg + R"(.CRAPPYbin)";
                break;
            }
        }

        debug("(Compiling )" + source_file + " to " + bin_file + "\n");
        std::vector<std::string> lines = load_lines_from_file(source_file);

        for (int i = 0; i < lines.size(); ++i) {
            message(lines[i]);
        } message("");
        get_meta_info_from(&lines);


        return 0;

    } catch (CompileTimeException & _) {
        return -2;
    } catch (...) {
        error("Unknown exception was thrown.");
        return -1;
    }
}

void end() {}
