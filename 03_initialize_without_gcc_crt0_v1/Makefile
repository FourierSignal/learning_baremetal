


HOME_DIR =  /home/jaguar

PROJ_DIR = $(HOME_DIR)/Jaguar_workspace/Embedded/RSP3_revB/baremetal/learning_baremetal/03_initialize_without_gcc_crt0_v1



SRC_DIR = src
BUILD_DIR = build
OBJ_DIR = build/obj
BINARIES = bin



say_hello: set_path
	@echo "make clean start_build  flash_SDcard"
	

set_path:
	@echo "you can't export PATH: There's no way¹ the make process can change its parent's environment"
	@echo " you can set env by sourcing the shell script setenv in the project directory"
	@echo " execute command : source setenv.sh"
	@echo ""
	


build: clean
	aarch64-elf-gcc  -c  -nostdlib -march=armv8-a+crc -mcpu=cortex-a53 $(SRC_DIR)/hello_world.c -o hello_world.o
	aarch64-elf-gcc  -c  -nostdlib -march=armv8-a+crc -mcpu=cortex-a53 $(SRC_DIR)/uart.c -o  uart.o
	aarch64-elf-as    -march=armv8-a+crc -mcpu=cortex-a53  $(SRC_DIR)/startup.S -o startup.o
	aarch64-elf-ld  -T hello_world.ld  hello_world.o uart.o startup.o -o hello_world.elf 
	aarch64-elf-objcopy -O binary hello_world.elf hello_world.bin

start_build:  organise_build_files


organise_build_files:  create_build_dir  move_objfiles
	

create_build_dir: build
	mkdir -p $(BUILD_DIR)
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BINARIES)


#use eval to assign a variable in a target rule.
categorise_obj_files:
	$(eval C_OBJ_FILES = $(shell ls *.o | fmt) )
	$(eval ELF_FILES = $(shell ls *.elf | fmt) )
	$(eval BINARY_IMAGES = $(shell ls *.bin | fmt) )


move_objfiles: categorise_obj_files
	@echo "moving object files"

ifneq ($(C_OBJ_FILES) , "")
	mv ${C_OBJ_FILES}   $(OBJ_DIR)
	mv ${ELF_FILES}     $(OBJ_DIR)
endif

ifneq ($(BINARY_IMAGES) , "")
	mv ${BINARY_IMAGES} $(BINARIES)
endif

clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(BINARIES)	

	
flash_SDcard:
	
	#@shell_output := $(shell "$(PROJ_DIR)/card/create_card.sh" hello_world.bin )

	