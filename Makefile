# Nom de l'exécutable
TARGET = main

# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -std=c99 -Iheaders 

# Librairies nécessaires à raylib
LIBS = -lraylib -lm -ldl -lpthread -lX11 -lGL -lGLU

# Fichiers sources et objets
SRC = $(wildcard srcs/*.c)
OBJ = $(SRC:.c=.o)

# Règle par défaut
all: $(TARGET)

# Compilation de l'exécutable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(LIBS)

# Compilation des .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage
clean:
	rm -f $(OBJ) $(TARGET)

