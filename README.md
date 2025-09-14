# Kernel

This is a simple x86_64kernel written in C for educational purposes.

## Features

- Basic VGA text output
- Simple Makefile for building the kernel
- Linker script for memory layout

## Requirements

- LLVM toolchain (clang, lld)
- GNU Make
- QEMU for testing the kernel

## Building the Kernel

To build the kernel, simply run:

```bash
make
```

This will compile the source files and link them into a binary named `kernel.elf`.

## Running the Kernel

You can run the kernel using QEMU with the following command:

```bash
make run
```

## Cleaning Up

To clean up the build files, run:

```bash
make clean
```

## File Structure

- `Makefile`: The build script for compiling and linking the kernel.
- `linker.ld`: The linker script defining the memory layout.
- `sources/`: Directory containing the source code files.
    - `main.c`: The main entry point of the kernel.
    - `vga.c`: Implementation of VGA text output functions.
- `header/`: Directory containing header files.
    - `vga.h`: Header file for VGA text output functions.
- `objects/`: Directory where compiled object files are stored.
