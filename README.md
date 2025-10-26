# Trabalho de Programação Paralela

Este projeto foi desenvolvido para a disciplina optativa de **Programação Paralela** do curso de Ciência da Computação da **UFSJ**.

## Objetivo

O objetivo deste trabalho é implementar o **Crivo de Eratóstenes** de forma **paralela**, utilizando o modelo **mestre-escravo** com **MPI**, para identificar todos os números primos até um inteiro \(N\).

## Pré-Requisitos

Antes de compilar e executar o projeto, verifique se você possui os seguintes softwares instalados:

- **Compilador C:** GCC (GNU Compiler Collection).  
- **MPI:** Implementação do Message Passing Interface (ex: OpenMPI ou MPICH).  
- **Ferramenta de Build:** GNU Make.

## Estrutura do Projeto

O projeto está organizado da seguinte forma:
```bash
Trabalho-Programacao_Paralela/
│
├─ bin/ → Contém o executável gerado (Programa.out)
├─ obj/ → Arquivos objeto gerados durante a compilação
├─ src/ → Código-fonte do projeto
│ ├─ Crivo_de_Eratostenes.c
│ ├─ Crivo_de_Eratostenes.h
│ ├─ Lista.c
│ ├─ Lista.h
│ ├─ Programa.c
│ ├─ Utilitarios.c
│ └─ Utilitarios.h
├─ Makefile → Script para compilação
├─ primos.txt → Arquivo de saída com os primos (gerado pelo programa)
├─ README.md → Este arquivo
└─ gmon.out → Arquivo de profiling (gerado opcionalmente)
```

**Observações: bin/** e **obj/** são criados automaticamente após a compilação.  


## Compilação

Na raiz do projeto, utilize o `make` para compilar o código e gerar o executável:

```bash
$ make
```
Isso irá gerar o arquivo `Programa.out` na pasta **bin/**.

## Execução
Para executar o programa, use o comando:
```bash
$ mpirun -np 4 ./Programa.out <N> <modo>
```
Onde as flags significa o seguinte:

* **<N>:** quantidade de números a serem calculados.
* **<Modo>**: o modo que pode ser:
* * **s:** modo sequencial.
* * **p:** modo paralelo.

**Observação:** O número de processos (*-np 4*) pode ser alterado conforme o número de núcleos ou threads que você deseja utilizar para o modo paralelo

## Grupo
**Braian Melo**

**Leonardo Ribeiro**
