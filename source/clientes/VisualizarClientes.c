#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include "../../libs/structs.h"
#include "../../libs/voltar.h"
#include "../../libs/Mensagem.h"
#include "../../libs/cabSys.h"
/* #include <conio.h> */



void LerClie(){

    FILE *infile;
    struct cliente input;
    infile = fopen("./data/clientes.dat", "r");

    printf("   -----------------------------  Visualizar Cliente  ------------------------------\n\n");
    while(fread(&input, sizeof(struct cliente), 1, infile)){
            printf ("\n                              Nome....: %s", input.nome);
            printf ("\n                              Endereço: %s", input.endereco);
            printf ("\n                              Telefone: %s \n", input.telefone);
           
            //printf ("\n Nome = %s \n Endereço = %s\n Telefone= %s\n", input.nome, input.endereco, input.telefone);

    };

    fclose (infile);
}

void LerClientes(){

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
    cab();
    LerClientes();

    voltarMenu();

    return 0;
}
