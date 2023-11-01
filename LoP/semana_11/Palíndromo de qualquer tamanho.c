#include <stdio.h>
#include <string.h>

void removerEspacos(char *string){
    for (int i = 0; i < strlen(string); i++){
        if (string[i] == ' '){
            for (int j = i; j < strlen(string) - 1; j++){
                string[j] = string[j+1];
            }

            string[strlen(string) - 1] = 0;
        }
    }
}

int e_palindromo(char *palavra){
    int tam_palavra = strlen(palavra);

    if(tam_palavra == 0 || tam_palavra == 1){
        return 1;
    }

    if(palavra[0] == palavra[tam_palavra - 1]){
        palavra[tam_palavra - 1] = 0;
        e_palindromo(palavra + 1);
    } else {
        return 0;
    }
}

int palindromo(char *string){
    char palavra[strlen(string)];
    strcpy(palavra, string);
    removerEspacos(palavra);
    return e_palindromo(palavra);
}

int main(){
    char input[100] = {0};
    fgets(input, 99, stdin);

    if (palindromo(input)){
        printf("O texto \"%s\" é palíndromo", input);
    } else {
        printf("O texto \"%s\" não é palíndromo", input);
    }
}