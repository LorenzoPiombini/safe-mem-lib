TARGET = mem_safe
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))

default:$(TARGET)


clean:
	sudo rm $(TARGET)
	sudo rm -r obj/*.o 


$(TARGET):$(OBJ)
	sudo gcc -Wall -o $@ $? -lbst -lll -fsanitize=address -fpie -pie -z relro -z now -z noexecstack

obj/%.o:src/%.c
	sudo gcc -Wall -g3 -c $< -o $@ -Iinclude -fstack-protector-strong -D_FORTIFY_SOURCE=2 -fpie -fPIE -pie -fsanitize=address
