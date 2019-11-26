#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
/* #include <conio.h> */
#include "../../libs/LerEst.h"
#include "../../libs/voltar.h"
#include "../../libs/structs.h" 
#include "../../libs/Mensagem.h"
#include "../../libs/cabSys.h"

void Adicionar(id){

    FILE *EstoqueFile;
    struct estoque est;
    EstoqueFile = fopen(".\\data\\estoque.dat", "r");

    FILE *TempFile;
    TempFile = fopen(".\\data\\estoqueTemp.dat", "w");

    int quant;

    printf("                               Quantas unidades deseja adicionar? \n");
    scanf("%d", &quant);

    while(fread(&est, sizeof(struct estoque), 1, EstoqueFile)){
        if(id == est.id){
            est.quantidade += quant;
            printf("                               %s agora tem %d unidades em estoque \n", est.nome, est.quantidade);
            Editar();
        }
        fwrite(&est, sizeof(struct estoque), 1, TempFile); /* Grava a estrutura no arquivo */
        if(&fwrite == 0){
            error();
        }
    };

    fclose(EstoqueFile);  
    fclose(TempFile);  
    remove(".\\data\\estoque.dat");
    rename(".\\data\\estoqueTemp.dat", ".\\data\\estoque.dat");
}

void Remover(id){

    FILE *EstoqueFile;
    struct estoque est;
    EstoqueFile = fopen(".\\data\\estoque.dat", "r");

    FILE *TempFile;
    TempFile = fopen(".\\data\\estoqueTemp.dat", "w");

    int quant;

    printf("                               Quantas unidades deseja remover? \n");
    scanf("%d", &quant);

    while(fread(&est, sizeof(struct estoque), 1, EstoqueFile)){
        if(id == est.id){
            est.quantidade -= quant;

            printf("                               %s agora tem %d unidades em estoque \n", est.nome, est.quantidade);
        }
        fwrite(&est, sizeof(struct estoque), 1, TempFile); /* Grava a estrutura no arquivo */
        if(&fwrite == 0){
            printf("                               Erro ao gravar: %d!\n", est.id);
        }
    };

    fclose(EstoqueFile);
    fclose(TempFile);
    remove(".\\data\\estoque.dat");
    rename(".\\data\\estoqueTemp.dat", ".\\data\\estoque.dat");
}

void EditarEstoque(){

   printf("   -------------------------------  Editar estoque  -------------------------------\n\n");
    int id;
    int resp;

    LerEst();

    printf("                               Qual ID deseja alterar:");
    scanf("%d", &id);

    FILE *EstoqueFile;
    struct estoque est;
    EstoqueFile = fopen(".\\data\\estoque.dat", "r");

    while(fread(&est, sizeof(struct estoque), 1, EstoqueFile)){
        if(id == est.id){
            printf ("\n                               Id........: %d ", est.id);
            printf ("\n                               Nome......: %s ", est.nome);
            printf ("\n                               Quantidade: %d ", est.quantidade);
            printf("\n   --------------------------------------------------------------------------------\n\n");
        }
    };

    fclose (EstoqueFile);

    printf("\n                               Opcoes disponiveis");
    printf("\n                               [1] Adicionar");
    printf("\n                               [2] Remover ");
    printf("\n                               O que deseja fazer:");
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
    //Define o padrao UTF-8
    setlocale(LC_ALL, "Portuguese_Brasil");
    //Define a cor azul do terminal
    //system("color 1F");
    //define o titulo da janela do prompt
    //system("title Menu");

    cab();
    EditarEstoque();
    voltarMenu();

    return 0;
}
