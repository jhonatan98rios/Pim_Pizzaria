#include<stdio.h>
#include<stdlib.h>
/* #include <windows.h> */
#include <locale.h>
#include "../../libs/voltar.h" 
 
 int main(){

   int resposta;
     
   printf("\e[H\e[2J"); //Limpa a tela

   printf("   ---------------------------------------------------------------------------------\n");
   printf("  |                         Opcoes disponiveis:                                     |\n");
   printf("  |                                                                                 |\n");
   printf("  |             (1) Relatorio Diário       (2) Relatorio Mensal                     |\n");
   printf("  |             (0) Voltar                                                          |\n");
   printf("   ---------------------------------------------------------------------------------\n");
   printf("\n \n Selecione uma das opcoes acima: ");
   scanf("%d", &resposta);

   switch (resposta)
   {
   case 1:
      printf("\e[H\e[2J"); //Limpa a tela
      system(".\\dist\\relatorios\\RelatoriosDiarios");
      break;
   case 2:
      printf("\e[H\e[2J"); //Limpa a tela
      system(".\\dist\\relatorios\\RelatoriosMensais");
      break;
   default:
      voltarMenu();
   }

}
   