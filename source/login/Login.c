#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
/* #include <conio.h> */
#include "../../libs/structs.h" 
#include "../../libs/voltar.h"

void cab(){

    printf("                                                              \n");
    printf("                                                              \n");
    printf("   ---------------------------------------------------------------------------------\n");
    printf("  |                                                                                 |\n");
    printf("  |                              Sistema para Pizzaria                              |\n");
    printf("  |                                                                                 |\n");
    printf("  |                                    Unip 2019                                    |\n");
    printf("  |                                                                                 |\n");
    printf("   ---------------------------------------------------------------------------------\n");
    printf("\n\n\n");

}

void lerLogin(){

    FILE *Loginfile;
    struct funcionario input;

    char user[10];
    char password[10];
    int userValido = 0;
    int passValido = 0;

    printf("\e[1;1H\e[2J");
    printf("                               Digite seu usuário:");

    gets(user);
    fflush(stdin);
    
    printf("                               Digite sua senha...:");
    gets(password);
    fflush(stdin);


    Loginfile = fopen ("./data/funcionarios.dat", "r");

    while(fread(&input, sizeof(struct funcionario), 1, Loginfile)){
        
        char compare = strcmp(input.name,user); //Atribui o valor da comparação a "Compare"
        char comparesenha = strcmp(input.senha,password); //Atribui o valor da comparação a "Comparesenha"

        if (compare==0){//Verifica se a comparação de senha é verdadeira
            userValido = 1;//atriubui o valor 1 se o usuário existir

            if(comparesenha==0){//verifica se a comparação de senha é verdadeira
                passValido = 1;//Adiciona o valor 1 se a senha é verdadeira
                break;
            }else{
                passValido = 0;//Adiciona 0 se a senha for inválida
            }
        }else{
            userValido = 0;//Adiciona 0 se o usuário é inválido
        }
    };

<<<<<<< HEAD
    if(userValido==1){//Verifica se o usuário é válido
        //printf("Usuario Valido \n");
        if(passValido==1){//Verifica se a senha é válida
            if(input.tipoLogin == 1){
                system("./dist/menu");
            }
            else{
                system("./dist/menu-operacional");
            }
            //printf("Senha Valida\n");//senha válida
=======
    if(userValido==1){
        //printf("Usuario Valido \n");
        if(passValido==1){
            //printf("Senha Valida\n");
            system("..\\menu.exe");
>>>>>>> 9a4d848b2e8bf70eb761b9ea316053ac12812df4
            /* Gravar arquivo temp */
        }else{
            printf("Senha invalida\n");
        }
    }else{
        printf("User Invalido\n");
    }

    fclose (Loginfile);
}


int main()
{
    //Define o padrão UTF-8
    setlocale(LC_ALL, "Portuguese_Brasil");
    //Define a cor azul do terminal
    system("color 1F");
    //define o titulo da janela do prompt
    system("title login");

<<<<<<< HEAD
=======
    // printf("\e[1;1H\e[2J");
    cab();
>>>>>>> 9a4d848b2e8bf70eb761b9ea316053ac12812df4
    lerLogin();

    return 0;
}
