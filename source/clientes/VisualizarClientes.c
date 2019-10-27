#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include "../../libs/StructClie.h"
/* #include <conio.h> */



void LerClie(){

    FILE *infile;
    struct cliente input;
    infile = fopen("./data/clientes.dat", "r");

    // printf("\n =================== %s =================== \n");
    while(fread(&input, sizeof(struct cliente), 1, infile)){

            printf ("\n Nome = %s \n Endereço = %s\n Telefone= %s\n", input.nome, input.endereco, input.telefone);

    };

    fclose (infile);
}

void LerClientes(){

    printf("\n ==============================================");
    printf("\n ================= Clientes ===================");
    printf("\n ==============================================\n");

    LerClie();


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
    LerClientes();

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
