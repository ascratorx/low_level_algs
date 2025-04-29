# Compiler und Flags
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Zielprogramme
TARGET = 02_necklaces

# Quellcode-Dateien
SRC = 02_necklaces.c

# Objektdateien
OBJ = $(SRC:.c=.o)

# Standard-Ziel: Beide Programme erstellen
all: $(TARGET)

# Erstellen von alg_muenzen_count
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lm

# Kompilieren der .c-Dateien in .o-Dateien
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Bereinigen
clean:
	rm -f $(OBJ) $(TARGET)

# Alles neu kompilieren
rebuild: clean all
