#include <stdio.h>
#include<stdlib.h>
#include <conio.h>
#include <locale.h>



void LerArquivoUsuario(){

    char usuario[50],senha[10],senhareal[10];
    FILE *ArqUsr;

    printf("Digite seu nome de usuário: ");gets(usuario);//Usuário digita o nome com que quer se logar
    ArqUsr = fopen(usuario,"r");//abre o arquivo com o nome do usuário
    printf("Digite sua senha: ");gets(senha);//usuário informa sua senha
    
        if(ArqUsr!=NULL){//se o arquivo com o nome informado existir
            fscanf (ArqUsr,"%*s",&senhareal);//grava o conteúdo de ArqUsr na variável senhareal
                if (strcmp(senha,senhareal)!=0)//e a senha informada pelo usuário bater com a senha real...
                {
                    printf("Login feito com sucesso!");//é informado ao usuário que ele conseguiu se logar
                    system("cd..");
                     system("cd menu");
                    //break;
                }
                else{//se não...
                        
                        printf("Usuário ou senha não está correto. Tente novamente...");//é informado que os dados estão incorretos
                        //break;
                }                                
        }
        else{
            printf("Usuário ou senha não está correto. Tente novamente...");//quando o usuário tenta entrar com um nome inválido
            //break;
        }
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
