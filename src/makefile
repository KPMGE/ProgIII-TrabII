NAME_PROGRAM = vereadores.exe
CC = g++
FLAGS = -std=c++11 -lm -pedantic -Wall 
C_FILES = $(wildcard *.cpp)
O_FILES = $(patsubst %.cpp, %.o, $(C_FILES))

all: clean $(O_FILES) create_executable

main.o: main.cpp
	@ echo "\033[1;32m"
	@ echo "Compiling main.c ..."
	@ $(CC) -c $< $(FLAGS)
	@ echo "\033[0m"

%.o: %.cpp %.h
	@ echo "\033[1;32m"
	@ echo "Compiling $< ..."
	@ $(CC) -c $< $(FLAGS)
	@ echo "\033[0m"

create_executable: 
	@ echo "\033[1;32m"
	@ echo "Creating executable..."
	@ $(CC) -o $(NAME_PROGRAM) $(O_FILES)
	@ echo "\033[0m"

run: 
	@ echo "\033[1;32m"
	@ echo "Running program ..."
	@ echo "\033[0m"
	@ ./$(NAME_PROGRAM)

pre_processor: 
	 @ $(CC) -E $(C_FILES) > processed.c

test: clean $(O_FILES) create_executable run

valgrind: 
	@ echo "\033[1;32m"
	@ echo "Running program ..."
	@ echo "\033[0m"
	@ valgrind ./$(NAME_PROGRAM)

clean: 
	@ echo "\033[1;35m"
	@ echo "Removing temporary files ..."
	@ rm -rf $(NAME_PROGRAM) $(O_FILES)
	@ echo "\033[0m"
