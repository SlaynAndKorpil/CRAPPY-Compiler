#pragma once

const char* UNUSED_MARKER_COMPILER_FLAG = "";

const char* UNUSED_DEFINE_COMPILER_FLAG = "";

const char* NUMBER_TOO_LONG = "The number is longer than allowed.";

void print_compiler_error(const char* error, unsigned long long line);
