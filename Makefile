NAME := kernel
CC := clang
LD := ld.lld
OBJCOPY := objcopy
TARGET := x86_64-elf
QEMU := qemu-system-x86_64

SOURCES_DIRECTORY := sources
HEADERS_DIRECTORY := headers
OBJECTS_DIRECTORY := objects

CFLAGS := -Wall -Wextra -Werror -target $(TARGET) -ffreestanding -nostdlib -I$(HEADERS_DIRECTORY) -mno-red-zone -fno-PIE -g
LDFLAGS := -T linker.ld -nostdlib --nmagic --oformat=elf64-x86-64

SOURCES := $(wildcard $(SOURCES_DIRECTORY)/*.c)
OBJECTS := $(patsubst $(SOURCES_DIRECTORY)/%.c,$(OBJECTS_DIRECTORY)/%.o,$(SOURCES))

all: $(NAME).bin

$(NAME).bin: $(OBJECTS)
	@echo "Linking $(NAME).elf"
	$(LD) $(LDFLAGS) $^ -o $(NAME).elf

$(OBJECTS_DIRECTORY)/%.o: $(SOURCES_DIRECTORY)/%.c
	@mkdir -p $(@D)
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS_DIRECTORY)

fclean: clean
	rm -f $(NAME).elf $(NAME).bin

re: fclean all

run: $(NAME).bin
	@echo "Starting kernel in QEMU..."
	$(QEMU) -drive format=raw,file=$(NAME).elf -m 512M -cpu qemu64,+sse3,+sse4.2,+xsave,+avx,+xsaveopt,+xsavec,+xgetbv1,+avx2,+bmi2,+smep,+bmi1,+fma -smp 2 -serial stdio -no-reboot -d int

.PHONY: all clean fclean re run
