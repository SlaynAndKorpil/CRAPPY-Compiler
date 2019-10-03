#pragma once

#include <vector>
#include <corecrt_math_defines.h>
#include <string>
#include "cellsize.h"

struct Definition {
    const char* name;
    const char* replacement;
    Definition(const char* name, const char* replacement);
    Definition(const char* name, double replacement);
};

// all currently known definitions
static std::vector<Definition> definitions = std::vector<Definition>();

void get_meta_info_from(std::vector<std::string>* lines) noexcept(false);

Definition parse_using(const char* string);

void add_definition(const char* name, const char* replacement);

bool exists_definition(const char* name);
