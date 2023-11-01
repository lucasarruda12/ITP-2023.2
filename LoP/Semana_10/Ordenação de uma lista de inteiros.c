#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ordenar_lista(int *lista, int tam){
    int trocas = -1;
    int ph = 0;

    while (trocas != 0){
        trocas = 0;

        for (int i = 0; i < tam-1; i++){
            if(lista[i] > lista[i + 1]){
                trocas++;

                ph = lista[i];
                lista[i] = lista[i+1];
                lista[i+1] = ph;
            }
        }
    }
}

int main(){
    char input[50] = {0};
    fgets(input, 49, stdin);

    int *lista;
    int tam = 0;
    int counter = 0;
    
    lista = (int *)malloc(tam * sizeof(int));
    for (int i = 0; i < strlen(input); i++){
        if (input[i] != ' ' & input[i] != '\n') {
            tam++;
            lista = realloc(lista, sizeof(int) * tam);

            sscanf(input + i, "%d ", &lista[counter]);
            counter++;

            while (input[i] != ' ' && input[i] != '\0') {
                i++;
            }
        } else {
            i++;
        }
    }

    ordenar_lista(lista, tam);

    for (int i = 0; i < tam; i++){
        printf("%d ", lista[i]);
    }

    free(lista);
}