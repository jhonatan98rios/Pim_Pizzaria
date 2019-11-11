#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

/* #include <windows.h> */
/* #include <conio.h> */
#include "../../libs/structs.h" /* Essa é a classe de produto */
#include "../../libs/voltar.h" /* Essa é a classe de produto */


void remover(){
 FILE *FuncFile;
 struct funcionario func;
 char cpf[11];
 int confirma = 0;
 int compare;

printf("Informe o CPF a ser excluido:");
scanf("%s",cpf);

 FuncFile = fopen("./data/funcionarios.dat","r");

 FILE *FuncTemp;
 FuncTemp = fopen("./data/funcionariosTemp.dat","w");

 while(fread(&func, sizeof(struct funcionario),1,FuncFile)){

     compare = strcmp(func.cpf, cpf);

     if(compare != 0){
         fwrite(&func, sizeof(struct funcionario),1,FuncTemp);
     }else{
         printf("Tem certeza que deseja excluir o %s?\n [1] Sim \n [0] Nao\n", func.name);
         scanf("%d", &confirma);
        if(confirma == 1){
            printf("Funcionario Excluido com sucesso!!");
        }else{
            fwrite(&func, sizeof(struct funcionario),1,FuncTemp);
            printf("Exclusão cancelada!!")
        }
        
     }
 }

    fclose(FuncFile);
    remove("./data/funcionarios.dat");
    rename("./data/funcionariosTemp.dat","./data/funcionarios.dat");
}



int main(){

remover();
voltarMenu();

}

