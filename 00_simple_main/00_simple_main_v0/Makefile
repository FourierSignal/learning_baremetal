say_hello:
	echo "hello"
	@echo "check the diffence in prints!echoing suppressed."

set_path:
	@echo "$(PATH)"
	export PATH=$(PATH):/home/jaguar/Jaguar_workspace/Embedded/RSP3_revB/toolchains/Linaro/baremetal_toolchain/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-elf/bin
	@echo "$(PATH)"
	@echo "you can't export PATH: There's no way¹ the make process can change its parent's environment"
	@echo " you can set env  from seperate shell script"

compile: 
	echo "compiling sorce files\n"
	aarch64-elf-gcc  -march=armv8-a+crc -mcpu=cortex-a53   main.c -o main.elf
	#aarch64-elf-gcc  -march=armv8-a+crc -mcpu=cortex-a53  -specs=rdimon.specs -lc -lrdimon main.c -o main.elf
