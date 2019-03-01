OBJS = main.c init.c object.c timer.c foto.c
CC = gcc
COMPILER_FLAGS = -std=c11 -Wall -Wextra -pedantic -O2
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer
OBJ_NAME = a.out
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME) 
