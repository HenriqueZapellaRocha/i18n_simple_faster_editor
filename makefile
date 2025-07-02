TARGET = main
CC      = gcc
CFLAGS  = -Wall -Wextra -O3 -Iinclude

OBJ_DIR = build

# Encontra recursivamente todos os .c (exceto dentro de build/)
SRC := $(shell find . -type f -name '*.c' -not -path "./$(OBJ_DIR)/*")
# Converte cada .c em build/arquivo.o mantendo a estrutura
define to_obj
  $(OBJ_DIR)/$(1:.c=.o)
endef
OBJ := $(foreach src,$(SRC),$(call to_obj,$(src)))

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	@echo "Linkando: $^"
	$(CC) $(CFLAGS) $^ -o $@

# Regra genérica para compilar cada .c em .o
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "Compilando $< -> $@"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)