#include "structs.h"

void LerProd( char titulo[10], int category ){

    FILE *infile;
    struct produtos input;
    infile = fopen("./data/produtos.dat", "r");

    printf("   --------------------------  %s  ------------------------\n", titulo);
    while(fread(&input, sizeof(struct produtos), 1, infile)){
        if(input.category == category){
            printf ("\n                  id...: %s\n\n", prod.id);
            printf ("\n                  preco: %s\n\n", prod.name);
            printf ("\n                  preco: %s\n\n", prod.price);
        }
    };

    fclose (infile);
}