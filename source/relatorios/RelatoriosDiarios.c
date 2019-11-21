#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <string.h>

#include "../../libs/structs.h" 
#include "../../libs/voltar.h" 
#include "../../libs/cabSys.h" 

void LerRelatorios(){

    char ano[8];
    char mes[4];
    char dia[4];

    char data[20];
    char path[30] = ".\\data\\relatorio\\";

    float total = 0.0;

    printf("Informe a data para visualizar os relatorios: \n");
    
    printf("\nInforme o ano (ex: 2019): ");
    scanf("%s", ano);
    fflush(stdin);

    printf("Informe o mes (ex: 01): ");
    scanf("%s", mes);
    fflush(stdin);

    printf("Informe o dia (ex: 01): ");
    scanf("%s", dia);
    fflush(stdin);

    strcat(dia, "-");
    strcat(mes, "-");
    strcat(data, dia);
    strcat(data, mes);
    strcat(data, ano);

    strcat(path, data);
    strcat(path, ".dat");

    printf("\n Data: %s. \n\n", path);

// ===================================================

    FILE *infile;
    struct produtos prod;
    infile = fopen(path, "r");

    printf("   ----------------------------- Visualizar Relatorios -----------------------------\n\n");
    
    while(fread(&prod, sizeof(struct produtos), 1, infile)){

        printf("\n      Nome.......: %s", prod.name);
        printf("\n      Preço......: %.2f", prod.price);
        printf("\n      Quantidade.: %d\n\n", prod.quant);

        total += (prod.price * prod.quant);

	}

    printf("\nO Lucro total desse dia foi de: %.2f \n", total);

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