#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
/* #include <conio.h> */
#include "../../libs/structs.h"
#include "../../libs/voltar.h"
#include "../../libs/cabSys.h"
#include "../../libs/Mensagem.h"
#include "../../libs/lerProd.h"


void editar(){

    FILE *infile;
    FILE *tempFile;
    struct produtos input;
    int idProd;

    infile = fopen(".\\data\\produtos.dat", "r");
    tempFile = fopen(".\\data\\prodTemp.dat", "w");

    printf("   -------------------------------  Editar Produto  --------------------------------\n\n");

    LerProd( "Pizzas" , 1);
    LerProd( "Bebidas" , 2);
    LerProd( "Doces" , 3);
    LerProd( "Pizzas Grandes", 4);
    LerProd( "Meias Pizzas", 5);
    LerProd( "Promocoes", 6);

    printf("                            Informe o ID do produto a ser editado: ");
    scanf("%d", &idProd);
    fflush(stdin);

    while(fread(&input, sizeof(struct produtos), 1, infile)){

        if(idProd != input.id){
           fwrite(&input, sizeof(struct produtos),1,tempFile);
        }else{
            printf("\n                             Produto Encontrado");
            printf ("\n                            Id.......: %d", input.id);
            printf ("\n                            Nome.....: %s", input.name);
            printf ("\n                            Categoria: %d", input.category);
            printf ("\n                            Preco....: %.2f", input.price);
            fflush(stdin);
            printf("\n   ---------------------------------------------------------------------------------\n");
            printf("                               Digite o novo nome: ");
            gets(input.name);
            fflush(stdin);
            printf("                               [1] Pizza - [2] Bebidas - [3] Sobremesas \n");
            printf("                               [4] Pizzas Grandes - [5] 1/2 Pizzas - [6] Promocoes \n");
            printf("                               Digite a nova categoria: ");
            scanf("%d", &input.category);
            fflush(stdin);
            printf("                               Digite o novo preco: ");
            scanf("%f", &input.price);
            fflush(stdin);
            fwrite(&input, sizeof(struct produtos),1,tempFile);

            sucess();
        }
    };

    fclose(infile);
    fclose(tempFile);
    remove(".\\data\\produtos.dat");
    rename(".\\data\\prodTemp.dat",".\\data\\produtos.dat");
}

int main(){
    system("color 1F");
    setlocale(LC_ALL,"Portuguese_Brazil");
    cab();
    editar();
    voltarMenu();

    return 0;
}
