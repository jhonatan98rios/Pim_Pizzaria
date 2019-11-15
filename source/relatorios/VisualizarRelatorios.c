#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

#include "../../libs/structs.h" 
#include "../../libs/voltar.h" 
#include "../../libs/cabSys.h" 

void LerRelatorios(){

    /* Pega a data do sistema */
    struct tm *data_hora_atual;     
    time_t segundos; 
    time(&segundos);   
    data_hora_atual = localtime(&segundos);
    /* Converte em string "dd-mm-aaaa" */
    char data[20];
    sprintf(data, "%d-%d-%d", data_hora_atual->tm_mday, data_hora_atual->tm_mon+1, data_hora_atual->tm_year+1900);
    /* Cria o nome do arquivo de relatorios baseado na data */
    char relatorioName[40];
    strcpy(relatorioName, ".\\data\\relatorio\\");
    strcat(relatorioName, data);
    strcat(relatorioName, ".dat");

    /* ==================== */

    FILE *infile;
    struct produtos prod;
    infile = fopen(relatorioName, "r");

    printf("   ----------------------------- Visualizar Relatorios -----------------------------\n\n");
    
    while(fread(&prod, sizeof(struct produtos), 1, infile)){

        printf("\n      Nome.......: %s", prod.name);
        printf("\n      Preço......: %.2f", prod.price);
        printf("\n      Quantidade.: %d\n\n", prod.quant);
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