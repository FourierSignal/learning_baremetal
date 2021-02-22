TOOLCHAIN_PATH = /home/jaguar/Jaguar_workspace/Embedded/RSP3_revB/toolchains/Linaro/baremetal_toolchain/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-elf/

#CROSS = arch64-elf
#CROSS = arm-none-eabi
CROSS = aarch64-elf

say_hello: set_path
	@echo "make clean start_build"
	

set_path:
	@echo "you can't export PATH: There's no way¹ the make process can change its parent's environment"
	@echo " you can set env by sourcing the shell script setenv in the project directory"
	@echo "projdir:$(PROJ_DIR)"
	@echo " execute command : source setenv.sh"
	@echo ""
	


start_build:
	$(CROSS)-gcc  -c -g  -march=armv8-a+crc -mcpu=cortex-a53 hello_world.c
	cp $(TOOLCHAIN_PATH)/aarch64-elf/libc/usr/lib/crt0.o  .
	aarch64-elf-ld -o  hello_world.elf hello_world.o crt0.o -lc

