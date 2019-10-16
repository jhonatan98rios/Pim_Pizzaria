#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <string.h>

struct produtos{
    int category;
    char name[10];
    float price;
};

void LerProd( char titulo[10], int category ){ /* Isso deve virar uma funcao de cabeçalho */

    FILE *infile;
    struct produtos prod; /* Cria uma instância para vizualização */
    infile = fopen ("../../data/produtos.dat", "r"); /* Salva os produtos armazenados em memória */

    printf("\n =================== %s =================== \n", titulo);
    while(fread(&prod, sizeof(struct produtos), 1, infile)){ /* Isso deve virar uma funcao de cabeçalho */
        if(prod.category == category){
            printf ("\n nome = %s \n preco = %.2f\n", prod.name, prod.price); /* Percorre o array printando */
        }
    };

    fclose (infile);
}

void CadastrarPedido(){

    char produto[10];
    int confirm = 0;

    FILE *infile;
    infile = fopen("../../data/produtos.dat", "r"); /* Abre o arquivo para leitura */
    struct produtos prod; /* prod é o objeto vindo da memoria */

    FILE *InputFile; /* Cria um arquivo para armazenar a compra */
    InputFile = fopen("./data/carrinho_de_compra.dat", "a"); /* Abre o arquivo para adição */
    struct produtos input; /* input é o objeto informado */

    printf("O que deseja comprar? \n\n [1] Pizzas \n [2] Bebidas \n [3] Doces \n");
    scanf("%d", &input.category );

    switch(input.category)
    {
    case 1:
        LerProd( "Pizzas" , 1);
        break;
    case 2:
        LerProd( "Bebidas" , 2);
        break;
    case 3:
        LerProd( "Doces" , 3);
        break;
    default:
        printf("Informe um valor válido");
        CadastrarPedido();
        break;
    }

    printf(" \n Informe o nome do produto: \n");
    scanf("%s", input.name);
    
    int compare =  strcmp(prod.name, input.name); /* Verifica se produto é igual à a prod.name */
    int produtoValido = 0;

    while(fread(&prod, sizeof(struct produtos), 1, infile)){

        if(prod.category == input.category){

            printf("%s \n", input.name);
            printf("%s \n", prod.name);
            printf("%d \n", compare);

/* ======================================================   */
            if( compare == 0 ){
                printf ("\n nome = %s \n preco = %.2f\n", prod.name, prod.price);
                produtoValido = 1;
                input.price = prod.price; /* Salva o valor do produto na struct input */
                break;
            }
/* ======================================================   */
        }
    };

    if(produtoValido != 0){
        printf("Produto Inválido \n");
        CadastrarPedido();
    };

    printf("Confirmar pedido?");
    scanf("%d", &confirm);

    if(confirm == 0){
        printf("Compra cancelada!");
        CadastrarPedido();
        exit(0);

    }else{
        confirm = 0;
        fwrite (&input, sizeof(struct produtos), 1, ProdFile); /* Grava o produto no carrinho */

        if(&fwrite != 0){ /* Se conseguir gravar */
            printf("\e[1;1H\e[2J");
            printf("Cadastrado com sucesso !\n\n"); 
        }else{
            printf("\e[1;1H\e[2J"); 
            printf("Erro ao gravar !\n");
            system( "read -n 1 -s -p \"Press any key to continue...\"" ); /* Pause */
        }

        printf("Deseja adicionar produtos? \n [1] Sim - [0] Não");
        scanf("%d", &confirm);

        if(confirm == 1){
            CadastrarPedido();
            exit(0);
        }else{



        }
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese_Brasil");

    printf("\e[1;1H\e[2J");
    CadastrarPedido();
}