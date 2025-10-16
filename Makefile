# Nome do executável final
EXEC = programa

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -O2

# Diretórios
SRC_DIR = src
OBJ_DIR = obj

# ARQUIVOS-FONTE CORRIGIDOS: 
# Adicionado $(SRC_DIR)/Lista.c à lista de arquivos-fonte
SRC = $(SRC_DIR)/Programa.c \
      $(SRC_DIR)/Utilitarios.c \
      $(SRC_DIR)/Lista.c 

# Gera a lista de objetos correspondente
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Regra padrão
all: $(EXEC)

# Compilação e linkagem final
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compilação dos arquivos objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar objetos
clean:
	rm -rf $(OBJ_DIR)

# Limpar tudo
fclean: clean
	rm -f $(EXEC)

# Recompilar do zero
re: fclean all

.PHONY: all clean fclean re
