#include<stdio.h>
#include<stdlib.h>
/* #include <windows.h> */
#include <locale.h>
 
 int main(){
     
    int resposta;

    printf("\e[H\e[2J"); //Limpa a tela

    printf("\n ==============================================");
    printf("\n ============ Promoções ==============");
    printf("\n ==============================================");
    printf("\n \n");

    printf("\n (1) Vizualizar Promoções");
    printf("\n (2) Adicionar Promoções");
    printf("\n (3) Excluir Promoções \n");

    scanf("%d", &resposta);

    switch (resposta)
    {
    case 1:
        printf("\e[H\e[2J"); //Limpa a tela
        system("./source/promocoes/VizualizarPromocoes");
        break;
    case 2:
        printf("\e[H\e[2J"); //Limpa a tela
        system("./source/promocoes/CadastrarPromocoes");
        break;
    case 3:
        printf("\e[H\e[2J"); //Limpa a tela
        printf("\n Excluir");
        break;
    }
}   