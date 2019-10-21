#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
/* #include <conio.h> */
#include "./LerEst.h"

void Adicionar(id){

    FILE *EstoqueFile;
    struct estoque est;
    EstoqueFile = fopen("estoque.dat", "r");

    FILE *TempFile;
    TempFile = fopen("temp.dat", "w");

    int quant;

    printf("Quantas unidades deseja adicionar? \n");
    scanf("%d", &quant);

    while(fread(&est, sizeof(struct estoque), 1, EstoqueFile)){
        if(id == est.id){
            est.quantidade += quant;
            printf("%s agora tem %d unidades em estoque \n", est.nome, est.quantidade);
        }
        fwrite(&est, sizeof(struct estoque), 1, TempFile); /* Grava a estrutura no arquivo */
        if(&fwrite == 0){
            printf("Erro ao gravar: %d!\n", est.id);
        }
    };

    fclose(EstoqueFile);  
    remove("estoque.dat");
    rename("temp.dat", "estoque.dat");
}

void Remover(id){

    FILE *EstoqueFile;
    struct estoque est;
    EstoqueFile = fopen("estoque.dat", "r");

    FILE *TempFile;
    TempFile = fopen("temp.dat", "w");

    int quant;

    printf("Quantas unidades deseja remover? \n");
    scanf("%d", &quant);

    while(fread(&est, sizeof(struct estoque), 1, EstoqueFile)){
        if(id == est.id){
            est.quantidade -= quant;
            printf("%s agora tem %d unidades em estoque \n", est.nome, est.quantidade);
        }
        fwrite(&est, sizeof(struct estoque), 1, TempFile); /* Grava a estrutura no arquivo */
        if(&fwrite == 0){
            printf("Erro ao gravar: %d!\n", est.id);
        }
    };

    fclose(EstoqueFile);  
    remove("estoque.dat");
    rename("temp.dat", "estoque.dat");
}

void EditarEstoque(){

    printf("\n =======================================================");
    printf("\n ================= Edição de Estoque ===================");
    printf("\n =======================================================\n");

    int id;
    int resp;

    LerEst();

    printf("\n\n Qual ID deseja alterar? \n");
    scanf("%d", &id);

    FILE *EstoqueFile;
    struct estoque est;
    EstoqueFile = fopen("estoque.dat", "r");

    while(fread(&est, sizeof(struct estoque), 1, EstoqueFile)){
        if(id == est.id){
            printf ("\n id = %d \n nome = %s \n quantidade = %d \n\n", est.id, est.nome, est.quantidade);
        }
    };

    fclose (EstoqueFile);

    printf("O que deseja fazer? \n [1] Adicionar \n [2] Remover \n");
    scanf("%d", &resp);

    if(resp == 1){
        Adicionar(id);
    }else{
        Remover(id);
    }  
    
    printf("\n\n");
};

int main()
{
    //Define o padrão UTF-8
    setlocale(LC_ALL, "Portuguese_Brasil");
    //Define a cor azul do terminal
    //system("color 1F");
    //define o titulo da janela do prompt
    //system("title Menu");

    printf("\e[1;1H\e[2J");
    EditarEstoque();

    return 0;
}