


HOME_DIR =  /home/jaguar

PROJ_DIR = $(HOME_DIR)/Jaguar_workspace/Embedded/RSP3_revB/baremetal/learning_baremetal/03_initialize_without_gcc_crt0_v1



SRC_DIR = src
BUILD_DIR = build
OBJ_DIR = build/obj
BINARIES = bin





build: clean create_build_dir
	aarch64-elf-gcc  -c  -nostdlib -march=armv8-a+crc -mcpu=cortex-a53 $(SRC_DIR)/hello_world.c -o $(OBJ_DIR)/hello_world.o
	aarch64-elf-gcc  -c  -nostdlib -march=armv8-a+crc -mcpu=cortex-a53 $(SRC_DIR)/uart.c -o  $(OBJ_DIR)/uart.o
	aarch64-elf-as    -march=armv8-a+crc -mcpu=cortex-a53  $(SRC_DIR)/startup.S -o $(OBJ_DIR)/startup.o
	aarch64-elf-ld  -T hello_world.ld  $(OBJ_DIR)/hello_world.o $(OBJ_DIR)/uart.o $(OBJ_DIR)/startup.o -o $(OBJ_DIR)/hello_world.elf 
	aarch64-elf-objcopy -O binary $(OBJ_DIR)/hello_world.elf  $(BINARIES)/hello_world.bin


create_build_dir: 
	mkdir -p $(BUILD_DIR)
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BINARIES)



clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(BINARIES)	

say_hello: set_path
	@echo "make clean start_build  flash_SDcard"
	

set_path:
	@echo "you can't export PATH: There's no way¹ the make process can change its parent's environment"
	@echo " you can set env by sourcing the shell script setenv in the project directory"
	@echo " execute command : source setenv.sh"
	@echo ""
	

	
flash_SDcard:
	
	#@shell_output := $(shell "$(PROJ_DIR)/card/create_card.sh" hello_world.bin )

	