#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_in(char c, char str[]){
    int tam = strlen(str);

    for (int i = 0; i < tam; i++){
        if (c == str[i]){
            return true;
        }
    }

    return false;
}

int main(){
    char seq[51] = {0};
    char pad[21] = {0};

    fgets(seq, 51, stdin);
    fgets(pad, 21, stdin);

    int tamSeq = strlen(seq);
    int tamPad = strlen(pad);
    bool match = true;

    for (int i = 0; i < (tamSeq - tamPad); i++){
        match = true;

        for (int j = 0; j < tamPad; j++){
            printf("%c ", seq[i + j], pad[j]);

            if (!(seq[i + j] == pad[j])){
                match = false;
                printf("não");

                if (is_in(seq[i+j], pad) == false){
                    i = i + j;
                }

                break;
            }
        }

        if (match == true){
            printf("sim\n");
            printf("Achei o padrão no índice %d", i);
            break;
        }

        printf("\n");
    }

    if (match == false){
        printf("Não achei o padrão");
    }
}