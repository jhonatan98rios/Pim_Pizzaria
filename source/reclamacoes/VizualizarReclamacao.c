#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
/* #include <conio.h> */

struct reclamacoes{
    char nome[10];
    char mensagem [150];
};

void LerRec( ){

    FILE *infile;
    struct reclamacoes input;
    infile = fopen ("rec.dat", "r");

    printf("\n =================== Reclamacoes =================== \n");
    while(fread(&input, sizeof(struct reclamacoes), 1, infile)){
            printf ("\n nome = %s \n mensage, = %s \n", input.nome, input.mensagem);
        }
    

    fclose (infile);
};



int main()
{
    //Define o padrão UTF-8
    setlocale(LC_ALL, "Portuguese_Brasil");
    
    printf("\e[1;1H\e[2J");
    
    LerRec();

    

    int continuar;

    printf("Deseja voltar ao menu? \n [1] Sim \n [2] Nao\n");
    scanf("%d", &continuar);
    if(continuar == 1){
        system("./source/menu");
    }else{
        printf("Programa Encerrado");
    }

    return 0;
}
