#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[100];
    int idade;
    char estadoCivil[50];
    struct listaSeguidores *listaDeSeguidores;
    struct listaSeguindo *listaDeSeguindo;

} usuario;

typedef struct no
{
    usuario *pessoa;
    struct no *prox;

} nodo;

typedef struct
{
    int tamanho;
    nodo *inicio;
} lista;

typedef struct
{
    int tamanho;
    nodo *inicio;
} listaSeguidores;

typedef struct
{
    int tamanho;
    nodo *inicio;
} listaSeguindo;

lista *novaLista();

void leString(char entrada[], int t);

usuario *leUsuario();

int getPessoa(lista *, int, nodo *);

void mostraUsuario(usuario *);

int insereNaPos(lista *, int, nodo *);

int insereNoFim(lista *, nodo *);

void imprime(lista *);

void deletaLista(lista **);

int excluiNaPos(lista *, int);

void excluiSeguidor(listaSeguidores *, nodo *);

void usuariosPadrao(lista *);
void alteraUsuario(usuario *);
