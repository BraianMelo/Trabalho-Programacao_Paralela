# Nome do executável final
EXEC = Programa.out

# Compilador (use o compilador MPI)
CC = mpicc

# Flags de compilação (mantém profiling se quiser)
CFLAGS = -Wall -Wextra -O2 -pg

# Diretórios
SRC_DIR = src
OBJ_DIR = obj

# Arquivos-fonte
SRC = $(SRC_DIR)/Programa.c \
	  $(SRC_DIR)/Utilitarios.c \
	  $(SRC_DIR)/Lista.c \
	  $(SRC_DIR)/Crivo_de_Eratostenes.c

# Gera a lista de objetos correspondente
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Regra padrão
all: $(EXEC)

# Compilação e linkagem final
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lm

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
	rm -f gmon.out

# Recompilar do zero
re: fclean all

.PHONY: all clean fclean re
