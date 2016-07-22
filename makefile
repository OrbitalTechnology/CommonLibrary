NAME := common
ARCH := x64
ID := debug

OUTPUT := $(NAME)$(ARCH)$(ID)

build :
	mkdir -p bin/
	cd bin/ ; clang++ -c ../src/*.cpp -I ../include/ -Wc++11-extensions
	ar rcs bin/lib$(OUTPUT).a bin/*.o

clean :	
	rm -rf bin/* || true