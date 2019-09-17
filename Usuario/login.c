#include <stdio.h>
/* #include <conio.h> */

//Ainda estou implementando
void lerArq()
{
       FILE *arq;
  char Linha[100];
  char *result;
  int i;
 // clrscr();
  // Abre um arquivo TEXTO para LEITURA
  arq = fopen("ArqTeste.txt", "rt");
  if (arq == NULL)  // Se houve erro na abertura
  {
     printf("Problemas na abertura do arquivo\n");
     return;
  }
  i = 1;
  while (!feof(arq))
  {
      /* char usuario;
      int senha; */
	// Lê uma linha (inclusive com o '\n')
      result = fgets(Linha, 100, arq);  // o 'fgets' lê até 99 caracteres ou até o '\n'
      if (result){ // Se foi possível ler
      /* usuario = Linha[4];
      senha = Linha[6,9]; */
	  //printf("Linha %d : %s",i,Linha);
      //i++;
    }

  }
   
  fclose(arq);
}

int main()
{
    
    char user;
    int password;
    printf("\n Digite o Usuario:");
    scanf("%s",&user);
    printf("\n Digite a Senha:");
    scanf("%d",&password);

}