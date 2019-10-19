#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

struct produtos{
    int id;
    int category; /* Define se é pizza, bebida ou doce */
    char name[20];
    float price;
};

#endif