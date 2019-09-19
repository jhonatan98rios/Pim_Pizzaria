#include <stdio.h>
#include<stdlib.h>
/* #include <conio.h> */
#include <locale.h>

void CadastrarProduto(){
    
}

void main()
{
    //Define o padrão UTF-8
    setlocale(LC_ALL, "Portuguese_Brasil");
    //Define a cor azul do terminal
    system("color 1F");
    //define o titulo da janela do prompt
    system("title Menu");
    LerArquivoUsuario();
}
