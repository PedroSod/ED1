#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
#include "insereUsuariosPadrao.h"

void usuariosPadrao2(nodo *n1,nodo *n2, nodo *n3, nodo *n4, nodo *n5){
    
        nodo *s1, *s2, *s3, *s4, *s5, *s;
        s = (nodo *)malloc(sizeof(nodo));
        s1 = (nodo *)malloc(sizeof(nodo));
        s2 = (nodo *)malloc(sizeof(nodo));
        s3 = (nodo *)malloc(sizeof(nodo));
        s4 = (nodo *)malloc(sizeof(nodo));
        s5 = (nodo *)malloc(sizeof(nodo));
    
        s->pessoa = n2->pessoa;
        s->prox = n2->prox;
        s4->pessoa = n2->pessoa;
        s4->prox = n2->prox;
        s5->pessoa = n1->pessoa;
        s5->prox = n1->prox;
    
        s1->pessoa = n1->pessoa;
        s1->prox = n1->prox;
        s2->pessoa = n4->pessoa;
        s2->prox = n4->prox;
        s3->pessoa = n2->pessoa;
        s3->prox = n2->prox;
    
        insereNoFim(s->pessoa->listaDeSeguindo, s1);
        insereNoFim(s1->pessoa->listaDeSeguidores, s);
    
        insereNoFim(s4->pessoa->listaDeSeguindo, s2);
        insereNoFim(s2->pessoa->listaDeSeguidores, s4);
    
        insereNoFim(s5->pessoa->listaDeSeguindo, s3);
        insereNoFim(s3->pessoa->listaDeSeguidores, s5);
    }
    
    void usuariosPadrao(lista *userLista)
    {
        nodo *n1, *n2, *n3, *n4, *n5;
    
        nodo *s1, *s2, *s3, *s4, *s5, *s;
    
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
    
        s = (nodo *)malloc(sizeof(nodo));
        s1 = (nodo *)malloc(sizeof(nodo));
        s2 = (nodo *)malloc(sizeof(nodo));
        s3 = (nodo *)malloc(sizeof(nodo));
        s4 = (nodo *)malloc(sizeof(nodo));
        s5 = (nodo *)malloc(sizeof(nodo));
    
        s->pessoa = n5->pessoa;
        s->prox = n5->prox;
        s4->pessoa = n5->pessoa;
        s4->prox = n5->prox;
        s5->pessoa = n5->pessoa;
        s5->prox = n5->prox;
    
        s1->pessoa = n1->pessoa;
        s1->prox = n1->prox;
        s2->pessoa = n2->pessoa;
        s2->prox = n2->prox;
        s3->pessoa = n3->pessoa;
        s3->prox = n3->prox;
    
        insereNoFim(s->pessoa->listaDeSeguindo, s1);
        insereNoFim(s1->pessoa->listaDeSeguidores, s);
    
        insereNoFim(s4->pessoa->listaDeSeguindo, s2);
        insereNoFim(s2->pessoa->listaDeSeguidores, s4);
    
        insereNoFim(s5->pessoa->listaDeSeguindo, s3);
        insereNoFim(s3->pessoa->listaDeSeguidores, s5);
    
        usuariosPadrao2(n1, n2, n3, n4, n5);
    }