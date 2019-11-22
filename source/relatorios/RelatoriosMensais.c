#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <string.h>

#include "../../libs/structs.h" 
#include "../../libs/voltar.h" 
#include "../../libs/cabSys.h"
#include "../../libs/Mensagem.h"

void LerRelatorios(){

    char ano[8] = "";
    char mes[4] = "";
    char dia[4] = "";

    char data[20] = "";
    char path[60] = ".\\data\\relatorio\\";

    float total = 0.0;

    int index = 1;

    printf("   ----------------------------- Relatorios Mensais -----------------------------\n\n");
    printf("\nInforme o ano (ex: 2019): ");
    scanf("%s", ano);
    fflush(stdin);

    printf("Informe o mes (ex: 01): ");
    scanf("%s", mes);
    strcat(mes, "-");
    fflush(stdin);

// ============== Percorre todos os arquivos de relatorios ==========================

    for(index=1; index <= 31; index++){

        strcpy(data, "");
        strcpy(path, ".\\data\\relatorio\\");

        if(index<10){
            sprintf(dia, "0%d", index);
        }else{
            sprintf(dia, "%d", index);
        }
        
        strcat(dia, "-");
        strcat(data, dia);
        strcat(data, mes);
        strcat(data, ano);

        strcat(path, data);
        strcat(path, ".dat");

/* ================ Lê todos os arquivos ================ */

        FILE *infile;
        struct produtos prodt;
        infile = fopen(path, "r");
        if(infile != NULL){ /* Se o arquivo existir */
            printf("----------------------------- Dia %s -----------------------------\n\n", data);
            while(fread(&prodt, sizeof(struct produtos), 1, infile)){
                printf("\n\n      Nome.......: %s", prodt.name);
                printf("\n      Preço......: %.2f", prodt.price);
                printf("\n      Quantidade.: %d\n\n", prodt.quant);
                total += prodt.price;
            }
            fclose (infile);
        }
        
    /* for end */
    }

    printf("\nO lucro total nesse mes, foi de: R$ %.2f \n", total);
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
