#include <stdio.h>
#include <conio.h>
#include <locale.h>


/*
Autor: Hugo Barros
Data de criação 09/09/2019
Descrição:
Implementação 01: Feito a criação da função (cadastrar),O mesmo vai criar um arquivo de texto com o nome do usuário e inserir a senha dentro dele
*/
int cadastrar(){
    //char opl;
    char usr[50],senha[10];
    FILE *ArqUsr;
                
    printf("\n ==============================================");
    printf("\n ============ Usuários ==============");
    printf("\n ==============================================");
    printf("\n \n");

    printf("Digite seu nome: ");gets(usr);//Usuário insere o nome com que quer ser cadastrado
    printf("Digite sua senha: ");gets(senha);//usuário digita sua senha
                
    ArqUsr=fopen(usr,"a");//fazer um arquivo com o nome do usuário
                  
    printf("Usuário cadastrado com sucesso!");
    fprintf(ArqUsr,"*%s",senha);//grava no arquivo a senha do usuário, antecedida pelo caractere *
    fclose(ArqUsr);//fecha o arquivo
    getch();
                
}

int main(){
        //Define o padrão UTF-8
    setlocale(LC_ALL, "Portuguese_Brasil");
    //Define a cor azul do terminal
    system("color 1F");
    //define o titulo da janela do prompt
    system("title Menu");
    cadastrar();
}
