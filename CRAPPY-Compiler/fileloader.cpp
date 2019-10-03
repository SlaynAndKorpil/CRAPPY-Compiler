#include "fileloader.h"
#include <fstream>
#include "CompileTimeException.h"
#include <iostream>

using namespace std;

// removes unnecessary whitespaces/tabs and comments
// also replaces tabs with whitespaces
void simplify(std::vector<std::string>* lines) {
    for (int i = 0; i < lines->size(); ++i) {
        std::string line = lines->at(i);
        std::string simplified = "";
        bool in_char = false;
        bool in_string = false;

        // skip all until first non-whitespace char
        int first_char = 0;
        while (first_char < line.size() && (line[first_char] == ' ' || line[first_char] == '\t'))
            ++first_char;

        std::cout << line << "\n";
        for (int j = first_char; j < line.size(); ++j) {
            char curr_char = line[j];

            if (in_char) {
                if (curr_char == '\'') in_char = false;
            } else if (in_string) {
                if (curr_char == '\"') in_string = false;
            } else {
                switch (curr_char) {
                case ';':
                    goto add_line;
                case '\'':
                    in_char = true;
                    break;
                case '\"':
                    in_string = true;
                    break;
                case ' ':
                case '\t':
                    std::cout << "    has space at " << j << "\n";
                    simplified += ' ';
                    while (++j < (int) line.size() && (line[j] == ' ' || line[j] == '\t')) {}
                    std::cout << "    until " << j << "\n";
                    --j;
                    continue;
                }
            }

            simplified += curr_char;
        }

    add_line:
        lines->at(i) = simplified;
    }
}

vector<string> load_lines_from_file(string file_path) noexcept(false) {
    fstream code_file;
    code_file.open(file_path, ios::in);

    if (code_file.is_open()) {
        string line;
        vector<string> res = vector<string>();

        while (getline(code_file, line)) {
            if (code_file.bad()) {
                // reading op failed
            } else if (code_file.fail()) {
                // bad() or format error (e.g. alphabetical char extracted when integer was expected
            } else if (code_file.eof()) {
                // reached end of file
            } else {
                // np
            }
            res.push_back(line);
        }
        code_file.close();

        simplify(&res);
        return res;
    } else compile_time_exception("Failed to open the source file.");
}
