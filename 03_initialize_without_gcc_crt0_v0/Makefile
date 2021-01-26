

say_hello: set_path
	@echo "make clean start_build"
	

set_path:
	@echo "you can't export PATH: There's no way¹ the make process can change its parent's environment"
	@echo " you can set env by sourcing the shell script setenv in the project directory"
	@echo "projdir:$(PROJ_DIR)"
	@echo " execute command : source setenv.sh"
	@echo ""
	


start_build:
	aarch64-elf-gcc  -c  -march=armv8-a+crc -mcpu=cortex-a53 hello_world.c -o hello_world.o
	#aarch64-elf-g++  -c -nostdlib  -march=armv8-a+crc -mcpu=cortex-a53 hello_world.c
	#aarch64-elf-gcc -S -v -nostdlib -march=armv8-a+crc -mcpu=cortex-a53  startup.S
	aarch64-elf-as    -march=armv8-a+crc -mcpu=cortex-a53  startup.S -o startup.o
	aarch64-elf-ld  -T hello_world.ld  hello_world.o startup.o -o hello_world.elf 

clean:
	rm  *.o  *.elf
	