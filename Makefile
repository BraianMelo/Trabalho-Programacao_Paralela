# Nome do executável final
EXEC = Programa.out

# Compilador
CC = gcc

# Flags de compilação. O -pg (para profiling) foi adicionado aqui.
CFLAGS = -Wall -Wextra -O2 -pg

# Diretórios
SRC_DIR = src
OBJ_DIR = obj

# ARQUIVOS-FONTE
SRC = $(SRC_DIR)/Programa.c \
	  $(SRC_DIR)/Utilitarios.c \
	  $(SRC_DIR)/Lista.c

# Gera a lista de objetos correspondente
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Regra padrão
all: $(EXEC)

# Compilação e linkagem final
# O -lm é a flag para linkar com a biblioteca matemática
# O -pg é usado aqui automaticamente via CFLAGS
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lm

# Compilação dos arquivos objeto
# O -pg é usado aqui automaticamente via CFLAGS
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar objetos
clean:
	rm -rf $(OBJ_DIR)

# Limpar tudo
fclean: clean
	rm -f $(EXEC)
	rm gmon.out

# Recompilar do zero
re: fclean all

.PHONY: all clean fclean re
