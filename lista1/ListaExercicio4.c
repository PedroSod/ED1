#include <stdlib.h>
#include <stdio.h>

int main()
{
    float vlrBanana, vlrUva;
    int qtdBanana,qtdUva;
    float totBanana, totUva;
    printf("Informe o valor dos seguintes dados:\n");
    printf("Preço da Banana:");
    scanf("%f", &vlrBanana);
    __fpurge(stdin); 
    printf("Quantidade da Banana:");
    scanf("%d", &qtdBanana);
    __fpurge(stdin); 
    printf("Preço da uva:");
    scanf("%f", &vlrUva);
    __fpurge(stdin); 
    printf("Quantidade da Uva:");
    scanf("%d", &qtdUva);
    totBanana = (qtdBanana * vlrBanana);
    totUva = (qtdUva * vlrUva);
    printf("________________________________________________________\n");
    printf("Produto :Preço  Unitário  :Quantidade     :Preço Total\n");
    printf("________:_________________:_______________:_____________\n");
    printf("Banana  :R$ %.2f          :       %d      :R$      %.2f\n", vlrBanana, qtdBanana,totBanana);
    printf("Uva     :R$ %.2f          :       %d      :R$      %.2f\n", vlrUva, qtdUva,totUva);
    printf("        :                 :Sub_Total     :R$      %.2f\n", (totUva + totBanana));
    printf("________:_________________:______________:______________\n");
    printf("        :Imposto(5%)                     :R$      %.2f\n", ((totUva + totBanana)*0.05));
    printf("________:________________________________:______________\n");
    printf("                Total                     R$      %.2f\n", 
    (((totUva + totBanana)*0.05) + (totUva + totBanana)));
    
    return 1;
}