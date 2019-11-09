#include<stdio.h>
#include<stdlib.h>
/* #include <windows.h> */
#include <locale.h>
 
 int main(){
     
    int resposta;

    printf("\e[H\e[2J"); //Limpa a tela

    printf("\n ==============================================");
    printf("\n ============ Reclamações ==============");
    printf("\n ==============================================");
    printf("\n \n");

    printf("\n (1) Vizualizar Reclamações");
    printf("\n (2) Adicionar Reclamações");

    scanf("%d", &resposta);

    switch (resposta)
    {
    case 1:
        printf("\e[H\e[2J"); //Limpa a tela
        system("./dist/reclamacoes/VisualizarReclamacao");
        break;
    case 2:
        printf("\e[H\e[2J"); //Limpa a tela
        system("./dist/reclamacoes/CadastrarReclamacoes");
        break;
    }
}   