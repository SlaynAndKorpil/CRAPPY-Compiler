#pragma once

const unsigned int HELP_FLAG = 0b001;

const unsigned int BREAK_ON_UNUSED_DEFINE_FLAG = 0b010;

const unsigned int DEBUGGER_INFORMATION_FLAG = 0b011;

const unsigned int BREAK_ON_UNUSED_MARKER_FLAG = 0b100;

static unsigned int current_flags = 0;

bool is_flag_set(unsigned int flag);

int parse_compiler_flag(char flag);
