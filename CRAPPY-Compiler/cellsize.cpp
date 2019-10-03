#include "cellsize.h"
#include <cstring>

// Parses pre-compilation info about the cell size
// returns 0 when unable to parse
uint8_t parse_cell_size(const char* size) {
    return
        std::strcmp(size, "8-bit") ? CELL_8_BIT_SIZE :
        std::strcmp(size, "16-bit") ? CELL_16_BIT_SIZE :
        std::strcmp(size, "32-bit") ? CELL_32_BIT_SIZE :
        std::strcmp(size, "64-bit") ? CELL_64_BIT_SIZE :
        std::strcmp(size, "128-bit") ? CELL_128_BIT_SIZE :
        0;
}

char current_bit_id() {
    return cell_size;
}
