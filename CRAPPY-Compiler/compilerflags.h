#pragma once

#define _ // just because my IDE does not want me to properly align my constants

const unsigned int _ _ _ _ _ _ _ _ _ HELP_FLAG = 0b0001;

const unsigned int _ DEBUGGER_INFORMATION_FLAG = 0b0010;

const unsigned int BREAK_ON_UNUSED_DEFINE_FLAG = 0b0100;

const unsigned int BREAK_ON_UNUSED_MARKER_FLAG = 0b1000;

static unsigned int current_flags = 0;

void set_flag(unsigned int flag);

bool is_flag_set(unsigned int flag);

// returns 0 when unable to parse
int parse_compiler_flag(char flag);
