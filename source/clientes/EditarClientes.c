#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include <conio.h>
#include "StructClie.h"



void editar(){


    FILE *infile;
    FILE *tempFile;
    struct cliente input;
    char foneCliente [20];
    char novoEndereco[20];

    infile = fopen("clientes.dat", "r");
    tempFile = fopen("clientesTemp.dat", "w");
    setlocale(LC_ALL,"Portuguese_Brazil");



    printf("\n =====================================================");
    printf("\n ================= Editar Clientes ===================");
    printf("\n =====================================================\n");

    printf("Informe o Numero do cliente:");
    scanf("%s", foneCliente);

    while(fread(&input, sizeof(struct cliente), 1, infile)){

       int Compare = strcmp(foneCliente,input.telefone);


        if(Compare != 0){
           fwrite(&input, sizeof(struct cliente),1,tempFile);
        }else{
            printf("\nCliente encontrado com o telefone: %s \n", input.telefone);
            printf ("\n Nome: %s \n Endereço: %s\n Telefone: %s\n", input.nome, input.endereco, input.telefone);
            fflush(stdin);
            printf(" =====================================================\n");
            printf("\n Digite o novo endereço:");
            gets(input.endereco);
             fwrite(&input, sizeof(struct cliente),1,tempFile);

             printf("\n Cadastro Atualizado!!!\n\n");
        }
    };
    fclose(infile);
    fclose(tempFile);
}

int main(){
    system("color 1F");
    setlocale(LC_ALL,"Portuguese_Brazil");
    editar();

    
    int continuar;

    printf("Deseja voltar ao menu? \n [1] Sim \n [2] Nao\n");
    scanf("%d", &continuar);
    if(continuar == 1){
        system("./source/menu");
    }else{
        printf("Programa Encerrado");
    }

    return 0;
}
