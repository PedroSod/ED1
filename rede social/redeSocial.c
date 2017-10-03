#include "funcoes.h"
#include "insereUsuariosPadrao.h"
#include <stdio.h>
#include <stdlib.h>
enum menu
{
    inserir = 1,
    buscar = 2,
    alterar = 3,
    deletar = 4,
    listar = 5,
    seguir = 6,
    deixarDeSeguir = 7,
    listarSeguidores = 8,
    listarSeguindo = 9,
    sair = 0
};

const lista *userLista;
void funcoesPadroes()
{
    int op;
    do
    {
        printf("--Funções Gerais--\no que deseja fazer?\n(%d)sair\n(%d)inserir usuário\n(%d)buscar usuário\n(%d)altera\n(%d)deletar usuário\n(%d)listar\n", sair, inserir, buscar, alterar, deletar, listar);
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
            insereNoFim(userLista, val);
            break;
        case buscar:
            val = (nodo *)malloc(sizeof(nodo));
            imprime(userLista);
            printf("Informe o Código do Usuário:");
            scanf("%d", &pos);
            if (getPessoa(userLista, pos, val) == 1)
            {
                system("clear");
                mostraUsuario(val->pessoa);
                funcoesUsuario(val);
            }
            else
            {
                funcoesPadroes();
            }
            break;
        case deletar:
            imprime(userLista);
            printf("Informe o Código do Usuário (de 0 a %d):", userLista->tamanho - 1);
            scanf("%d", &pos);
            system("clear");
            if (excluiNaPos(userLista, pos) != 1)
            {
                puts("Entre com usuário valido. Obrigado!!\n");
                funcoesPadroes();
            }
            break;
        case listar:
            imprime(userLista);
            break;
        case alterar:
            imprime(userLista);
            val = (nodo *)malloc(sizeof(nodo));
            printf("Informe o Código do Usuário:");
            scanf("%d", &pos);
            __fpurge(stdin);
            if (getPessoa(userLista, pos, val) == 1)
            {
                mostraUsuario(val->pessoa);
                alteraUsuario(val->pessoa);
                mostraUsuario(val->pessoa);
            }
            else
            {
                funcoesPadroes();
            }
            break;
        default:
            deletaLista(&userLista);
            return 1;
        }
    } while (op != sair);
}

void funcoesUsuario(nodo *nodoUsuario)
{
    int op;
    do
    {
        printf("--Funções do Usuário--\no que deseja fazer?\n(%d)sair\n(%d)Seguir\n(%d)Deixar de Seguir\n(%d)listar seguidores\n(%d)listar seguindo\n", sair, seguir, deixarDeSeguir, listarSeguidores, listarSeguindo);
        scanf("%d", &op);
        __fpurge(stdin);
        switch (op)
        {
            int pos, pos2;
            nodo *val, *v2;
        case sair:
            return 1;
        case seguir:
            val = (nodo *)malloc(sizeof(nodo));
            v2 = (nodo *)malloc(sizeof(nodo));
            v2->pessoa = nodoUsuario->pessoa;
            imprime(userLista);
            printf("Informe o Código do Usuário  ser seguido:");
            scanf("%d", &pos2);
            __fpurge(stdin);
            if (getPessoa(userLista, pos2, val) == 1)
            {
                mostraUsuario(val->pessoa);
                insereNoFim(v2->pessoa->listaDeSeguindo, val);
                insereNoFim(val->pessoa->listaDeSeguidores, v2);
            }
            else
            {
                funcoesUsuario(nodoUsuario);
            }
            break;
        case deixarDeSeguir:
            val = (nodo *)malloc(sizeof(nodo));
            v2 = (nodo *)malloc(sizeof(nodo));
            v2->pessoa = nodoUsuario->pessoa;            
            imprime(v2->pessoa->listaDeSeguindo);
            printf("Informe o Código do Usuário a deixar de seguir:");
            scanf("%d", &pos2);
            __fpurge(stdin);
            if (getPessoa(v2->pessoa->listaDeSeguindo, pos2, val) == 1)
            {
                excluiNaPos(v2->pessoa->listaDeSeguindo, pos2);
                excluiSeguidor(val->pessoa->listaDeSeguidores, v2);
            }
            else
            {
                funcoesUsuario(nodoUsuario);
            }
            break;
        case listarSeguindo:
            printf("Seguindo:\n");
            imprime(nodoUsuario->pessoa->listaDeSeguindo);
            break;
        case listarSeguidores:
            printf("Seguidores:\n");
            imprime(nodoUsuario->pessoa->listaDeSeguidores);
            break;
        default:
            funcoesPadroes();
            return 1;
        }
    } while (op != sair);
}

int main()
{

    userLista = novaLista();
    usuariosPadrao(userLista);
    funcoesPadroes();
    return 1;
}
