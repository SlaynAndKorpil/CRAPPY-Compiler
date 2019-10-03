#include "fileloader.h"
#include <fstream>
#include "CompileTimeException.h"

using namespace std;

// removes unnecessary whitespaces and comments
void simplify(std::vector<std::string>* lines) {
    for (int i = 0; i < lines->size(); ++i) {
        std::string line = lines->at(i);
        std::string simplified = "";

        // skip all until first non-whitespace char
        int first_char = 0;
        while (first_char < line.size() && (line[first_char] == ' ' || line[first_char] == '\t'))
            ++first_char;

        // removes comments by copying all chars until a ';' appeares
        for (int j = first_char; j < line.size(); ++j) {
            char curr_char = line[j];
            if (curr_char == ';') break;
            simplified += curr_char;
        }
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
