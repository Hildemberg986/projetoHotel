# Nome do executável
TARGET = main

# Compiler
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra

# Diretórios dos arquivos fonte
LOGIC_DIR = logic
SCREENS_DIR = screens

# Arquivos fonte de lógica
LOGIC_SRCS := $(wildcard $(LOGIC_DIR)/*.c)

# Arquivos fonte de telas
SCREENS_SRCS := $(wildcard $(SCREENS_DIR)/*.c)

# Arquivo fonte contendo a função main
MAIN_SRC = main.c

# Todos os arquivos fonte
SRCS = $(MAIN_SRC) $(LOGIC_SRCS) $(SCREENS_SRCS)

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