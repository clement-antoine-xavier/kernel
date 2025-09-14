#include "vga.h"

void _start()
{
    vga_putchar('A', 0, 0, WHITE, BLACK);
    vga_print("Hello, World!", 0, 1, LIGHT_GREY, BLACK);

    while (1)
    {
        asm volatile("hlt");
    }
}
