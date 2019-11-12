#include "structs.h"

void LerEst(){
    FILE *EstoqueFile;
    struct estoque est;
    EstoqueFile = fopen("./data/estoque.dat", "r");

    while(fread(&est, sizeof(struct estoque), 1, EstoqueFile)){
        printf ("\n id = %d \n nome = %s \n quantidade = %d \n", est.id, est.nome, est.quantidade);
    };

    fclose (EstoqueFile);
}