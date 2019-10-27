#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <string.h>

#include "../../libs/structs.h" /* Essa é a classe de produto */
#include "../../libs/lerProd.h" /* Essa é a classe de produto */
#include "../../libs/voltar.h" /* Essa é a classe de produto */
#include "../../libs/StructClie.h"

void LerCarrinho(){

    FILE *carrinho;
    struct produtos car; /* Cria uma instância para vizualização */
    carrinho = fopen("./data/carrinho_de_compras.dat", "r"); /* Salva os produtos armazenados em memória */

    printf("\n\n === Carrinho de Compras === \n\n");
    while(fread(&car, sizeof(struct produtos), 1, carrinho)){
        printf ("\n nome = %s \n preco = %.2f\n", car.name, car.price); /* Printa a lista */
    };
    fclose(carrinho);
}

void ApagarCarrinho(){
    FILE *carrinho;
    struct produtos car; /* Cria uma instância para vizualização */
    carrinho = fopen("./data/carrinho_de_compras.dat", "w"); /* Salva os produtos armazenados em memória */

    fclose(carrinho);
}

void CadastrarPedido(char tel[20]){

    char produto[10];
    int confirm = 0;

    FILE *ProdFile;
    ProdFile = fopen("./data/produtos.dat", "r"); /* Abre o arquivo para leitura */
    struct produtos prod; /* prod é o objeto vindo da memoria */

    FILE *InputFile; /* Cria um arquivo para armazenar a compra */
    InputFile = fopen("./data/carrinho_de_compras.dat", "a"); /* Abre o arquivo para adição */
    struct produtos input; /* input é o objeto informado */

    printf("O que deseja comprar? \n\n [1] Pizzas \n [2] Bebidas \n [3] Doces \n [4] Pizzas Grandes \n [5] Pizzas 1/2 \n");
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
    case 4:
        LerProd( "Pizzas Grandes" , 4);
        break;
    case 5:
        LerProd( "Pizzas 1/2" , 5);
        break;
    default:
        printf("Informe um valor válido");
        CadastrarPedido(tel);
        break;
    }

    printf(" \n Informe o id do produto: \n");
    scanf("%d", &input.id);
    
    int produtoValido = 0;

    while(fread(&prod, sizeof(struct produtos), 1, ProdFile)){

        if(prod.category == input.category){

/* ======================================================   */
            if( prod.id == input.id ){
                printf ("\nid = %d \n nome = %s \n preco = %.2f\n",prod.id,  prod.name, prod.price);
                produtoValido = 1;
                input.price = prod.price; /* Salva o valor do produto na struct input */
                break;
            }
/* ======================================================   */
        }
    };

    if(produtoValido != 1){
        printf("Produto Inválido \n");
        CadastrarPedido(tel);
    };

    printf("Confirmar pedido? [1] Sim - [0] Não \n");
    scanf("%d", &confirm);

    if(confirm != 1){
        printf("Compra cancelada!");
        CadastrarPedido(tel);
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
            CadastrarPedido(tel);
            confirm = 0;
            exit(0);
        }else{

            /* Mostra o carrinho */
            LerCarrinho();
            /* ======================= */
            
            printf("Confirmar pagamento? [1] Sim - [0] Não \n");
            scanf("%d", &confirm);

            if(confirm == 1){
                printf("%s \n\n", tel);
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

void IniciarVenda(){

    FILE *infile;
    struct cliente input;
    infile = fopen("./data/clientes.dat", "r");

    char tel[20];
    int isUser = 0;

    printf("Informe o telefone do Cliente: ");
    gets(tel);
    fflush(stdin);

    while(fread(&input, sizeof(struct cliente), 1, infile)){

        int compare = strcmp(tel, input.telefone);

        if(compare == 0){
            printf ("\n Nome = %s \n Endereço = %s\n Telefone= %s\n", input.nome, input.endereco, input.telefone);
            isUser = 1;
        }

        if(isUser == 1){
            CadastrarPedido(input.telefone);
        }else{
            system("./source/clientes/CadastrarClientes");
            CadastrarPedido(tel);
        }
        
    };



    fclose (infile);
}

int main(){
    setlocale(LC_ALL, "Portuguese_Brasil");

    printf("\e[1;1H\e[2J");
    IniciarVenda();

    voltarMenu();
}