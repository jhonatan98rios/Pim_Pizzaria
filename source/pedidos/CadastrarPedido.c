#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <string.h>

#include "../../libs/structs.h"
#include "../../libs/lerProd.h"
#include "../../libs/voltar.h"
#include "../../libs/cabSys.h"
#include "../../libs/Mensagem.h"
#include "../../libs/rel.h"

void LerCarrinho(){

    FILE *carrinho;
    struct produtos car; /* Cria uma instância para vizualização */
    carrinho = fopen("./data/vendas/carrinho_de_compras.dat", "r"); /* Salva os produtos armazenados em memória */

    float total;
    printf("\n\n   ----------------------------- Carrinho de Compras -------------------------------\n");
    
    while(fread(&car, sizeof(struct produtos), 1, carrinho)){
        printf ("\n                          Nome.: %s", car.name);
        printf ("\n                          Preco: %.2f \n", car.price);
        total += car.price;
    };

    printf("\n\n                         Total: %.2f \n\n", total);
    
    fclose(carrinho);
}

void ApagarCarrinho(){
    FILE *carrinho;
    struct produtos car; /* Cria uma instância para vizualização */
    carrinho = fopen("./data/vendas/carrinho_de_compras.dat", "w"); /* Salva os produtos armazenados em memória */
    remove("./data/vendas/carrinho_de_compras.dat");
}

void isUser(char tel[20]){

    /* 
        Essa função verifica se o telefone existe.
        Se ele existir, o programa segue em execução
        Se não, o modulo de cadastro de clientes e chamado
    */

    FILE *ClieFile;
    struct cliente clie;
    ClieFile = fopen("./data/clientes.dat", "r");

    int hasUser = 0;

    while(fread(&clie, sizeof(struct cliente), 1, ClieFile)){
        int compare = strcmp(tel, clie.telefone);
        if(compare == 0){
            printf ("\n                          Nome.....: %s", clie.nome);
            printf ("\n                          Endereço.: %s", clie.endereco);
            printf ("\n                          Telefone.: %s\n\n", clie.telefone);
            hasUser = 1;
            break;
        }
    };

    if(hasUser == 0){
        /* Se o usuario for inválido, execute Cadastrar e repita a verificação */
        system("./dist/clientes/CadastrarClientes");
        fclose (ClieFile); 
        isUser(tel);
    }else{
        printf("Usuario valido \n\n");
    }

    fclose (ClieFile); 

}

void CadastrarPedido(){

    /* Lê a lista de clientes */

    FILE *Carrinho; /* Cria um arquivo para armazenar a compra */
    Carrinho = fopen("./data/vendas/carrinho_de_compras.dat", "a"); /* Abre o arquivo para adição */
    struct produtos input; /* clie é o objeto informado */

    char tel[20]; /* Telefone do clientes */
    int confirm = 0;

    printf ("\n      Informe o telefone do Cliente:");   
    gets(tel);

    int emptyCar = 1; /* Verifica se o carrinho ainda esta vazio */

    /* Verifica se o numero de telefone existe na lista */

    isUser(tel);

    ESCOLHA:

    fflush(stdin);

    FILE *ProdFile;
    ProdFile = fopen("./data/produtos.dat", "r"); /* Abre o arquivo para leitura */
    struct produtos prod; /* prod é o objeto vindo da memoria */

    input.category = 0;

    printf("   ---------------------------------------------------------------------------------\n");
    printf("  |                        O que deseja comprar:                                    |\n");
    printf("  |           (1) Pizzas                     (4) Pizzas Grandes                     |\n");
    printf("  |           (2) Bebidas                    (5) Pizzas 1/2                         |\n");
    printf("  |           (3) Doces                      (6) Promocoes                          |\n");
    printf("  |           (0) Cancelar                                                          |\n");
    printf("   ---------------------------------------------------------------------------------\n");
    printf("\n \n Selecione uma das opcoes acima: ");
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
    case 6:
        LerProd( "Promocoes" , 6);
        break;
    case 0:
        if(emptyCar == 1){
            exit(0);
        }else if(emptyCar == 0){
            goto ADICIONAR;
        }

    default:
        printf ("\n                Informe um valor válido \n\n");
        fclose(ProdFile);
        goto ESCOLHA;
        break;
    }

    fflush(stdin);

    printf(" \n                Informe o id do produto:");
    scanf("%d", &input.id);
    
    int produtoValido = 0;

    while(fread(&prod, sizeof(struct produtos), 1, ProdFile)){

        if( input.category == prod.category ){
            if( input.id == prod.id ){
                printf ("\n                          id...: %d", prod.id);
                printf ("\n                          nome.: %s", prod.name);
                printf ("\n                          preco: %.2f\n\n", prod.price);
                produtoValido = 1;
                input.price = prod.price; /* Salva o valor do produto na struct input */
                input.quant = prod.quant;
                strcpy(input.name, prod.name);
                break;
            }
        }
    };

    if(produtoValido == 0){
        printf("                Produto Inválido \n");
        fflush(stdin);
        input.category = 0;
        fclose(ProdFile);
        goto ESCOLHA;
    }else{

        printf("         \n\nConfirmar pedido? [1] Sim - [0] Não: ");

        scanf("%d", &confirm);

        if(confirm != 1){
            printf("                      Compra cancelada!");
            fclose(ProdFile);
            goto ESCOLHA;
        }else{

            confirm = 0;        
            fwrite(&input, sizeof(struct produtos), 1, Carrinho); /* Grava o produto no carrinho */

            emptyCar = 0;

            if(&fwrite != 0){ 
                printf("\e[1;1H\e[2J");
                sucess();
            }else{
                printf("\e[1;1H\e[2J"); 
                error();
            }

        }

        ADICIONAR:

        printf("  Deseja adicionar produtos? [1] Sim - [0] Não: ");
        scanf("%d", &confirm);

        if(confirm == 1){
            confirm = 0;
            fclose(ProdFile);
            goto ESCOLHA;
            
        }else{

            fclose(Carrinho);
            fclose(ProdFile);

            /* Mostra o carrinho */
            LerCarrinho();
            /* ======================= */

            PAGAMENTO:
            
            printf("     Confirmar pagamento? [1] Sim - [0] Não: ");
            scanf("%d", &confirm);

            if(confirm == 1){

                compraFinalizada();
                fclose (Carrinho); 
                SalvarRelatorio(); /* Grava os dados em outro arquivo */
                ApagarCarrinho();

            }else if(confirm == 0){
                ApagarCarrinho();
                exit(0);
            }else{
                ValorValido();
                goto PAGAMENTO;
            }
        }
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese_Brasil");

    printf("\e[1;1H\e[2J");
    cab();
    CadastrarPedido();

    voltarMenu();
}