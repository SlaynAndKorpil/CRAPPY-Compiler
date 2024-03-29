#include "compilerflags.h"
#include <iostream>

void set_flag(unsigned int flag) {
    current_flags |= flag;
}

bool is_flag_set(unsigned int flag) {
    return (current_flags & flag) != 0;
}

int parse_compiler_flag(char flag) {
    switch (flag) {
    case 'i': return DEBUGGER_INFORMATION_FLAG;
    case 'h': return HELP_FLAG;
    case 'd': return BREAK_ON_UNUSED_DEFINE_FLAG;
    case 'm': return BREAK_ON_UNUSED_MARKER_FLAG;
    default: return 0;
    }
}
