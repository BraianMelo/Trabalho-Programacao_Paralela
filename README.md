# Trabalho de Programacao Paralela
Trabalho referente à disciplina optativa de Programação Paralela do curso de Ciência da Computação da **UFSJ**.

## Objetivo
O objetivo deste trabalho é a implementação paralela, usando o modelo mestre-escravo com MPI, do algoritmo Crivo de Eratóstenes para identificar todos os números primos até um inteiro N.

## Pré-Requisitos
Para compilar e executar o projeto, você precisará dos seguintes softwares instalados em seu ambiente:

- **Compilador C:** GCC (GNU Compiler Collection).
- **MPI:** Implementação do Message Passing Interface (ex: OpenMPI ou MPICH).
- **Ferramenta de Build:** GNU Make.

## Como Compilar e Executar
Para compilar o projeto e gerar o executável, acesse a pasta raiz e utilize o make:
```bash
user-pc$ make
```

Após isso será gerado, na pasta raiz, o arquivo Programa.out, o executável. Para conseguir rodar o programa, bastar executar o seguinte comando: 
```bash
user-pc$ ./Programa.out
```