#pragma once

#include <stdint.h>
#include <stddef.h>

typedef enum vga_color_e
{
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    BROWN = 6,
    LIGHT_GREY = 7,
    DARK_GREY = 8,
    LIGHT_BLUE = 9,
    LIGHT_GREEN = 10,
    LIGHT_CYAN = 11,
    LIGHT_RED = 12,
    LIGHT_MAGENTA = 13,
    LIGHT_BROWN = 14,
    WHITE = 15,
} vga_color_t;

typedef struct vga_char_s
{
    uint8_t character;
    uint8_t color;
} vga_char_t;

extern volatile vga_char_t *const VGA_MEMORY;

void vga_putchar(char c, uint8_t x, uint8_t y, vga_color_t fg, vga_color_t bg);

void vga_print(const char *str, uint8_t x, uint8_t y, vga_color_t fg, vga_color_t bg);