COMPILER ?= clang --target=aarch64
LINKER ?= aarch64-linux-gnu-ld
OBJCOPY ?= aarch64-linux-gnu-objcopy

COPS = -Wall -nostdlib -ffreestanding -Isrc -mgeneral-regs-only
ASMOPS = -Isrc 

BUILD_DIR = build/bin
SRC_DIR = src
LINKER_DIR = build

all : kernel8.img

clean :
	rm -rf $(BUILD_DIR) *.img 

$(BUILD_DIR)/%_c.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(COMPILER) $(COPS) -MMD -c $< -o $@

$(BUILD_DIR)/%_s.o: $(SRC_DIR)/%.S
	$(COMPILER) $(ASMOPS) -MMD -c $< -o $@

C_FILES = $(wildcard $(SRC_DIR)/*.c)
ASM_FILES = $(wildcard $(SRC_DIR)/*.S)
OBJ_FILES = $(C_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%_c.o)
OBJ_FILES += $(ASM_FILES:$(SRC_DIR)/%.S=$(BUILD_DIR)/%_s.o)

DEP_FILES = $(OBJ_FILES:%.o=%.d)
-include $(DEP_FILES)

kernel8.img: $(LINKER_DIR)/linker.ld $(OBJ_FILES)
	$(LINKER) -T $(LINKER_DIR)/linker.ld -o $(BUILD_DIR)/kernel8.elf  $(OBJ_FILES)
	$(OBJCOPY) $(BUILD_DIR)/kernel8.elf -O binary kernel8.img
