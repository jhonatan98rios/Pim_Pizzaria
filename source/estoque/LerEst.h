struct estoque{
    int id;
    char nome[20];
    int quantidade;
};

void LerEst(){
    FILE *EstoqueFile;
    struct estoque est;
    EstoqueFile = fopen("estoque.dat", "r");

    while(fread(&est, sizeof(struct estoque), 1, EstoqueFile)){
        printf ("\n id = %d \n nome = %s \n quantidade = %d \n", est.id, est.nome, est.quantidade);
    };

    fclose (EstoqueFile);
}