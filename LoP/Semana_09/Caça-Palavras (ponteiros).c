#include <stdio.h>
#include <string.h>
#include <ctype.h>

void imprimePalavra (char *c, int salto, int tam){
    if(c==NULL){
        printf("Palavra nao encontrada\n");
        return;
    }

    for (int i =0; i < tam; i++){
        printf("%c", *c);
        c+=salto;
    }

    printf(", salto:%d\n", salto);
}

void encontrar_palavra(char tabuleiro[10][10], char palavra[]){
    int pos_0, pos_1;
    int salto = 0;
    int tam_palavra = strlen(palavra);

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (tolower(tabuleiro[i][j]) == tolower(palavra[0])){
                pos_0 = i*10 + j;

                for (int i2 = 0; i2 < 10; i2++){
                    for (int j2 = 0; j2 < 10; j2++){
                        if (tolower(tabuleiro[i2][j2]) == tolower(palavra[1])){
                            pos_1 = i2*10 + j2;

                            salto = pos_1 - pos_0;

                            for (int k = 1; k < tam_palavra; k++){
                                int salto_k = (pos_0 + (salto * k)) % 99;

                                if(tolower(palavra[k]) != tolower(tabuleiro[(salto_k) / 10][(salto_k) % 10])){
                                    break;
                                }

                                if (k == (tam_palavra - 1)){
                                    imprimePalavra(&tabuleiro[pos_0 / 10][pos_0 % 10], salto, tam_palavra);
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    char *null = NULL;

    imprimePalavra(null, salto, tam_palavra);
}

int main(){
    int num_palavras;
    scanf("%d", &num_palavras);
    getchar();

    char palavras[num_palavras][20];
    for (int i = 0; i < num_palavras; i++){
        fgets(palavras[i], 20, stdin);
        palavras[i][strlen(palavras[i]) - 1] = 0;
    }

    char tabuleiro[10][10];
    for(int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            scanf("%c", &tabuleiro[i][j]);
        }
        getchar();
    }

    for(int i = 0; i < num_palavras; i++){
        encontrar_palavra(tabuleiro, palavras[i]);
    }
}