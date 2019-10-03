#include "CompileTimeException.h"


void compile_time_exception(const char* msg) noexcept(false) {
    error(msg);
    throw CompileTimeException();
}
