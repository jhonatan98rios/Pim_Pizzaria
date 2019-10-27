#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include <conio.h>
#include "../../libs/structs.h" /* Essa é a classe de produto */



void editarProd(){


    FILE *infile;
    FILE *tempFile;
    struct produtos input;
    int codigoProd;

    infile = fopen("./data/produtos.dat", "r");
    tempFile = fopen("./data/produtosTemp.dat", "w");



    printf("\n =====================================================");
    printf("\n ================= Editar Produtos ===================");
    printf("\n =====================================================\n");

    printf(" Informe o código do produto:");
    scanf("%d",&codigoProd);
    printf(" =====================================================\n");

    while(fread(&input, sizeof(struct produtos), 1, infile)){


        if(input.id != codigoProd){
           fwrite(&input, sizeof(struct produtos),1,tempFile);
        }else{
            printf("\n Produto encontrado:\n");
            printf(" =====================================================\n");
            printf (" id = %d \n nome = %s \n preco = %.2f\n",input.id, input.name, input.price);
            fflush(stdin);
            printf(" =====================================================\n");
            printf("\n Digite o novo preço:");
            scanf("%f",&input.price);
            fwrite(&input, sizeof(struct produtos),1,tempFile);
            printf(" =====================================================\n");
            printf("\n Cadastro Atualizado!!!\n\n");
            printf(" =====================================================\n");
        }
    };
    fclose(infile);
    fclose(tempFile);
}

int main(){
    system("color 1F");
    setlocale(LC_ALL,"Portuguese_Brazil");
    editarProd();

    
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
