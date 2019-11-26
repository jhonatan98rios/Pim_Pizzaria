#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <string.h>

#include "../../libs/structs.h"
#include "../../libs/voltar.h"
#include "../../libs/cabSys.h"
#include "../../libs/Mensagem.h"

void reclamacao(){

FILE *RecFile;
    RecFile = fopen(".\\data\\reclamacoes.dat", "a");	

    struct reclamacoes rec; 

	printf("                               Escreva seu nome: " );
	gets(rec.nome); 
	fflush(stdin);

	printf("                                       Mensagem: ");
	gets(rec.msg);
	fflush(stdin);

	fwrite(&rec, sizeof(struct reclamacoes), 1, RecFile); /* Grava a estrutura no arquivo */
	if(&fwrite == 0){ /* Se conseguir gravar */
		error();
	}else{
		sucess();
	}

	fclose(RecFile);

}

int main(){
    //Define o padrao UTF-8
    setlocale(LC_ALL, "Portuguese_Brasil");
	cab();
    reclamacao();

    voltarMenu();

    return 0;
}