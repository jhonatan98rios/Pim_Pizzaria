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
    carrinho = fopen("../../data/vendas/carrinho_de_compras.dat", "r"); /* Salva os produtos armazenados em memória */

    printf("\n\n === Carrinho de Compras === \n\n");
    while(fread(&car, sizeof(struct produtos), 1, carrinho)){
        printf ("\n nome = %s \n preco = %.2f\n", car.name, car.price); /* Printa a lista */
    };
    fclose(carrinho);
}

void ApagarCarrinho(){
    FILE *carrinho;
    struct produtos car; /* Cria uma instância para vizualização */
    carrinho = fopen("./data/vendas/carrinho_de_compras.dat", "w"); /* Salva os produtos armazenados em memória */
    fclose(carrinho);
}


void isUser(char tel[20]){

    FILE *ClieFile;
    struct cliente clie;
    ClieFile = fopen("../../data/clientes.dat", "r");

    int hasUser = 0;

    while(fread(&clie, sizeof(struct cliente), 1, ClieFile)){
        int compare = strcmp(tel, clie.telefone);
        if(compare == 0){
            printf ("\n Nome = %s \n Endereço = %s\n Telefone= %s\n", clie.nome, clie.endereco, clie.telefone);
            hasUser = 1;
            break;
        }
    };

    if(hasUser == 0){
        system("../clientes/CadastrarClientes");
        fclose (ClieFile); 
        isUser(tel);
    }else{
        printf("Usuario valido \n\n");
    }

    fclose (ClieFile); 

}

void CadastrarPedido(){

    /* Lê a lista de clientes */

    FILE *ProdFile;
    ProdFile = fopen("../../data/produtos.dat", "r"); /* Abre o arquivo para leitura */
    struct produtos prod; /* prod é o objeto vindo da memoria */

    FILE *Carrinho; /* Cria um arquivo para armazenar a compra */
    Carrinho = fopen("../../data/vendas/carrinho_de_compras.dat", "a"); /* Abre o arquivo para adição */
    struct produtos input; /* clie é o objeto informado */

    char tel[20]; /* Telefone do clientes */
    int confirm = 0;

    printf("Informe o telefone do Cliente: ");
    gets(tel);
    fflush(stdin);

    /* Verifica se o numero de telefone existe na lista */

    isUser(tel);

    ESCOLHA:

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
        goto ESCOLHA;
        break;
    }

    printf(" \n Informe o id do produto: \n");
    scanf("%d", &input.id);
    
    int produtoValido = 0;

    while(fread(&prod, sizeof(struct produtos), 1, ProdFile)){

        if( input.id == prod.id ){
            printf ("\nid = %d \n nome = %s \n preco = %.2f\n",prod.id,  prod.name, prod.price);
            produtoValido = 1;
            input.price = prod.price; /* Salva o valor do produto na struct input */
            break;
        }

    };

    if(produtoValido != 1){
        printf("Produto Inválido \n");
        goto ESCOLHA;
    }else{

        printf("Confirmar pedido? [1] Sim - [0] Não \n");
        scanf("%d", &confirm);

        if(confirm != 1){
            printf("Compra cancelada!");
            goto ESCOLHA;
        }else{

            confirm = 0;        
            fwrite(&input, sizeof(struct produtos), 1, Carrinho); /* Grava o produto no carrinho */

            if(&fwrite != 0){ 
                printf("\e[1;1H\e[2J");
                printf("Cadastrado com sucesso !\n\n"); 
            }else{
                printf("\e[1;1H\e[2J"); 
                printf("Erro ao gravar !\n");
            }

        }

        printf("Deseja adicionar produtos? \n [1] Sim - [0] Não \n");
        scanf("%d", &confirm);

        if(confirm == 1){
            confirm = 0;
            goto ESCOLHA;
            
        }else{

            fclose(Carrinho);
            fclose(ProdFile);

            /* Mostra o carrinho */
            LerCarrinho();
            /* ======================= */

            PAGAMENTO:
            
            printf("Confirmar pagamento? [1] Sim - [0] Não \n");
            scanf("%d", &confirm);

            if(confirm == 1){
                printf("%s \n\n", tel);
                printf("Compra Finalizada com sucesso \n");

            }else if(confirm == 0){
                ApagarCarrinho();
                exit(0);
            }else{
                printf("Informe um valor válido: \n");
                goto PAGAMENTO;
            }
        }
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese_Brasil");

    printf("\e[1;1H\e[2J");
    CadastrarPedido();

    voltarMenu();
}