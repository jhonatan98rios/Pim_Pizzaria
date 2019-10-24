#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
/* #include <conio.h> */
#include "../../libs/LerProm.h" /* Essa é a classe de produto */

void LerPromocoes(){

    printf("\n ==============================================");
    printf("\n ================= Promocoes ===================");
    printf("\n ==============================================\n");

    LerProm( "Pizzas" , 1);
    LerProm( "Bebidas" , 2);
    LerProm( "Doces" , 3);

    printf("\n\n");
};

int main()
{
    //Define o padrão UTF-8
    setlocale(LC_ALL, "Portuguese_Brasil");
    //Define a cor azul do terminal
    //system("color 1F");
    //define o titulo da janela do prompt
    //system("title Menu");

    printf("\e[1;1H\e[2J");
    LerPromocoes();

    /* Isso se tornará uma biblioteca de cabeçalho */

    int continuar;

    printf("Deseja voltar ao menu? \n [1] Sim \n [2] Nao\n");
    scanf("%d", &continuar);
    if(continuar == 1){
        system("./source/menu");
    }else{
        printf("Programa Encerrado");
    }

    return 0;
}
