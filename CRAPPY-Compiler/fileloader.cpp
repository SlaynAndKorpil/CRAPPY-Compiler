#include "fileloader.h"
#include <fstream>

using namespace std;

vector<string> load_lines_from_file(string file_path) noexcept(false) {
  try {
    fstream code_file;
    code_file.open(file_path, ios::in | ios::binary);
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
      return res;
    } else throw "Failed to open the source file.";
  } catch (const char* msg) {
    throw msg;
  }
}
