# C++ WebAssembly Text Editor

Editor de texto experimental desenvolvido em C++ com execução no navegador utilizando WebAssembly.

## Objetivo

Explorar integração entre aplicações C++ e interfaces web modernas, mantendo lógica de processamento em código nativo e interface no navegador.

## Tecnologias

- C++
- WebAssembly (Wasm)
- JavaScript
- HTML
- CSS

## Arquitetura

O projeto separa claramente:

Interface Web
↓
JavaScript
↓
WebAssembly
↓
Motor em C++

O motor em C++ é responsável pelo processamento e manipulação de dados, enquanto a interface é construída em HTML/CSS.

## Conceitos explorados

- Gerenciamento manual de memória
- Concorrência com threads e mutex
- Integração C++ ↔ WebAssembly
- Estruturas de dados com std::vector e std::map
- Separação de responsabilidades entre backend e interface

## Como executar

1. Compilar o código C++ para WebAssembly
2. Abrir `index.html` no navegador

## Autor

Moisés Santos
