#include "structs.h"
#include <time.h>

void editar(struct produtos item){

    /*  */

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
    strcpy(relatorioName, "./data/relatorio/");
    strcat(relatorioName, data);
    strcat(relatorioName, ".dat");

    /* ==================== */

    FILE *relatorioFile;
    struct produtos rel;
    relatorioFile = fopen(relatorioName, "r");

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
    remove(relatorioName);
    rename("./data/relatorio/temp.dat", relatorioName);
}

void gravar(struct produtos item){

    /*  */

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
    strcpy(relatorioName, "./data/relatorio/");
    strcat(relatorioName, data);
    strcat(relatorioName, ".dat");

    /* ==================== */

    FILE *Relatorio; 
    Relatorio = fopen(relatorioName, "a"); 
        fwrite (&item, sizeof(struct produtos), 1, Relatorio); /* Grava a estrutura no arquivo */
    fclose(Relatorio);
}

void SalvarRelatorio(){

    /*  */

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
    strcpy(relatorioName, "./data/relatorio/");
    strcat(relatorioName, data);
    strcat(relatorioName, ".dat");

    /* ==================== */

    FILE *Relatorio; 
    Relatorio = fopen(relatorioName, "a"); 
    fclose(Relatorio);

    /* ==================== */
    
    FILE *Carrinho; 
    Carrinho = fopen("./data/vendas/carrinho_de_compras.dat", "r"); 
    struct produtos item;

    int exist = 0;

    while(fread(&item, sizeof(struct produtos), 1, Carrinho)){

        FILE *Relatorio; 
        Relatorio = fopen(relatorioName, "r"); 
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

