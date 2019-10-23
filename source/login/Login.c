	#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
/* #include <conio.h> */
#include "FuncStruct.h"

void lerLogin(){

    FILE *Loginfile;
    struct funcionario input;
   
   
    char user[10];
    char password[10];
    int userValido = 0;
    int passValido = 0;

    printf("Digite seu usuário:");
    scanf("%s", &user);
    
    printf("Digite sua senha:");
    scanf("%s", &password);


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

    if(userValido==1){//Verifica se o usuário é válido
        //printf("Usuario Valido \n");
        if(passValido==1){//Verifica se a senha é válida
            if(input.tipoLogin == 1){
                system("./source/menu");
            }
            else{
                system("./source/menu-operacional");
            }
            //printf("Senha Valida\n");//senha válida
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
    //system("color 1F");
    //define o titulo da janela do prompt
    //system("title Menu");

    printf("\e[1;1H\e[2J");
    lerLogin();

    return 0;
}
