void voltarMenu(){

    int continuar;

    printf("Deseja voltar ao menu? \n [1] Sim \n [2] Nao\n");
    scanf("%d", &continuar);
    if(continuar == 1){
        system("./dist/menu");
    }else{
        printf("Programa Encerrado");
    }
};