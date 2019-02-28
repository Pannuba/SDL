OBJS = main.c init.c foto.c
CC = gcc
COMPILER_FLAGS = -std=c11 -Wall -Wextra -pedantic -O2
LINKER_FLAGS = -lSDL2 -lSDL2_image
OBJ_NAME = a.out
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME) 
