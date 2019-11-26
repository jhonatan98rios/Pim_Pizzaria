#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
/* #include <conio.h> */
#include "../../libs/structs.h" /* Essa e a classe de produto */
#include "../../libs/voltar.h" /* Essa e a classe de produto */
#include "../../libs/cabSys.h"

void LerFunc( char titulo[10], int tipoLogin ){

    FILE *infile;
    struct funcionario input;
    infile = fopen (".\\data\\funcionarios.dat", "r");
    
    printf("   ------------------------------%s--------------------------------------\n\n",titulo);
    while(fread(&input, sizeof(struct funcionario), 1, infile)){
        
        if(tipoLogin == input.tipoLogin){
            printf ("\n               Nome do usuario.: %s\n", input.name);
            printf ("\n               CPF do usuario..: %s\n\n", input.cpf);
            printf("   --------------------------------------------------------------------------------\n\n");
        }
    }

    printf("   --------------------------------------------------------------------------------\n\n");
    fclose (infile);
}

void LerFuncionario(){

    printf("   ------------------------------Visualizar Funcionario------------------------------\n\n");

    LerFunc( "Usuario Administrativo" , 1);
    LerFunc( "Usuario Operacional" , 2);

    printf("\n\n");
};

int main()
{
    /* const char* menu = "/../menu.exe"; */
    //Define o padrao UTF-8
    setlocale(LC_ALL, "Portuguese_Brasil");
    //Define a cor azul do terminal
    system("color 1F");
    //define o titulo da janela do prompt
    system("title Menu");

    cab();
    LerFuncionario();

    /* Isso se tornara uma biblioteca de cabecalho */

    voltarMenu();

    return 0;
}