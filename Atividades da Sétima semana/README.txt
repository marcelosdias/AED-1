Disciplina: Algoritmos e Estruturas de Dados 1
Aluno: Marcelo da Silva Dias
E-mail: marcelo.sdias@inf.ufpel.edu.br
GitHub: https://github.com/marcelosdias/AED-1

Conteúdo do diretório:
- Imagens
    - Imagens dos testes feitos no DrMemory e Valgrind
    - Exercicio 1 da aula 8
        - aula8Exercicio1.jpg
    - Exercicio 1 da aula 9
        - aula9Exercicio1.jpg

- Exercicio 2 da aula 8
    - aula8Exercicio2.txt

- Arquivos main do Exercicio 3: 
    - aula8Exercicio3.1.c
    - aula8Exercicio3.2.c

- Biblioteca com as funções
    - funcoesAVL.h e funcoesAVL.c

Compilação:
- Exercicio3.1
    - make aula8Exercicio3.1
- Exercicio3.2
    - make aula8Exercicio3.2

- Caso não consiga com o makefile utilize:
    - Para o aula8Exercicio3.1
        - gcc -c funcoesAVL.c -Wall
	    - gcc funcoesAVL.o aula8Exercicio3.1.c -o aula8Exercicio3.1 -Wall;./aula8Exercicio3.1
    - Para o aula8Exercicio3.2
        - gcc -c funcoesAVL.c -Wall
	    - gcc funcoesAVL.o aula8Exercicio3.2.c -o aula8Exercicio3.2 -Wall;./aula8Exercicio3.2
