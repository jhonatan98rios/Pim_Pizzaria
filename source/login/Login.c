	#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
/* #include <conio.h> */

struct funcionario{
    int category;
    char name[10];
    char senha[10];
};

void lerLogin(){

    FILE *Loginfile;
    struct funcionario input;
   
   
    char user [10];
    char password[10];
    int userValido = 0;
    int passValido = 0;

    printf("Digite seu usuário:");
    gets(user);
    fflush(stdin);
    
    printf("Digite sua senha:");
    gets(password);
    fflush(stdin);


    Loginfile = fopen ("./data/funcionarios.dat", "r");

    while(fread(&input, sizeof(struct funcionario), 1, Loginfile)){
        
        char compare = strcmp(input.name,user); //Atribui o valor da comparação a "Compare"
        char comparesenha = strcmp(input.senha,password); //Atribui o valor da comparação a "Comparesenha"

        if (compare==0){
            userValido = 1;

            if(comparesenha==0){
                passValido = 1;
                break;
            }else{
                passValido = 0;
            }
        }else{
            userValido = 0;
        }
    };

    if(userValido==1){
        printf("Usuario Valido \n");
        if(passValido==1){
            printf("Senha Valida\n");
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

    /* Isso se tornará uma biblioteca de cabeçalho */

    int continuar;

    /*printf("Deseja voltar ao menu? \n [1] Sim \n [2] Nao\n");
    scanf("%d", &continuar);
    if(continuar == 1){
        system("./source/menu");
    }else{
        printf("Programa Encerrado");
    }*/

    return 0;
}
