cmake_minimum_required(VERSION 3.20)

project(kernel 
    VERSION 1.0.0
    DESCRIPTION "An experimental project to build a basic operating system kernel using C++."
    LANGUAGES CXX ASM
)

# x86_64 kernel settings
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR x86_64)

# Use GCC as the compiler
set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_LINKER /usr/bin/ld)

# Kernel-specific compiler flags
set(CMAKE_C_FLAGS "-m64 -ffreestanding -O2 -nostdlib -fno-exceptions -fno-rtti")
set(CMAKE_CXX_FLAGS "-m64 -ffreestanding -O2 -nostdlib -fno-exceptions -fno-rtti")

# Linker flags: explicitly use the linker script and disable pie
set(LINKER_SCRIPT "${CMAKE_SOURCE_DIR}/linker.ld")
set(CMAKE_EXE_LINKER_FLAGS "-static -nostdlib -nodefaultlibs -fno-pie -Wl,-T${LINKER_SCRIPT}")

# C++ standard settings
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include directories
set(HEADERS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/headers")
set(SOURCES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/sources")

include_directories(${HEADERS_DIR})

# Collect source files
file(GLOB_RECURSE SOURCES "${SOURCES_DIR}/*.cpp")
file(GLOB_RECURSE HEADERS "${HEADERS_DIR}/*.hpp")

# Create the kernel executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Set kernel-specific properties
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    LINKER_LANGUAGE CXX
)
