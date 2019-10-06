#include <stdio.h>
/* #include <conio.h> */
#include <locale.h>

/*
Autor: Hugo Barros
Data de criação 09/09/2019
Descrição:
Implementação 01: Feito a criação da função (cadastrar),O mesmo vai criar um arquivo de texto com o nome do usuário e inserir a senha dentro dele
*/

void cadastrar(){
    char usuario[50],senha[10],area[1];
    FILE *ArqUsr;
                
    printf("\n ==============================================");
    printf("\n ========== Usuários/Funcionario ==============");
    printf("\n ==============================================");
    printf("\n \n");

    printf("Digite seu nome: ");gets(usuario);//Usuário insere o nome com que quer ser cadastrado
    printf("Digite seu setor: (1) Administrativo, (2) Operacional) ");gets(area);
    printf("Digite sua senha: ");gets(senha);//usuário digita sua senha
   
                
    ArqUsr=fopen(usuario,"a");//fazer um arquivo com o nome do usuário
                  
    
    fprintf(ArqUsr,"*%s",senha);//grava no arquivo a senha do usuário, antecedida pelo caractere *
    senha[10]=" ";
    fprintf(ArqUsr,"*%s",area);
    fclose(ArqUsr);//fecha o arquivo
    printf("Usuário cadastrado com sucesso!");
                
}

int main(){
        //Define o padrão UTF-8
    setlocale(LC_ALL, "Portuguese_Brasil");
    //Define a cor azul do terminal
    /* system("color 1F"); */
    //define o titulo da janela do prompt
    /* system("title Menu"); */
    cadastrar();
}
