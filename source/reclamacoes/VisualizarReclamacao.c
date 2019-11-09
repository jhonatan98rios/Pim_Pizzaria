#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <string.h>

#include "../../libs/structs.h" 
#include "../../libs/voltar.h" 
#include "../../libs/cabSys.h" 

void LerRec(){

    FILE *infile;
    struct reclamacoes input;
    infile = fopen("./data/reclamacoes.dat", "r");

printf("   ----------------------------- Visualizar Reclamacoes -----------------------------\n\n");
    
    while(fread(&input, sizeof(struct reclamacoes), 1, infile)){

        printf ("\n                       Nome...: %s\n\n", input.nome);
        printf ("\n                       Mensage: %s\n\n", input.msg);
	}

    fclose (infile);
};



int main()
{
    //Define o padrão UTF-8
    setlocale(LC_ALL, "Portuguese_Brasil");
    cab();
    LerRec();

    voltarMenu();

    return 0;
}