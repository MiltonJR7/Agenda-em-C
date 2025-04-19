# Agenda de Contatos em C (modo texto)

Este é um projeto simples de **agenda de contatos** desenvolvido em linguagem **C**, com foco em prática de manipulação de **arquivos**, **structs** e **vetores**.  
Ideal para iniciantes que estão aprendendo a trabalhar com entrada/saída e persistência de dados.

## ✨ Funcionalidades

- Cadastrar contatos
- Listar todos os contatos salvos
- Editar um contato existente
- Excluir um contato da lista
- Salvar os dados em um arquivo `.txt`
- Persistência de dados entre execuções

## 📁 Estrutura do Contato

Cada contato possui:
- Nome (string)
- E-mail (string)
- Telefone (int)

## 💾 Armazenamento

Os dados são gravados em um arquivo `.txt` localizado em:

C:/Faculdade/C/PROJETOS/GITHUB/arquivos/agenda.txt

markdown
Copiar
Editar

> O caminho pode ser alterado no código, se necessário.

## 🧠 Conceitos Usados

- `struct` para representar os contatos
- Vetores para armazenar os dados em memória
- Manipulação de arquivos com `fopen`, `fprintf`, `fgets`, etc
- Menus interativos com `switch`
- Funções para modularizar as ações

## 🚀 Possíveis Melhorias Futuras

- Carregar os contatos do arquivo ao iniciar o programa
- Usar `char` para o telefone (permitir DDD e símbolos como `-`)
- Melhorar o layout do menu
- Ordenar contatos por nome
- Buscar contatos por nome ou telefone

---

Feito como exercício de prática e aprendizado! 💻
