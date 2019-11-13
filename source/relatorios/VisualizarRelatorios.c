#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <string.h>

#include "../../libs/structs.h" 
#include "../../libs/voltar.h" 
#include "../../libs/cabSys.h" 

struct registro{
    int id;
    int category;
    char name[20];
    float price;
    int quant;
};

void LerRelatorios(){

    FILE *infile;
    struct registro prod;
    infile = fopen("./data/relatorio/data.dat", "r");

printf("   ----------------------------- Visualizar produtos -----------------------------\n\n");
    
    while(fread(&prod, sizeof(struct registro), 1, infile)){

        printf ("\n      Nome.......: %s", prod.name);
        printf ("\n      Preço......: %.2f", prod.price);
        printf ("\n      Quantidade.: %d\n\n" prod.quant);
	}

    fclose (infile);
};



int main()
{
    //Define o padrão UTF-8
    setlocale(LC_ALL, "Portuguese_Brasil");
    cab();
    LerRelatorios();

    voltarMenu();

    return 0;
}