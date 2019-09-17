//Em desenvolvimento (Não mexer)

#include <stdio.h>
#include <json-c/json.h>
/* #include <conio.h> */
#include <locale.h>

void vizualizarProdutos(){
    FILE *fp;
    char buffer[1024];

    struct json_object *parsed_json;
    struct json_object *name;
    struct json_object *age;
    struct json_object *friends;

    struct json_object *friend;
    size_t n_friends;
    size_t i;

    fp = fopen("produtos.json", "r");
    fread(buffer, 1024, 1, fp);
    fclose(fp);

    parsed_json = json_tokener_parse(buffer);

    json_object_object_get_ex(parsed_json, "name", &name);

    printf("Name: %s\n", json_object_get_string(name));

    n_friends = json_object_array_length(friends);

    for(i=0; i<n_friends; i++){
        friend = json_object_array_get_idx(friends, i);
        printf("%s", json_object_get_string(friend));
    };
};

int main(){
        //Define o padrão UTF-8
    setlocale(LC_ALL, "Portuguese_Brasil");
    //Define a cor azul do terminal
    /* system("color 1F"); */
    //define o titulo da janela do prompt
    /* system("title Menu"); */
    vizualizarProdutos();
}
