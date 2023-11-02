#include <stdio.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

int can_move(int dir, int m, int n, char mapa[m][n], int pm, int pn){
    if(dir == UP){
        if(pm != 0 && mapa[pm-1][pn] != '*' && mapa[pm-1][pn] != 'M'){
            return 1;
        }
    }

    if(dir == DOWN){
        if(pm != m && mapa[pm+1][pn] != '*' && mapa[pm+1][pn] != 'M'){
            return 1;
        }
    }

    if(dir == LEFT){
        if(pn != 0 && mapa[pm][pn-1] != '*' && mapa[pm][pn-1] != 'M'){
            return 1;
        }
    }

    if(dir == RIGHT){
        if(pn != n && mapa[pm][pn+1] != '*' && mapa[pm][pn+1] != 'M'){
            return 1;
        }
    }

    return 0;
}

// void move(int dir, int m, int n, char *mapa, int px, int py){
//     if
// }

int main(){
    int m, n;
    int pm, pn;

    scanf("%d %d", &m, &n);

    char mapa[m][n];

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            scanf("%c", &mapa[i][j]);

            if(mapa[i][j] == 'C'){
                pm = i; 
                pn = j-1;
            }
        }

        getchar();
    }

    // for (int i = 0; i < m; i++){
    //     for (int j = 0; j < n; j++){
    //         printf("%c", mapa[i][j]); 
    //     }

    //     printf("\n");
    // }

    printf("player coords: %d, %d\n", pm, pn);

    printf("%d\n", can_move(UP, m, n, mapa, pm, pn));
    printf("%d\n", can_move(DOWN, m, n, mapa, pm, pn));
    printf("%d\n", can_move(LEFT, m, n, mapa, pm, pn));
    printf("%d\n", can_move(RIGHT, m, n, mapa, pm, pn));
}