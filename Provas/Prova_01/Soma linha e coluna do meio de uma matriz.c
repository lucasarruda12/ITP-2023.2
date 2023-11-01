#include <stdio.h>

void somaLinhaMatrizMeio(int l, int c, int m[l][c]){
    int soma_linha = 0;
    int soma_coluna = 0;

    int meio_linhas = (l/2);
    int meio_colunas = (c/2);

    // printf("%d %d", meio_colunas, meio_linhas);

    for (int i = 0; i < l; i++){
        soma_linha = soma_linha + m[i][meio_colunas];
    }

    for (int i = 0; i < c; i++){
        soma_coluna = soma_coluna + m[meio_linhas][i];
    }

    printf("%d", (soma_coluna + soma_linha));
}

int main(){
    int l, c;
    scanf("%d%d", &l, &c);

    int m[l][c];
    for (int i = 0; i < l; i++){
        for (int j = 0; j < c; j++){
            scanf("%d", &m[i][j]);
        }
    }

    somaLinhaMatrizMeio(l, c, m);
}