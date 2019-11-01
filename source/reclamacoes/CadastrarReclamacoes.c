#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include <string.h>

#include "../../libs/structs.h"
#include "../../libs/voltar.h"

void reclamacao(){

FILE *RecFile;
    RecFile = fopen("./data/reclamacoes.dat", "a");	

    struct reclamacoes rec; 

	printf("Escreva seu nome: \n"  );
	gets(rec.nome); 
	fflush(stdin);

	printf("Mensagem: \n");
	gets(rec.msg);
	fflush(stdin);

	fwrite(&rec, sizeof(struct reclamacoes), 1, RecFile); /* Grava a estrutura no arquivo */
	if(&fwrite == 0){ /* Se conseguir gravar */
		printf("Erro ao gravar");
	}else{
		printf("Sucesso ao gravar!");
	}

	fclose(RecFile);

}

int main(){
    //Define o padrão UTF-8
    setlocale(LC_ALL, "Portuguese_Brasil");

    reclamacao();

    voltarMenu();

    return 0;
}