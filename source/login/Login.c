#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include <conio.h>
#include "../../libs/structs.h" 
#include "../../libs/voltar.h"
#include "../../libs/cabSys.h"

void lerLogin(){

    FILE *Loginfile;
    struct funcionario input;

    char user[10];
    char password[10];
    int userValido = 0;
    int passValido = 0;

    printf("                               Digite seu usuario:");

    gets(user);
    fflush(stdin);
    
    printf("                               Digite sua senha...:");
    gets(password);
    fflush(stdin);


    Loginfile = fopen (".\\data\\funcionarios.dat", "r");

    while(fread(&input, sizeof(struct funcionario), 1, Loginfile)){
        
        char compare = strcmp(input.name,user); //Atribui o valor da comparacao a "Compare"
        char comparesenha = strcmp(input.senha,password); //Atribui o valor da comparacao a "Comparesenha"

        if (compare==0){    //Verifica se a comparacao de senha e verdadeira
            userValido = 1; //atriubui o valor 1 se o usuario existir

            if(comparesenha==0){    //verifica se a comparacao de senha e verdadeira
                passValido = 1; //Adiciona o valor 1 se a senha e verdadeira
                break;
            }else{
                passValido = 0; //Adiciona 0 se a senha for invalida
            }
        }else{
            userValido = 0; //Adiciona 0 se o usuario e invalido
        }
    };

    if(userValido==1){  //Verifica se o usuario e valido
        if(passValido==1){  //Verifica se a senha e valida
            if(input.tipoLogin == 1){
                system(".\\dist\\menu");
            }
            else{
                system(".\\dist\\operacional\\MenuEstoque");
            }
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
    //Define o padrao UTF-8
    setlocale(LC_ALL, "Portuguese_Brasil");
    //Define a cor azul do terminal
    system("color 1F");
    //define o titulo da janela do prompt
    system("title login");

    cab();

    lerLogin();

    return 0;
}
