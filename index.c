#include<stdio.h>
#include<stdlib.h>
/* #include <windows.h> */
#include <locale.h>

int main(){
    
    printf("\e[1;1H\e[2J");
    
    system(".\\dist\\login\\Login"); //Esse arquivo esta com erro. Mas ele devera ser chamado
    /* system("./dist/menu"); */ //Substitui o login por hora
}


/* Esse arquivo deve ser executado primeiro, pois ele sera a referencia a todos os diretórios  */