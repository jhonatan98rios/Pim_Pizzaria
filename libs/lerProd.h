#include "structs.h"

void LerProd( char titulo[10], int category ){

    FILE *infile;
    struct produtos prod;
    infile = fopen(".\\data\\produtos.dat", "r");

    printf("   --------------------------  %s  ------------------------\n", titulo);
    while(fread(&prod, sizeof(struct produtos), 1, infile)){
        if(prod.category == category){
            printf ("\n                  id...: %d", prod.id);
            printf ("\n                  preco: %s", prod.name);
            printf ("\n                  preco: %.2f\n\n", prod.price);
        }
    };

    fclose (infile);
}