# Projeto TList - Lista Contígua em C++

![C++](https://img.shields.io/badge/Language-C++-blue) ![License](https://img.shields.io/badge/License-MIT-green)

## Descrição

Este projeto implementa uma **lista contígua (vetor dinâmico)** em C++ chamada `TList`, que permite a realização de operações básicas de uma lista linear, como:

- Inserir elementos no final ou em posições específicas.
- Remover o último elemento ou elementos em posições específicas.
- Ordenar a lista usando **Insertion Sort**.
- Consultar elementos e imprimir a lista de forma visual.

O projeto foi desenvolvido como prática de **estruturas de dados** e demonstra o uso de **alocação dinâmica de memória**, controle de tamanho e capacidade da lista, e manipulação de arrays em C++.

## Funcionalidades

- Inicialização da lista com tamanho definido pelo usuário.
- Inserção de elementos no final ou em uma posição específica.
- Remoção de elementos.
- Impressão da lista no console em formato visual `[ elem ] -> [ elem ] -> NULL`.
- Ordenação da lista (Insertion Sort).
- Checagem de limite de capacidade antes de inserir elementos.

## Estrutura do Projeto

TList/
├── main.cpp # Programa principal com menu interativo
├── TList.h # Declaração da classe TList
├── TList.cpp # Implementação da classe TList
├── README.md # Este arquivo


## Como Usar

1. Clone o repositório:

```bash
git clone https://github.com/seu_usuario/nome_do_repositorio.git

2 Compile o projeto usando um compilador C++ (ex: g++):

g++ main.cpp TList.cpp -o TList

3 Execute o programa:
./TList


4 Siga o menu interativo para criar, inserir, remover e ordenar elementos na lista.

Observações

A lista é contígua, ou seja, utiliza um vetor alocado dinamicamente. Quando a lista atinge sua capacidade máxima, não é possível inserir novos elementos sem reinicializar.

A impressão é estilizada no console para melhor visualização da estrutura da lista.


5 Exemplo de execução:
Digite o tamanho inicial da lista: 3
Lista inicializada com capacidade 3.

Escolha uma opcao: 1
Quantos elementos deseja inserir? 3
Digite o numero 1: 2
Digite o numero 2: 5
Digite o numero 3: 8

Escolha uma opcao: 5
Lista: [ 2 ] -> [ 5 ] -> [ 8 ] -> NULL


Licença
Prof. Laércio Pioli Junior