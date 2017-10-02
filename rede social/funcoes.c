#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
enum erro
{
    semErro = 0,
    posInv = 1,
    listaCheia = 2,
    listaVazia = 3
};

lista *novaLista()
{
    lista *l = (lista *)malloc(sizeof(lista));
    l->tamanho = 0;
    l->inicio = NULL;
    return l;
}
void leString(char entrada[], int t)
{
    fgets(entrada, t, stdin);
    entrada[strlen(entrada) - 1] = '\0';
}
usuario *leUsuario()
{
    usuario *u = (usuario *)malloc(sizeof(usuario));
    printf("Digite nome:");
    leString(u->nome, 100);
    printf("Digite estado civil:");
    leString(u->estadoCivil, 50);
    printf("Digite a idade:");
    scanf("%d", &(u->idade));
    __fpurge(stdin);
    u->listaDeSeguidores = novaLista();
    u->listaDeSeguindo = novaLista();
    return u;
}
void mostraUsuario(usuario *u)
{
    printf("Nome:%s\n", u->nome);
    printf("Estado Civil:%s\n", u->estadoCivil);
    printf("Idade:%d\n", u->idade);
    printf("-----------------------\n");
}

int insereNaPos(lista *lista, int pos, nodo *n)
{
    int i;
    nodo *no = lista->inicio;
    nodo *ant = no;
    //inserir no inicio
    if (no == NULL || pos == 0)
    {
        n->prox = lista->inicio;
        lista->inicio = n;
        lista->tamanho++;
        return semErro;
    }
    for (i = 0; ant != NULL; i++)
    {
        if (i == pos)
        {
            n->prox = ant->prox;
            ant->prox = n;
            lista->tamanho++;
            return semErro;
        }
        ant = no;
        no = no->prox;
    }
}

int insereNoFim(lista *lista, nodo *n)
{
    insereNaPos(lista, lista->tamanho, n);
}
void imprime(lista *lista)
{
    int i;
    nodo *no = lista->inicio;
    printf("-----------------------\n");
    printf("Lista: \n");
    for (i = 0; no != NULL; i++)
    {
        printf("elemento: %d\n", i);
        mostraUsuario(no->pessoa);
        no = no->prox;
    }
}
void deletaLista(lista **lista)
{
    nodo *no = (*lista)->inicio;
    nodo *aux = NULL;

    while (no != NULL)
    {
        aux = no;
        no = no->prox;
        free(aux);
    }
    free(*lista);
    *lista = NULL;
}
void getPessoa(lista *lista, int pos, nodo *n)
{
    if (pos < 0 || pos > lista->tamanho - 1)
    {
        printf("lista vazia");
    }
    int i;
    nodo *no = lista->inicio;
    for (i = 0; no != NULL && i <= pos; i++)
    {
        if (i == pos)
        {
            n->pessoa = no->pessoa;
            n->prox = no->prox;
        }
        no = no->prox;
    }
}
int excluiNaPos(lista *lista, int pos)
{
    if (pos < 0 || pos >= lista->tamanho)
    {
        return posInv;
    }
    int i;
    nodo *no = lista->inicio;
    nodo *ant = NULL;
    for (i = 0; no != NULL && i < pos; i++)
    {
        ant = no;
        no = no->prox;
    }
    //retira o elemento
    if (ant == NULL) //quando quer retirar o primeiro elemento, pos=0
    {
        lista->inicio = no->prox;
        free(no);
        lista->tamanho--;
        return semErro;
    }
    else
    {
        ant->prox = no->prox;
        lista->tamanho--;
        free(no);
        return semErro;
    }
}
void excluiSeguidor(listaSeguidores *lista, nodo *n)
{
    int i;
   int pos = 0;
    nodo *no = lista->inicio;
    for (i = 0; no != NULL; i++)
    {   
        if (n->pessoa == n->pessoa)
        {
            puts("entrou");
            excluiNaPos(lista, i);
        }
        no = no->prox;
    }
}

void usuariosPadrao(lista *userLista)
{
    nodo *n1, *n2, *n3, *n4, *n5;
    usuario *u = (usuario *)malloc(sizeof(usuario));
    strcpy(u->nome, "Pedro");
    strcpy(u->estadoCivil, "Solteiro");
    u->idade = 23;
    u->listaDeSeguidores = novaLista();
    u->listaDeSeguindo = novaLista();
    n1 = (nodo *)malloc(sizeof(nodo));
    n1->pessoa = u;

    insereNoFim(userLista, n1);

    usuario *u2 = (usuario *)malloc(sizeof(usuario));
    strcpy(u2->nome, "Camila");
    strcpy(u2->estadoCivil, "Solteira");
    u2->idade = 21;
    u2->listaDeSeguidores = novaLista();
    u2->listaDeSeguindo = novaLista();
    n2 = (nodo *)malloc(sizeof(nodo));
    n2->pessoa = u2;
    insereNoFim(userLista, n2);

    usuario *u3 = (usuario *)malloc(sizeof(usuario));
    strcpy(u3->nome, "Joao");
    strcpy(u3->estadoCivil, "Casado");
    u3->idade = 33;
    u3->listaDeSeguidores = novaLista();
    u3->listaDeSeguindo = novaLista();
    n3 = (nodo *)malloc(sizeof(nodo));
    n3->pessoa = u3;
    insereNoFim(userLista, n3);

    usuario *u4 = (usuario *)malloc(sizeof(usuario));
    strcpy(u4->nome, "Maria");
    strcpy(u4->estadoCivil, "Casada");
    u4->idade = 34;
    u4->listaDeSeguidores = novaLista();
    u4->listaDeSeguindo = novaLista();
    n4 = (nodo *)malloc(sizeof(nodo));
    n4->pessoa = u4;
    insereNoFim(userLista, n4);

    usuario *u5 = (usuario *)malloc(sizeof(usuario));
    strcpy(u5->nome, "Carlos");
    strcpy(u5->estadoCivil, "Solteiro");
    u5->idade = 45;
    u5->listaDeSeguidores = novaLista();
    u5->listaDeSeguindo = novaLista();
    n5 = (nodo *)malloc(sizeof(nodo));
    n5->pessoa = u5;
    insereNoFim(userLista, n5);
}
void alteraUsuario(usuario *u)
{
    printf("Digite nome:");
    leString(u->nome, 100);
    printf("Digite estado civil:");
    leString(u->estadoCivil, 50);
    printf("Digite a idade:");
    scanf("%d", &(u->idade));
    __fpurge(stdin);
}