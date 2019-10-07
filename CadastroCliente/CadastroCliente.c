#include<stdio.h>
#include<conio.h>
#include<locale.h>



int Cadastrar(){
    //char cliente
    char Numero[50],Nome[20],Endereco[50];
    FILE *ArqNumero;


    printf("\n ======================================================================");
    printf("\n =================== Cadastro de Cliente =======================");
    printf("\n =======================================================================");
    printf("\n\n");


    printf("Digite o telefone do cliente:");gets(Numero);//Usuario insere o telefone que vai cadastrar o cliente
    printf("Digite o nome do cliente:");gets(Nome);//Usuario insere o nome do cliente
    printf("Digite o endereço do cliente:");gets(Endereco);//Usuario insere o endereço do cliente

    ArqNumero=fopen(Numero,"a");//Fazer um arquivo com o numero do cliente

    prinf("Cliente cadastrado com sucesso");
    fprint(ArqNumero,"*%s",Nome);//Grava no arquivo o nome do cliente,antecedida pelo caractete *
    fprint(ArqNumero,"*%s",Endereco);//Grava no arquivo o endereço do cliente,antecedida pelo caractere *
    fclose(ArqNumero);//Fecha o arquivo



}
int main(){
    //Define o padrão UTF-8
    setlocale(LC_ALL,"Portuguese_Brasil");
    //Define a cor azul do terminal
    system("color 1F");
    //Define o titulo da janela do prompt
    system("title Cadastro Cliente");
    Cadastrar();









}