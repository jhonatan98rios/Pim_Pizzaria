#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
/* #include <conio.h> */
#include "../../libs/LerEst.h"
#include "../../libs/voltar.h"
#include "../../libs/structs.h"
#include "../../libs/cabSys.h"

void LerEstoque(){

printf("   -----------------------------  Visualizar Estoque  ------------------------------\n\n");
    LerEst();
    
    printf("\n\n");
};

int main()
{
    //Define o padrao UTF-8
    setlocale(LC_ALL, "Portuguese_Brasil");
    //Define a cor azul do terminal
    //system("color 1F");
    //define o titulo da janela do prompt
    //system("title Menu");

    cab();
    LerEstoque();

    int continuar;

    printf("   ---------------------------------------------------------------------------------\n");
    printf("   Deseja voltar ao menu?\n");
    printf("   [1] Sim \n");
    printf("   [0] Nao\n");
    scanf("%d", &continuar);
    if(continuar == 1){
        system(".\\dist\\operacional\\MenuEstoque.exe");
    }else{
        printf("--------------------\n");
        printf("| Programa Encerrado |\n");
        printf("--------------------\n");
        
    }


    return 0;
}