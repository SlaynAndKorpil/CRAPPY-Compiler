#include <iostream>
#include "metainfo.h"
#include "CompileTimeException.h"

Definition::Definition(const char* name, const char* replacement) {
    this->name = name;
    this->replacement = replacement;
}

Definition::Definition(const char* name, double replacement) {
    this->name = name;
    this->replacement = std::to_string(replacement).c_str();
}

void get_meta_info_from(std::vector<std::string>* lines) noexcept(false) {
    for (int line_nr = 0; line_nr < lines->size(); ++line_nr) {
        std::string line = lines->at(line_nr);

        if (line != "" && line[0] == '#') {
            std::string first_word = "";

            for (int i = 1; i < line.size(); ++i) {
                char curr_char = line[i];
                if (curr_char == ' ') break;
                else first_word += curr_char;
            }

            if (first_word == "define") {
                std::cout << "Found definition in line " << line_nr + 1 << "\n";
            } else if (first_word == "using") {
                std::cout << "Found using in line " << line_nr + 1 << "\n";
            } else if ('0' <= first_word[0] && first_word[0] <= '9') {
                // cell size instruction
                if (cell_size == 0) {
                    cell_size = parse_cell_size(first_word.c_str());

                    if (cell_size == 0) // parsing failed
                        compile_time_exception(("Failed to parse the cell size instruction\n    " + line + "\nin line " + std::to_string(line_nr + 1)).c_str());
                }
                else compile_time_exception(("Only one cell size instruction allowed\n    " + line + "\nin line " + std::to_string(line_nr + 1)).c_str());
            } else compile_time_exception(
                ("Failed to parse the meta command\n    " + line + "\nin line " + std::to_string(line_nr + 1)).c_str());
        }
    }
}

Definition parse_using(const char* string) {
    double value =
        string == "E" ? M_E :
        string == "LOG2E" ? M_LOG2E :
        string == "LOG10E" ? M_LOG10E :
        string == "LN2" ? M_LN2 :
        string == "LN4" ? M_LN10 :
        string == "PI" ? M_PI :
        string == "PI/2" ? M_PI_2 :
        string == "PI/4" ? M_PI_4 :
        string == "1/PI" ? M_1_PI :
        string == "2/PI" ? M_2_PI :
        string == "2/SQRTPI" ? M_2_SQRTPI :
        string == "SQRT2" ? M_SQRT2 :
        string == "1/SQRT2" ? M_SQRT1_2 :
        (compile_time_exception("Unknown constant."), -1);
    return Definition(string, value);
}

void add_definition(const char* name, const char* replacement) {
    definitions.push_back(Definition(name, replacement));
}

bool exists_definition(const char* name) {
    for (Definition def : definitions) {
        if (def.name == name) return true;
    }
    return false;
}
