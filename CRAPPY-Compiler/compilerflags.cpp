#include "compilerflags.h"

bool is_flag_set(unsigned int flag) {
  return (current_flags & flag) != 0;
}

int parse_compiler_flag(char flag) {
  switch (flag) {
  case 'I' | 'i': return DEBUGGER_INFORMATION_FLAG;
  case 'H' | 'h': return HELP_FLAG;
  case 'D' | 'd': return BREAK_ON_UNUSED_DEFINE_FLAG;
  case 'M' | 'm': return BREAK_ON_UNUSED_MARKER_FLAG;
  default: return 0;
  }
}
