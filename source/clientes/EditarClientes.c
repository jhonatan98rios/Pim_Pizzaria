#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
/* #include <conio.h> */
#include "../../libs/structs.h"
#include "../../libs/voltar.h"
#include "../../libs/cabSys.h"
#include "../../libs/Mensagem.h"


void editar(){

    FILE *infile;
    FILE *tempFile;
    struct cliente input;
    char foneCliente [20];
    char novoEndereco[20];

    infile = fopen(".\\data\\clientes.dat", "r");
    tempFile = fopen(".\\data\\clientesTemp.dat", "w");
    

    printf("   -------------------------------  Editar Cliente  --------------------------------\n\n");
    printf("                            Informe o Numero do cliente: ");
    gets(foneCliente);
    fflush(stdin);

    while(fread(&input, sizeof(struct cliente), 1, infile)){

       int Compare = strcmp(foneCliente,input.telefone);


        if(Compare != 0){
           fwrite(&input, sizeof(struct cliente),1,tempFile);
        }else{
            printf("\n                            Cliente encontrado com o telefone: %s ", input.telefone);
            printf ("\n                            Nome....: %s", input.nome);
            printf ("\n                            Endereco: %s", input.endereco);
            printf ("\n                            Telefone: %s", input.telefone);
            fflush(stdin);
             printf("\n   ---------------------------------------------------------------------------------\n");
            printf("                             Digite o novo endereco: ");
            gets(input.endereco);
             fwrite(&input, sizeof(struct cliente),1,tempFile);

             sucess();
        }
    };
    fclose(infile);
    fclose(tempFile);
}

int main(){
    system("color 1F");
    setlocale(LC_ALL,"Portuguese_Brazil");
    cab();
    editar();
    voltarMenu();

    return 0;
}
