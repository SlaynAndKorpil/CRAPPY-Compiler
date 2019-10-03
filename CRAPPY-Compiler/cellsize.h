#pragma once

#include <stdint.h>

static uint8_t CELL_8_BIT_SIZE = 1;
static uint8_t CELL_16_BIT_SIZE = 2;
static uint8_t CELL_32_BIT_SIZE = 4;
static uint8_t CELL_64_BIT_SIZE = 8;
static uint8_t CELL_128_BIT_SIZE = 16;

uint8_t parse_cell_size(const char* size);

// the bit identifier for the current cell_size
char current_bit_id();

// the cell size in bytes
static uint8_t cell_size = 0;
