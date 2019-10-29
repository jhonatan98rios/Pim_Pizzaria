#include "structs.h"

void LerProd( char titulo[10], int category ){

    FILE *infile;
    struct produtos input;
    infile = fopen("../../data/produtos.dat", "r");

    printf("\n =================== %s =================== \n", titulo);
    while(fread(&input, sizeof(struct produtos), 1, infile)){
        if(input.category == category){
            printf("\n id = %d \n nome = %s \n preco = %.2f\n",input.id, input.name, input.price);
        }
    };

    fclose (infile);
}

void LerProm(){

    FILE *infile;
    struct produtos input;
    infile = fopen("../../data/promocoes.dat", "r");

    printf("\n =================== Promocoes =================== \n");
    while(fread(&input, sizeof(struct produtos), 1, infile)){
        printf("\n id = %d \n nome = %s \n preco = %.2f\n",input.id, input.name, input.price);
    };

    fclose (infile);
}