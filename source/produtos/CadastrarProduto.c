#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
/* #include <conio.h> */

struct produto{
        char nome[10];
        float preco;
};

void LerProdutos(){
    FILE *infile;
    struct produto input;
    infile = fopen ("produtos.dat", "r");

    while(fread(&input, sizeof(struct produto), 1, infile))
    
    printf ("nome = %s preco = %f\n", input.nome, input.preco);

    fclose (infile);
}


void CadastrarProduto(){

    FILE *ProdFile;
    ProdFile = fopen("produtos.dat", "w");

    struct produto prod;

    printf("Informe o nome do produto: ");
    scanf("%s", prod.nome);
    printf("Informe o preco: ");
    scanf("%f", &prod.preco);

    fwrite (&prod, sizeof(struct produto), 1, ProdFile);

    if(&fwrite != 0)  
        printf("Salvo com sucesso !\n"); 
    else 
        printf("Erro ao gravar !\n");

    fclose(ProdFile);
    
}

int main()
{
    //Define o padrão UTF-8
    setlocale(LC_ALL, "Portuguese_Brasil");
    //Define a cor azul do terminal
    //system("color 1F");
    //define o titulo da janela do prompt
    //system("title Menu");

    //CadastrarProduto();

    LerProdutos();

    return 0;
}
