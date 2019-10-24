struct promocoes{
    int id;
    int category;
    char name[20];
    float price;
};

void LerProm( char titulo[10], int category ){

    FILE *PromFile;
    struct promocoes prom;
    PromFile = fopen ("./data/promocoes.dat", "r");

    printf("\n =================== %s =================== \n", titulo);
    while(fread(&prom, sizeof(struct promocoes), 1, PromFile)){
        if(prom.category == category){
            printf ("\n id = %d \n nome = %s \n preco = %.2f\n", prom.id, prom.name, prom.price);
        }
    };

    fclose (PromFile);
}