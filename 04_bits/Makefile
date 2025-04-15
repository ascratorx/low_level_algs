# Compiler und Flags
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Zielprogramme
TARGET = 04_fibo

# Quellcode-Dateien
SRC = 04_fibo.c

# Objektdateien
OBJ = $(SRC:.c=.o)

# Standard-Ziel: Beide Programme erstellen
all: $(TARGET)

# Erstellen von coin_change_problem
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
