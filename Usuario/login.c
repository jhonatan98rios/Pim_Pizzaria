#include <stdio.h>
#include<stdlib.h>
/* #include <conio.h> */
#include <locale.h>


/*
Autor: Hugo Barros
Data de criação 15/09/2019
Descrição:
Implementação 01: Feito a criação da função (LerArquivoUsuario),O mesmo vai ler o arquivo texto com o nome do usuário caso esteja certo usuário e senha o login será feito
Implementação 02: Feito a criação do arquivo temporario para que guarde o usuário que logar no sistema
*/

void LerArquivoUsuario(){

    char usuario[50],senha[10],senhareal[10];
    FILE *ArqUsr;
    FILE *UsuarioLogado;

    printf("Digite seu nome de usuario: ");gets(usuario);//Usuário digita o nome com que quer se logar
    ArqUsr = fopen(usuario,"r");//abre o arquivo com o nome do usuário
    printf("Digite sua senha: ");gets(senha);//usuário informa sua senha
    
        if(ArqUsr!=NULL){//se o arquivo com o nome informado existir
            fscanf (ArqUsr,"%*s",&senhareal);//grava o conteúdo de ArqUsr na variável senhareal
                if (strcmp(senha,senhareal)!=0)//e a senha informada pelo usuário bater com a senha real...
                {
                    printf("Login feito com sucesso!");//é informado ao usuário que ele conseguiu se logar
                    //system("cd..");
                    //system("cd menu");
                    UsuarioLogado =fopen("Usuario_Logado.txt","a");
                    fprintf(UsuarioLogado,"%s",usuario);//grava no arquivo usuário Usuário que logou
                    fclose(UsuarioLogado);//fecha o arquivo
                    //break;
                }
                else{//se não...
                        
                    printf("Usuario ou senha nao estao correto. Tente novamente...");//é informado que os dados estão incorretos
                        //break;
                }                                
        }
        else{
            printf("Usuario nao cadastrado...");//quando o usuário tenta entrar com um nome inválido
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
