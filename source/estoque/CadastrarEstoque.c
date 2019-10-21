#include<stdio.h>
#include<stdlib.h>
/* #include <windows.h> */
#include <locale.h>
 
    struct estoque{
        int id;
        char nome[20];
        int quantidade;
    };

    int GerarId(){
        FILE *StoreFile;
        StoreFile = fopen("./data/estoque.dat", "r"); /* Abre o arquivo somente para leitura */

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
        EstoqueFile = fopen("./data/estoque.dat", "a"); /* Abre o arquivo somente para adição */

        struct estoque est; /* Cria uma instancia, da estrutura (Como uma cópia) */

        printf("Informe o nome do produto a ser cadastrado\n");
        scanf("%s", est.nome);
        printf("Informe a quantidade a ser cadastrada:  \n");
        scanf("%d", &est.quantidade);

        est.id = GerarId();

        fwrite (&est, sizeof(struct estoque), 1, EstoqueFile); /* Grava a estrutura no arquivo */

        if(&fwrite != 0){ /* Se conseguir gravar */
            printf("\e[1;1H\e[2J");
            printf("Salvo com sucesso !\n\n"); 
        }else{
            printf("\e[1;1H\e[2J"); 
            printf("Erro ao gravar !\n");
        }

        fclose(EstoqueFile);
    }

    int main(){

        //Define o padrão UTF-8
        setlocale(LC_ALL, "Portuguese_Brasil");
        //Define a cor azul do terminal
        //system("color 1F");
        //define o titulo da janela do prompt
        //system("title Menu");

        printf("\e[1;1H\e[2J");
        CadastrarEstoque();
        
    }