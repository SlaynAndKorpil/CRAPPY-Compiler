#pragma once

#include <exception>
#include "consoleout.h"

struct CompileTimeException : public std::exception {
public:
    virtual const char* what() noexcept(true) {
        return "A compile time error occured.";
    };
};

void compile_time_exception(const char* msg) noexcept(false);
