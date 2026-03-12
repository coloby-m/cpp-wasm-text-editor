# C++ WebAssembly Text Editor

Editor de texto experimental desenvolvido em **C++** com execução no navegador utilizando **WebAssembly (WASM)**.

O projeto explora a integração entre código nativo C++ e interfaces web modernas, permitindo que a lógica principal seja executada com alta performance diretamente no navegador.

---

## Funcionalidades

- Registro de textos
- Busca por título
- Busca por conteúdo
- Sistema de favoritos
- Estruturas FIFO e LIFO
- Execução paralela com threads
- Sincronização com mutex
- Multithreading com pthread (em WebAssembly)

---

## Tecnologias

- C++
- WebAssembly (WASM)
- JavaScript
- HTML
- CSS

---

## Arquitetura

O projeto separa claramente as responsabilidades entre interface e motor de processamento:

Interface Web  
↓  
JavaScript  
↓  
WebAssembly  
↓  
Motor em C++

O motor em **C++** é responsável pelo processamento e manipulação de dados, enquanto a interface é construída em **HTML/CSS** e controlada por **JavaScript**.

---

## Conceitos explorados

- Gerenciamento manual de memória
- Concorrência com **threads e mutex**
- Integração **C++ ↔ WebAssembly**
- Estruturas de dados com **std::vector** e **std::map**
- Comunicação entre **JavaScript e código compilado em WASM**
- Separação de responsabilidades entre backend e interface

---

## Objetivo do Projeto

Este projeto foi criado como parte do meu estudo avançado em:

- C++
- Sistemas de alto desempenho
- WebAssembly
- Programação concorrente

O objetivo é explorar a integração entre **aplicações C++ e interfaces web**, mantendo a lógica de processamento em código nativo enquanto a interface roda no navegador.

Também faz parte da minha preparação para projetos mais avançados envolvendo **Inteligência Artificial e sistemas de baixo nível**.

---

## Como executar

1. Baixe os repositorios
2. instale o pytho no terminal windows usando o comando winget install -e --id Python.Python.3.12, E no lunux  suto apt install python 3.12
3. http://localhost:9090/WebAssemnly.html

---

## Autor

Moisés Santos
