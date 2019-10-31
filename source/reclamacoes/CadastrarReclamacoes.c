#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <string.h>

#include "../../libs/structs.h" /* Essa é a classe de produto */
#include "../../libs/voltar.h" /* Essa é a classe de produto */

void reclamacao(){

FILE *RecFile;
    RecFile = fopen("../../data/reclamacoes.dat", "a");	

    struct reclamacoes rec; 

	printf("Escreva seu nome: \n"  );
	gets(rec.nome); 
	fflush(stdin);

	printf("Mensagem: \n");
	gets(rec.msg);
	fflush(stdin);

	fwrite (&rec, sizeof(struct reclamacoes), 1, RecFile); /* Grava a estrutura no arquivo */
	if(&fwrite != 0){ /* Se conseguir gravar */
		printf("\e[1;1H\e[2J");
	}

	fclose(RecFile);

}

int main(){
    //Define o padrão UTF-8
    setlocale(LC_ALL, "Portuguese_Brasil");

    printf("\e[1;1H\e[2J");

    reclamacao();

    voltarMenu();

    return 0;
}