#include<stdio.h>
#include<stdlib.h>
//#include <windows.h>
#include <locale.h>

//=======================

int main(){

    //Define o padrão UTF-8
    setlocale(LC_ALL, "Portuguese_Brasil");
    //Define a cor azul do terminal
    system("color 1F");
    //define o titulo da janela do prompt
    system("Cadastro de Funcionarios");

    printf("\e[H\e[2J"); //Limpa a tela

    printf("\n =====================================================");
    printf("\n ============ Cadastro de funcionarios ==============");
    printf("\n =====================================================");
    printf("\n");

}