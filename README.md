# C-CRUDSystem-A3

# Sistema de Gerenciamento Acadêmico em C

## Descrição
Este repositório contém o projeto CRUD (Create, Read, Update, Delete) para um sistema de gerenciamento acadêmico desenvolvido em linguagem C. O projeto é uma avaliação para a disciplina de Sistemas Computacionais e Segurança, com o objetivo de praticar operações CRUD em estruturas de dados em memória, utilizando arrays e ponteiros.

## Funcionalidades
O projeto inclui quatro principais funcionalidades, cada uma implementada como uma "User Story":

### User Story 1: Cadastro de TipoCurso
- **Objetivo**: Gerenciar tipos de cursos disponíveis.
- **CRUD**: Adicionar, visualizar, modificar e remover tipos de cursos.
- **Validações**: Verificação da unicidade do código do curso.

### User Story 2: Cadastro de Aluno
- **Objetivo**: Manter registros atualizados dos estudantes.
- **CRUD**: Adicionar, visualizar, modificar e remover alunos.
- **Associações**: Cada aluno é vinculado a um código de tipo de curso válido.
- **Validações**: Verificação da unicidade da matrícula.

### User Story 3: Cadastro de Disciplina
- **Objetivo**: Atualizar a oferta de disciplinas da instituição.
- **CRUD**: Adicionar, visualizar, modificar e remover disciplinas.
- **Associações**: Cada disciplina é vinculada a um tipo de curso.
- **Validações**: Verificação da unicidade do código da disciplina.

### User Story 4: Cadastro de InscricaoDisciplina
- **Objetivo**: Controlar as matrículas dos alunos em disciplinas.
- **CRUD**: Adicionar, visualizar, modificar e remover inscrições.
- **Validações**: Verificação da existência do aluno e da disciplina, e data de inscrição.

## Instruções de Uso
- Clone o repositório.
- Compile o código usando um compilador C padrão.
- Execute o programa para interagir com o sistema através de um menu de console.

## Critérios de Avaliação
- Cada implementação CRUD vale 10 pontos.
- Desconto de 2 pontos por cadastro sem verificação de domínio.

## Contribuições
- Este é um projeto de grupo para fins acadêmicos. Contribuições externas não são esperadas, mas feedback é bem-vindo.

## Autores
Pedro Soares
Marcel Brasileiro
Hector Valente
Lucas Torres
Nathan Munoz

## Licença
- Este projeto é distribuído sob a Licença MIT.

## Data Limite
- 28/11/2023

## Contato
- E-mail do responsável pelo projeto: [brasileirodev@gmail.com](mailto:brasileirodev@gmail.com)

## Agradecimentos
- Agradece-se aos professores e colegas de classe pelo suporte durante o desenvolvimento do projeto.
