#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
/* #include <conio.h> */
#include "../../libs/LerEst.h"

void LerEstoque(){

printf("   -----------------------------  Visualizar Estoque  ------------------------------\n\n");
    LerEst();
    
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
    LerEstoque();

    return 0;
}