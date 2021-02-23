
#HOME_DIR = /home/jaguar/Mount_dir/jaguar
HOME_DIR = /home/jaguar
RELATIVE_PATH = $(HOME_DIR)/Documents/learning_baremetal
PROJ_DIR = $(RELATIVE_PATH)/03_initialize_without_gcc_crt0_v5
CARD_DIR = $(PROJ_DIR)/card


SRC_DIR = src
BUILD_DIR = build
OBJ_DIR = build/obj
BINARIES = bin



CROSS = aarch64-elf
CFLAGS  = -g -Wall -O2 -ffreestanding  -D RPI3 -D IOBPLUS --verbose
LDFLAGS = -nostdlib -T hello_world.ld --verbose 

# -nostartfiles: Do not use the standard system startup files when linking
# -march=arch{+[no]feature}*  ==> 
build: clean create_build_dir
	$(CROSS)-gcc $(CFLAGS) -c  -nostdlib -march=armv8-a+crc -mcpu=cortex-a53 $(SRC_DIR)/hello_world.c -o $(OBJ_DIR)/hello_world.o
	$(CROSS)-gcc $(CFLAGS) -c  -nostdlib -march=armv8-a+crc -mcpu=cortex-a53 $(SRC_DIR)/uart.c -o  $(OBJ_DIR)/uart.o
	$(CROSS)-gcc $(CFLAGS) -c  -nostdlib -march=armv8-a+crc -mcpu=cortex-a53 $(SRC_DIR)/cstartup.c -o  $(OBJ_DIR)/cstartup.o
	
	$(CROSS)-gcc $(CFLAGS) -c  -nostdlib -march=armv8-a+crc -mcpu=cortex-a53 $(SRC_DIR)/gpio.c -o  $(OBJ_DIR)/gpio.o
		
	$(CROSS)-as    -march=armv8-a+crc -mcpu=cortex-a53  $(SRC_DIR)/startup.S -o $(OBJ_DIR)/startup.o
	$(CROSS)-ld  $(LDFLAGS)  $(OBJ_DIR)/hello_world.o $(OBJ_DIR)/uart.o $(OBJ_DIR)/gpio.o  $(OBJ_DIR)/cstartup.o $(OBJ_DIR)/startup.o -o $(OBJ_DIR)/hello_world.elf 
	$(CROSS)-objcopy -O binary $(OBJ_DIR)/hello_world.elf  $(BINARIES)/hello_world.bin



create_build_dir: 
	mkdir -p $(BUILD_DIR)
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BINARIES)



clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(BINARIES)	
	rm -f $(CARD_DIR)/hello_world.bin
	rm -f $(CARD_DIR)/card.Rpi3.RevB.baremetal.img


say_hello: set_path
	@echo "make clean start_build  copySDcard_files"
	

set_path:
	@echo "you can't export PATH: There's no way¹ the make process can change its parent's environment"
	@echo " you can set env by sourcing the shell script setenv in the project directory"
	@echo " execute command : source setenv.sh"
	@echo ""
	
debug_files:
	aarch64-elf-objdump  -D $(OBJ_DIR)/hello_world.elf   >  $(OBJ_DIR)/hello_world.disassemble
	aarch64-elf-objdump  -S $(OBJ_DIR)/hello_world.elf   >  $(OBJ_DIR)/hello_world.mixedassembly
	aarch64-elf-objdump  -t $(OBJ_DIR)/hello_world.elf   >  $(OBJ_DIR)/hello_world.symboltable
	aarch64-elf-objdump  -T $(OBJ_DIR)/hello_world.elf   >  $(OBJ_DIR)/hello_world.DynamicSymbols
	aarch64-elf-objdump  -r $(OBJ_DIR)/hello_world.elf   >  $(OBJ_DIR)/hello_world.relocEntries
	aarch64-elf-objdump  -R $(OBJ_DIR)/hello_world.elf   >  $(OBJ_DIR)/hello_world.DynrelocEntries

	
copySDcard_files:
	cp $(BINARIES)/hello_world.bin  $(CARD_DIR)/
	
flash_SDcard:
	#@shell_output := $(shell "$(PROJ_DIR)/card/create_card.sh" hello_world.bin )

	
