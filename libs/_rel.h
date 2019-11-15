/* #include <time.h> */
#include "structs.h"

struct registro{
    int id;
    int category;
    char name[20];
    float price;
    int quant;
};

gravarRelatorio(){

    /* Preciso passar os valores de produtos para registros para poder gravar */

    FILE *relatorio;
    relatorio = fopen(".\\data\\relatorio\\data.dat", "a");
    
    fwrite(&prod, sizeof(struct registro), 1, relatorio);
    fclose (relatorio); 
}

editarRelatorio(){
    /* Adiciona à quantidade do item mais 1 */
}

void SalvarRelatorio(){
    
    /* time_t current_time;
    current_time = time(NULL);
    char* c_time_string;

    c_time_string = ctime(&current_time);

    printf("Current time is %s", c_time_string); */


    FILE *Carrinho; 
    Carrinho = fopen(".\\data\\vendas\\carrinho_de_compras.dat", "r"); 
    struct produtos prod;

    int exist = 0;

    while(fread(&prod, sizeof(struct produtos), 1, Carrinho)){

        FILE *read;
        read = fopen(".\\data\\relatorio\\data.dat", "r");
        struct registro test;

        exist = 0;

        /* Percorre a lista de registros atras de um ID igual. Caso haja, exit = 1 */
        while(fread(&test, sizeof(struct registro), 1, read)){
            if(test.id == prod.id){
                exist = 1;
            }
        }

        if(exist == 0){
            gravarRelatorio();
        }else{
            editarRelatorio();
        }


    };

    fclose (Carrinho); 
    

}