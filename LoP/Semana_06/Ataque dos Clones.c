#include <stdio.h>
#include <stdbool.h>

int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    int jx, jy;
    scanf("%d%d", &jx, &jy);

    int cords[n][m];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &cords[i][j]);
        }
    }

    bool bomba = true;
    bool vivo = true;
    int ctd = 1;
    
    for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){ 
            bomba = true;

            if(x < n-1){
                if (cords[x][y] <= cords[x+1][y]){bomba= false;}
            }

            if(y < m-1){
                if (cords[x][y] <= cords[x][y+1]){bomba= false;}
            }

            if((x < n-1) && (y < m-1)){
                if (cords[x][y] <= cords[x+1][y+1]){bomba= false;}
            }

            if (x > 0){
                if (cords[x][y] <= cords[x-1][y]){bomba= false;}
            }

            if (y > 0){
                if (cords[x][y] <= cords[x][y-1]){bomba= false;}
            }

            if ((x > 0) && (y > 0)){
                if (cords[x][y] <= cords[x-1][y-1]){bomba= false;}
            }

            if ((x < n-1) && (y > 0)){
                if (cords[x][y] <= cords[x+1][y-1]){bomba= false;}
            }

            if ((x > 0) && (y < m-1)){
                if (cords[x][y] <= cords[x-1][y+1]){bomba= false;}
            }

            if(bomba) {
                printf("Local %d: %d %d\n", ctd, x+1, y+1);
                ctd++;

                if ((x + 1 == jx) && (y + 1 == jy)){
                    vivo = false;
                }
            }
        }
    }

    if (vivo){
        printf("Ao resgate!");
    } else {
        printf("Descanse na Força...");
    }
}