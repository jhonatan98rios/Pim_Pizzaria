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

    FILE *ProdFile;
    struct produtos prod; /* Cria uma instância para vizualização */
    ProdFile = fopen("../../data/produtos.dat", "r"); /* Salva os produtos armazenados em memória */

    printf("\n =================== %s =================== \n", titulo);
    while(fread(&prod, sizeof(struct produtos), 1, ProdFile)){ /* Isso deve virar uma funcao de cabeçalho */
        if(prod.category == category){
            printf ("\n nome = %s \n preco = %.2f\n", prod.name, prod.price); /* Percorre o array printando */
        }
    };

    fclose (ProdFile);
}

void LerCarrinho(){

    FILE *carrinho;
    struct produtos car; /* Cria uma instância para vizualização */
    carrinho = fopen("../../data/carrinho_de_compras.dat", "r"); /* Salva os produtos armazenados em memória */

    printf("\n\n === Carrinho de Compras === \n\n");
    while(fread(&car, sizeof(struct produtos), 1, carrinho)){
        printf ("\n nome = %s \n preco = %.2f\n", car.name, car.price); /* Printa a lista */
    };
    fclose(carrinho);
}

void ApagarCarrinho(){
    FILE *carrinho;
    struct produtos car; /* Cria uma instância para vizualização */
    carrinho = fopen("../../data/carrinho_de_compras.dat", "w"); /* Salva os produtos armazenados em memória */

    fclose(carrinho);
}

void CadastrarPedido(){

    char produto[10];
    int confirm = 0;

    FILE *ProdFile;
    ProdFile = fopen("../../data/produtos.dat", "r"); /* Abre o arquivo para leitura */
    struct produtos prod; /* prod é o objeto vindo da memoria */

    FILE *InputFile; /* Cria um arquivo para armazenar a compra */
    InputFile = fopen("../../data/carrinho_de_compras.dat", "a"); /* Abre o arquivo para adição */
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

/* ========== Isso verifica se o nome digitado é igual ao nome do produto salvo */

    printf(" \n Informe o nome do produto: \n");
    scanf("%s", input.name);
    
    int produtoValido = 0;
    int compare;

    while(fread(&prod, sizeof(struct produtos), 1, ProdFile)){

        if(prod.category == input.category){

            compare =  strcmp(prod.name, input.name); /* Verifica se produto é igual à a prod.name */

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

    if(produtoValido != 1){
        printf("Produto Inválido \n");
        CadastrarPedido();
    };

    printf("Confirmar pedido? [1] Sim - [0] Não \n");
    scanf("%d", &confirm);

    if(confirm != 1){
        printf("Compra cancelada!");
        CadastrarPedido();
        exit(0);

    }else{
        confirm = 0;
        
        fwrite(&input, sizeof(struct produtos), 1, InputFile); /* Grava o produto no carrinho */

        if(&fwrite != 0){ 
            printf("\e[1;1H\e[2J");
            printf("Cadastrado com sucesso !\n\n"); 
        }else{
            printf("\e[1;1H\e[2J"); 
            printf("Erro ao gravar !\n");
        }

        /* Mostra o carrinho */
        LerCarrinho();
        /* ======================= */
        
        printf("Deseja adicionar produtos? \n [1] Sim - [0] Não \n");
        scanf("%d", &confirm);

        if(confirm == 1){
            CadastrarPedido();
            confirm = 0;
            exit(0);
        }else{

            /* Mostra o carrinho */
            LerCarrinho();
            /* ======================= */
            
            printf("Confirmar pagamento? [1] Sim - [0] Não \n");
            scanf("%d", &confirm);

            if(confirm == 1){
                printf("Compra Finalizada com sucesso \n");

            }else{
                ApagarCarrinho();
                exit(0);
            }
        }
    }

    fclose(ProdFile);
    fclose(InputFile);

}

int main(){
    setlocale(LC_ALL, "Portuguese_Brasil");

    printf("\e[1;1H\e[2J");
    CadastrarPedido();
}