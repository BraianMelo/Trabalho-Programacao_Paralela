# Nome do executável final
EXEC = bin/Programa.out

# Compilador MPI
CC = mpicc

# Flags de compilação
CFLAGS = -Wall -Wextra -O2 -pg

# Diretórios
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
BUILD_DIR = build

# Fontes e objetos
SRC = $(SRC_DIR)/Programa.c \
	  $(SRC_DIR)/Utilitarios.c \
	  $(SRC_DIR)/Lista.c \
	  $(SRC_DIR)/Crivo_de_Eratostenes.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Regra padrão
all: $(EXEC)

# Linkagem final
$(EXEC): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^ -lm

# Compilação dos .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Executa e gera relatório do gprof
run: $(EXEC)
	@mkdir -p $(BUILD_DIR)
	@echo "Executando o programa..."
	@mpirun -np 4 ./$(EXEC) 100000 p
	@echo "\nGerando relatório de profiling..."
	@gprof ./$(EXEC) gmon.out > $(BUILD_DIR)/relatorio.txt
	@mv gmon.out $(BUILD_DIR)/
	@echo "Relatório gerado em $(BUILD_DIR)/relatorio.txt"

# Limpeza
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(BIN_DIR)
	rm -rf $(BUILD_DIR)
	rm primos.txt

re: fclean all

.PHONY: all clean fclean re relatorio
