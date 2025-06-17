# Directorios
SRC_DIR = src
INC_DIR = include
BIN_DIR = bin

# Archivos fuente y objeto
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/dynamicarray.c
OBJ = $(SRC:.c=.o)

# Compilador y flags
CC = gcc
CFLAGS = -I$(INC_DIR) -Wall -Wextra -g

# Ejecutable
EXEC = $(BIN_DIR)/main

# Regla por defecto
all: $(BIN_DIR) $(EXEC)

# Compilación del ejecutable
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@

# Crear directorio bin si no existe
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Limpiar archivos generados
clean:
	rm -f $(SRC_DIR)/*.o
	rm -f $(EXEC)
