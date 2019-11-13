#include "structs.h"


void editar(struct produtos item){
    FILE *relatorioFile;
    struct produtos rel;
    relatorioFile = fopen("./data/relatorio/relatorio.dat", "r");

    FILE *TempFile;
    TempFile = fopen("./data/relatorio/temp.dat", "w");

    while(fread(&rel, sizeof(struct produtos), 1, relatorioFile)){
        if(item.id == rel.id){
            rel.quant += 1;
        }
        fwrite(&rel, sizeof(struct produtos), 1, TempFile); /* Grava a estrutura no arquivo */
        if(&fwrite == 0){
            error();
        }
    };

    fclose(relatorioFile);  
    fclose(TempFile);  
    remove("./data/relatorio/relatorio.dat");
    rename("./data/relatorio/temp.dat", "./data/relatorio/relatorio.dat");
}

void gravar(struct produtos item){
    FILE *Relatorio; 
    Relatorio = fopen("./data/relatorio/relatorio.dat", "a"); 
        fwrite (&item, sizeof(struct produtos), 1, Relatorio); /* Grava a estrutura no arquivo */
    fclose(Relatorio);
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
            editar(item);
        }else{
        gravar(item);
        }
    };

    fclose (Carrinho);
    
}

