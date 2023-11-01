#include <stdio.h>

void flatten(int l, int c, int m[l][c], int vetor[], int ordem){
    int counter = 0;

    if (ordem == 0){
        for (int i = 0; i < l; i++){
            for (int j = 0; j < c; j++){
                vetor[counter] = m[i][j];
                counter++;
            }
        }
    }

    if (ordem == 1){
        for (int i = 0; i < c; i++){
            for (int j = 0; j < l; j++){
                vetor[counter] = m[j][i];
                counter++;
            }
        }
    }

    for (int i = 0; i < counter; i++){
        printf("%d ", vetor[i]);
    }
}

int main(){
    int ordem, l, c;
    scanf("%d", &ordem);
    scanf("%d %d", &l, &c);

    int m[l][c];
    int vetor[l*c];

    for (int i = 0; i < l; i++){
        for (int j = 0; j < c; j++){
            scanf("%d", &m[i][j]);
        }
    }

    flatten(l, c, m, vetor, ordem);
} 