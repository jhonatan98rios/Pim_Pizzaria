#include "structs.h"

void editar(){
    printf("Editar!!");
}

void gravar(){
    printf("Gravar!!");
    FILE *RelatorioA; 
    RelatorioA = fopen("./data/relatorio/relatorio.dat", "a"); 
        fwrite (&item, sizeof(struct produtos), 1, RelatorioA); /* Grava a estrutura no arquivo */
    fclose(RelatorioA);
}

void SalvarRelatorio(){
    
    FILE *Carrinho; 
    Carrinho = fopen("./data/vendas/carrinho_de_compras.dat", "r"); 
    struct produtos item;

    int exist = 0;

    while(fread(&item, sizeof(struct produtos), 1, Carrinho)){

        FILE *Relatorio; 
        Relatorio = fopen("./data/relatorio/relatorio.dat", "r"); 
        struct produtos index;
        exist = 0;

        while(fread(&index, sizeof(struct produtos), 1, Relatorio)){

            if(index.id == item.id){
                exist = 1;
                break;
            }
        }

        fclose (Relatorio);

        if(exist == 1){
            editar();
        }else{
        gravar();
        }
    };

    fclose (Carrinho);
    

}