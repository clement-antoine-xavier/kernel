#include "vga.h"

volatile vga_char_t *const VGA_MEMORY = (vga_char_t *)(0xB8000);

void vga_putchar(char c, uint8_t x, uint8_t y, vga_color_t fg, vga_color_t bg)
{
    const uint8_t color = fg | (bg << 4);
    VGA_MEMORY[y * 80 + x].character = c;
    VGA_MEMORY[y * 80 + x].color = color;
}

void vga_print(const char *str, uint8_t x, uint8_t y, vga_color_t fg, vga_color_t bg)
{
    for (size_t i = 0; str[i] != '\0'; ++i)
    {
        vga_putchar(str[i], x + i, y, fg, bg);
    }
}
