#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>


struct reclamacoes{
	char nome [20];
	char msg [150];
	
};

void reclamacao(){


FILE *RecFile;
    RecFile = fopen("reclamacoes.dat", "a");	
    
    struct reclamacoes rec; 
    
        printf("Escreva seu nome: \n"  );
         scanf("%s", rec.nome); 
        printf("Mensagem: \n");
        scanf("%s", rec.msg);
        
       
       fwrite (&rec, sizeof(struct reclamacoes), 1, RecFile); /* Grava a estrutura no arquivo */
       if(&fwrite != 0){ /* Se conseguir gravar */
        printf("\e[1;1H\e[2J");
        
        
        
           fclose(RecFile);

}
  
}

int main()
{
    //Define o padrão UTF-8
    setlocale(LC_ALL, "Portuguese_Brasil");
   

    printf("\e[1;1H\e[2J");
    
    
    reclamacao();

    /* Isso se tornará uma biblioteca de cabeçalho */
    int continuar;

    printf("Deseja voltar ao menu? \n [1] Sim \n [2] Nao\n");
    scanf("%d", &continuar);
    if(continuar == 1){
        system("./source/menu");
    }else{
        printf("Enviado com sucesso");
    }

    return 0;
}





