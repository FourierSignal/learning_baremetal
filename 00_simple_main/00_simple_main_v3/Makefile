PROJ_DIR = $(PWD)

SRC_DIR = src

BUILD_DIR = build
PREPROCESSED = build/preprocessed_files
OBJ_DIR = build/obj
ASM_DIR = build/asm
BINARIES = bin
EXECUTABLES = build/elfs


say_hello: set_path
	@echo "make clean start_build"
	

set_path:
	@echo "you can't export PATH: There's no way¹ the make process can change its parent's environment"
	@echo " you can set env by sourcing the shell script setenv in the project directory"
	@echo "projdir:$(PROJ_DIR)"
	@echo " execute command : source setenv.sh"
	@echo ""
	


start_build: stop_at_preprocess  stop_at_assemble  stop_atcompile generate_elf generate_binary organise_build_files
	
stop_at_preprocess: main.c
	aarch64-elf-gcc -E -march=armv8-a+crc -mcpu=cortex-a53  -specs=rdimon.specs -lc -lrdimon main.c -o main.i

stop_at_assemble: main.c
	aarch64-elf-gcc -S -march=armv8-a+crc -mcpu=cortex-a53  -specs=rdimon.specs -lc -lrdimon main.c -o main.s

stop_atcompile: main.c
	aarch64-elf-gcc -c -march=armv8-a+crc -mcpu=cortex-a53  -specs=rdimon.specs -lc -lrdimon main.c -o main.o

generate_elf: main.c
	aarch64-elf-gcc --verbose  -march=armv8-a+crc -mcpu=cortex-a53  -specs=rdimon.specs -lc -lrdimon main.c -o main.elf

generate_binary: main.elf
	aarch64-elf-objcopy  --gap-fill=0xff -O binary main.elf main.bin


organise_build_files: create_build_dir  move_objfiles
	ls -l build/elfs

create_build_dir:
	mkdir -p $(BUILD_DIR)
	mkdir -p $(PREPROCESSED)
	mkdir -p $(OBJ_DIR)
	mkdir -p $(ASM_DIR)
	mkdir -p $(EXECUTABLES)
	mkdir -p $(BINARIES)


#use eval to assign a variable in a target rule.
categorise_obj_files:
	$(eval PREPROCESSED_FILES = $(shell ls *.i| fmt) )
	$(eval C_OBJ_FILES = $(shell ls *.o | fmt) )
	$(eval ASM_FILES = $(shell ls *.s | fmt) )
	$(eval ELF_FILES = $(shell ls *.elf | fmt) )
	$(eval BINARY_IMAGES = $(shell ls *.bin | fmt) )


move_objfiles: categorise_obj_files
	@echo "moving object files"
ifneq ($(PREPROCESSED_FILES) , "")
	mv ${PREPROCESSED_FILES} $(PREPROCESSED)
endif

ifneq ($(ASM_FILES), "")
	mv ${ASM_FILES}     $(ASM_DIR)
endif

ifneq ($(C_OBJ_FILES) , "")
	mv ${C_OBJ_FILES}   $(OBJ_DIR)
endif

ifneq ($(ELF_FILES) , "")
	mv ${ELF_FILES}     $(EXECUTABLES)
endif

ifneq ($(BINARY_IMAGES) , "")
	mv ${BINARY_IMAGES} $(BINARIES)
endif

clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(BINARIES)	

