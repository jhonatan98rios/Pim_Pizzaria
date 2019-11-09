#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <string.h>

#include "../../libs/structs.h" 
#include "../../libs/voltar.h" 

void LerRec(){

    FILE *infile;
    struct reclamacoes input;
    infile = fopen("./data/reclamacoes.dat", "r");

    printf("\n =================== Reclamacoes =================== \n");
    while(fread(&input, sizeof(struct reclamacoes), 1, infile)){
		printf("\n nome = %s \n mensage = %s \n\n", input.nome, input.msg);
	}

    fclose (infile);
};



int main()
{
    //Define o padrão UTF-8
    setlocale(LC_ALL, "Portuguese_Brasil");

    LerRec();

    voltarMenu();

    return 0;
}