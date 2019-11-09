#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
/* #include <conio.h> */
#include "../../libs/structs.h" /* Essa é a classe de produto */
#include "../../libs/voltar.h" /* Essa é a classe de produto */


void LerFunc( char titulo[10], int tipoLogin ){

    FILE *infile;
    struct funcionario input;
    infile = fopen ("./data/funcionarios.dat", "r");
    
    printf("\n =============== %s =============== \n", titulo);
    while(fread(&input, sizeof(struct funcionario), 1, infile)){
        
        if(tipoLogin == input.tipoLogin){
            printf ("\n Nome do usuario: %s\n\n", input.name);
            printf ("\n CPF do usuario: %s\n\n", input.cpf);
            printf(" 1-Administrativo\n 2-Operacional\n Cargo: %d \n", input.tipoLogin);
            printf("\n-----------------------------------------------");
        }
    }

    printf("=========================================");
    fclose (infile);
}

void LerFuncionario(){

    printf("\n ==============================================");
    printf("\n =============== Funcionarios =================");
    printf("\n ==============================================\n");

    LerFunc( "Usuário Master" , 1);
    LerFunc( "Usuário Opera." , 2);

    printf("\n\n");
};

int main()
{
    /* const char* menu = "/../menu.exe"; */
    //Define o padrão UTF-8
    setlocale(LC_ALL, "Portuguese_Brasil");
    //Define a cor azul do terminal
    //system("color 1F");
    //define o titulo da janela do prompt
    //system("title Menu");

    printf("\e[1;1H\e[2J");
    LerFuncionario();

    /* Isso se tornará uma biblioteca de cabeçalho */

    voltarMenu();

    return 0;
}