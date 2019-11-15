
void voltarMenu(){

    int continuar;

    printf("   ---------------------------------------------------------------------------------\n");
    printf("   Deseja voltar ao menu?\n");
    printf("   [1] Sim \n");
    printf("   [2] Nao\n");
    scanf("%d", &continuar);
    if(continuar == 1){
        system(".\\dist\\menu");
    }else{
        printf("--------------------\n");
        printf("| Programa Encerrado |\n");
        printf("--------------------\n");
        
    }
};
