# Nome do executável
TARGET = main

# Compiler
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra

# Arquivos fonte
ifeq ($(OS),Windows_NT)
    SRCS := $(shell type imports.txt)
else
    SRCS := $(shell cat imports.txt)
endif

# Objetos gerados
OBJS = $(SRCS:.c=.o)

# Regra padrão: compila o programa
all: $(TARGET)

# Regra de compilação do programa
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regra de compilação de arquivos fonte para objetos
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar arquivos objeto e o executável
cleanunix:
	rm -f $(OBJS)
cleanwindows:
	del /Q $(OBJS)