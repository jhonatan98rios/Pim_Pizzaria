#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

struct produtos{
    int id;
    int category; /* Define se é pizza, bebida ou doce */
    char name[20];
    float price;
};

struct cliente{
    char nome[20];
    char endereco[30];
    char telefone[20];
};

struct reclamacoes{
	char nome[20];
	char msg[150];
};

#endif