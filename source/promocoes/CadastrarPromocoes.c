#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
/* #include <conio.h> */

/* Sctruct é uma variavel com varias propriedades */
struct promocoes{
    int category; /* Define se é pizza, bebida ou doce */
    char name[10];
    float price;
};

void CadastrarPromocao(){

    FILE *PromFile;
    PromFile = fopen("prod.dat", "a"); /* Abre o arquivo somente para adição */

    struct promocoes prod; /* Cria uma instancia, da estrutura (Como uma cópia) */

    printf("Informe qual promocao deseja cadastrar: \n \n [1] Pizzas \n [2] Bebidas \n [3] Doces\n\n");
    scanf("%d", &prod.category ); /* Isso vai definir como vai ser exibido em "Vizualizar Produto" */

    printf("\e[1;1H\e[2J"); /* Limpa a Tela */
    printf("Informe o nome do promocao: \n");
    scanf("%s", prod.name);
    printf("Informe o preco da produto: \n");
    scanf("%f", &prod.price);

    fwrite (&prod, sizeof(struct promocoes), 1, PromFile); /* Grava a estrutura no arquivo */

    if(&fwrite != 0){ /* Se conseguir gravar */
        printf("\e[1;1H\e[2J");
        printf("Salvo com sucesso !\n\n"); 
    }else{
        printf("\e[1;1H\e[2J"); 
        printf("Erro ao gravar !\n");
    }
    
    fclose(PromFile);
}

int main()
{
    //Define o padrão UTF-8
    setlocale(LC_ALL, "Portuguese_Brasil");
    //Define a cor azul do terminal
    //system("color 1F");
    //define o titulo da janela do prompt
    //system("title Menu");

    printf("\e[1;1H\e[2J");
    CadastrarPromocao();

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
