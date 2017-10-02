#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
enum menu
{
    inserir = 1,
    buscar = 2,
    deletar = 3,
    seguir = 4,
    deixarDeSeguir = 5,
    listar = 6,
    alterar = 7,
    sair = 0
};

int main()
{
    int op;
    lista *userLista = novaLista();
    usuariosPadrao(userLista);

    do
    {
        printf("--Listas (simplesmente encadeada)--\no que deseja fazer?\n(%d)sair\n(%d)inserir usuário\n(%d)buscar usuário\n(%d)deletar usuário\n(%d)Seguir\n(%d)Deixar de Seguir\n(%d)listar\n(%d)altera\n", sair, inserir, buscar, deletar, seguir, deixarDeSeguir, listar, alterar);
        scanf("%d", &op);
        __fpurge(stdin);
        switch (op)
        {
            int pos, pos2;
            nodo *val, *v2;
        case sair:
            return 1;
        case inserir:
            val = (nodo *)malloc(sizeof(nodo));
            val->pessoa = leUsuario();
            printf("inserindo... status:%d\n", insereNoFim(userLista, val));
            break;
        case buscar:
            val = (nodo *)malloc(sizeof(nodo));
            printf("informe a pos:");
            scanf("%d", &pos);
            getPessoa(userLista, pos, val);
            system("clear");
            mostraUsuario(val->pessoa);
            break;
        case deletar:
            printf("informe a posicao (de 0 a %d):", userLista->tamanho - 1);
            scanf("%d", &pos);
            system("clear");
            printf("deletando... status:%d\n", excluiNaPos(userLista, pos));
            break;
        case seguir:
            val = (nodo *)malloc(sizeof(nodo));
            v2 = (nodo *)malloc(sizeof(nodo));
            printf("informe a pos para buscar usuario:");
            scanf("%d", &pos);
            __fpurge(stdin);
            getPessoa(userLista, pos, v2);
            mostraUsuario(v2->pessoa);
            printf("informe a pessoa a ser seguida:");
            scanf("%d", &pos2);
            __fpurge(stdin);
            getPessoa(userLista, pos2, val);
            mostraUsuario(val->pessoa);
            printf("inserindo... status:%d\n", insereNoFim(v2->pessoa->listaDeSeguindo, val));
            printf("inserindo... status:%d\n", insereNoFim(val->pessoa->listaDeSeguidores, v2));
            imprime(v2->pessoa->listaDeSeguindo);
            imprime(val->pessoa->listaDeSeguidores);
            break;
        case deixarDeSeguir:
            val = (nodo *)malloc(sizeof(nodo));
            v2 = (nodo *)malloc(sizeof(nodo));
            printf("informe a pos para buscar usuario:");
            scanf("%d", &pos);
            __fpurge(stdin);
            getPessoa(userLista, pos, v2);
            mostraUsuario(v2->pessoa);
            printf("Seguindo:\n");
            imprime(v2->pessoa->listaDeSeguindo);
            printf("informe a pessoa deixar de seguir:");
            scanf("%d", &pos2);
            __fpurge(stdin);
            getPessoa(v2->pessoa->listaDeSeguindo, pos2, val);
            printf("Seguidores:\n");
            imprime(val->pessoa->listaDeSeguidores);
            excluiNaPos(v2->pessoa->listaDeSeguindo, pos2);
            excluiSeguidor(val->pessoa->listaDeSeguidores, v2);
            printf("Seguindo:\n");            
            imprime(v2->pessoa->listaDeSeguindo);
            printf("Seguidores:\n");            
            imprime(val->pessoa->listaDeSeguidores);
            break;
        case listar:
            imprime(userLista);
            break;
        case alterar:
            val = (nodo *)malloc(sizeof(nodo));
            printf("informe a pos:");
            scanf("%d", &pos);
            __fpurge(stdin);
            getPessoa(userLista, pos, val);
            mostraUsuario(val->pessoa);
            alteraUsuario(val->pessoa);
            mostraUsuario(val->pessoa);
            break;
        default:
            deletaLista(&userLista);
            return 1;
        }
    } while (op != sair);
    return 1;
}
