#include <time.h>
#include "structs.h"

struct registro{
    int id;
    int category;
    char name[20];
    float price;
    char date;
};

void SalvarRelatorio(){
    
    time_t current_time;
    current_time = time(NULL);
    char* c_time_string;

    c_time_string = ctime(&current_time);

    printf("Current time is %s", c_time_string);


    FILE *Carrinho; 
    Carrinho = fopen("./data/vendas/carrinho_de_compras.dat", "r"); 
    struct produtos prod;

    FILE *relatorio;
    relatorio = fopen("./data/relatorio/data.dat", "a");

    while(fread(&prod, sizeof(struct produtos), 1, Carrinho)){
        fwrite(&prod, sizeof(struct produtos), 1, relatorio);
    };

    fclose (Carrinho); 
    fclose (relatorio); 

}