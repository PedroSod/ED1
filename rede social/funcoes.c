#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
enum erro
{
    semErro = 1,
    erro = 0,
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
    printf("-----------------------\n");
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
        printf("Cód. Usuário: %d\n", i);
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
int getPessoa(lista *lista, int pos, nodo *n)
{

    if ((lista->tamanho - 1) >= pos)
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
    else
    {
        puts("Entre com usuário valido. Obrigado!!\n");
        return erro;
    }
    return semErro;
}
int excluiNaPos(lista *lista, int pos)
{
    if (pos < 0 || pos >= lista->tamanho)
    {
        return erro;
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
        if (no->pessoa == n->pessoa)
        {
            excluiNaPos(lista, i);
        }
        no = no->prox;
    }
    
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