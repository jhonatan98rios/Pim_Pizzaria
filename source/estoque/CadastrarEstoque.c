#include<stdio.h>
#include<stdlib.h>
/* #include <windows.h> */
#include <locale.h>
#include "../../libs/voltar.h"
#include "../../libs/structs.h" 
#include "../../libs/Mensagem.h"
#include "../../libs/cabSys.h"

    int GerarId(){
        FILE *StoreFile;
        StoreFile = fopen(".\\data\\estoque.dat", "r"); /* Abre o arquivo somente para leitura */

        struct estoque store;

        int contador = 1001;

        while(fread(&store, sizeof(struct estoque), 1, StoreFile)){
            contador++;
        };

        fclose(StoreFile);

        return contador;
    }

    void CadastrarEstoque(){
        FILE *EstoqueFile;
        EstoqueFile = fopen(".\\data\\estoque.dat", "a"); /* Abre o arquivo somente para adicao */

        struct estoque est; /* Cria uma instancia, da estrutura (Como uma copia) */

        printf("   ------------------------------  Cadastrar estoque  ------------------------------\n\n");
        printf("                      Informe o nome do produto a ser cadastrado: ");
        scanf("%s", est.nome);
        printf("\n                      Informe a quantidade a ser cadastrada.....: ");
        scanf("%d", &est.quantidade);

        est.id = GerarId();

        fwrite (&est, sizeof(struct estoque), 1, EstoqueFile); /* Grava a estrutura no arquivo */

        if(&fwrite != 0){ /* Se conseguir gravar */
            sucess();
        }else{
            error();
        }

        fclose(EstoqueFile);
    }

    int main(){

        //Define o padrao UTF-8
        setlocale(LC_ALL, "Portuguese_Brasil");
        //Define a cor azul do terminal
        system("color 1F");
        //define o titulo da janela do prompt
        system("title Menu");

        cab();
        CadastrarEstoque();
        
        voltarMenu();

    }