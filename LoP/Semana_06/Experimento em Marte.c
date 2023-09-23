#include <stdio.h>

int main(){
    int n, m, v;
    scanf("%d%d%d", &n, &m, &v);

    int mapa[n][m];

    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
            scanf("%d", &mapa[x][y]);
            // printf("aqui!");
        }
    }

    int diff = 100;
    int mArea[2] = {0, 0};

    for (int x = 0; x < n-2; x++){
        for (int y = 0; y < m-2; y++){
            int soma = mapa[x][y] + mapa[x][y+1] + mapa[x][y+2] + 
                       mapa[x+1][y] + mapa[x+1][y+1] + mapa[x+1][y+2] +
                       mapa[x+2][y] + mapa[x+2][y+1] + mapa[x+2][y+2];

            if((soma - v) * (soma - v) < diff*diff){
                diff = soma - v;
                mArea[0] = x+1;
                mArea[1] = y+1;
            }
        }
    }

    if(diff<0){diff = -diff;}
    printf("A melhor area para exploracao eh %d %d com valor %d", mArea[0], mArea[1], diff);
}