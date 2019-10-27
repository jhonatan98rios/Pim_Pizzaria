#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
/* #include <conio.h> */

struct promocoes{
    int category;
    char name[10];
    float price;
};

void LerProm( char titulo[10], int category ){

    FILE *infile;
    struct promocoes input;
    infile = fopen ("./data/promocoes.dat", "r");

    printf("\n =================== %s =================== \n", titulo);
    while(fread(&input, sizeof(struct promocoes), 1, infile)){
        if(input.category == category){
            printf ("\n nome = %s \n preco = %.2f\n", input.name, input.price);
        }
    };

    fclose (infile);
}

void LerPromocoes(){

    printf("\n ==============================================");
    printf("\n ================= Promocoes ===================");
    printf("\n ==============================================\n");

    LerProm( "Pizzas" , 1);
    LerProm( "Bebidas" , 2);
    LerProm( "Doces" , 3);

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
    LerPromocoes();

    /* Isso se tornará uma biblioteca de cabeçalho */

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
