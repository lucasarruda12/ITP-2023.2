#include <stdio.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

int get_oposite_move(int dir){
    if(dir % 2 == 0){return dir + 1;}
    if(dir % 2 == 1){return dir - 1;}
}

void print_map(int m, int n, char mapa[m][n]){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%c", mapa[i][j]); 
        }

        printf("\n");
    }
}

void find_possible_moves(int m, int n, char mapa[m][n], int pm, int pn, int *possible_moves){
    if(pm != 0 && mapa[pm-1][pn] != '*' && mapa[pm-1][pn] != 'M' && mapa[pm-1][pn] != ' ' && mapa[pm-1][pn] != 'C' ){
        possible_moves[0] = 1;
    }

    if(pm != m-1 && mapa[pm+1][pn] != '*' && mapa[pm+1][pn] != 'M' && mapa[pm+1][pn] != ' ' && mapa[pm+1][pn] != 'C' ){
        possible_moves[1] = 1;
    }

    if(pn != 0 && mapa[pm][pn-1] != '*' && mapa[pm][pn-1] != 'M' && mapa[pm][pn-1] != ' ' && mapa[pm][pn-1] != 'C' ){
        possible_moves[2] = 1;
    }

    if(pn != n-1 && mapa[pm][pn+1] != '*' && mapa[pm][pn+1] != 'M' && mapa[pm][pn+1] != ' ' && mapa[pm][pn+1] != 'C'){
        possible_moves[3] = 1;
    }
}

void move(int dir, int m, int n, char mapa[m][n], int pm, int pn, int *counter){
    if(dir == UP){
        if (mapa[pm-1][pn] == '.'){(*counter)++;}
        
        mapa[pm-1][pn] = ' ';
        pm = pm - 1;
    }

    else if(dir == DOWN){
        if (mapa[pm+1][pn] == '.'){(*counter)++;}

        mapa[pm+1][pn] = ' ';
        pm = pm + 1;
    }

    else if(dir == LEFT){
        if (mapa[pm][pn-1] == '.'){(*counter)++;}

        mapa[pm][pn-1] = ' ';
        pn = pn - 1;
    }

    else if(dir == RIGHT){
        if (mapa[pm][pn+1] == '.'){(*counter)++;}

        mapa[pm][pn+1] = ' ';
        pn = pn + 1;
    }

    int possible_moves[4] = {0};
    find_possible_moves(m, n, mapa, pm, pn, possible_moves);

    for (int i = 0; i < 4; i++){
        if ((possible_moves[i] == 1) && i != get_oposite_move(dir)){
            move(i, m, n, mapa, pm, pn, counter);
        }
    }
}

int main(){
    int m, n;
    int pm, pn;
    int possible_moves[4] = {0, 0, 0, 0};
    int counter = 0;

    scanf("%d %d", &m, &n);

    char mapa[m][n];

    for (int i = 0; i < m; i++){
        getchar();
        for (int j = 0; j < n; j++){
            scanf("%c", &mapa[i][j]);

            if(mapa[i][j] == 'C'){
                pm = i; 
                pn = j;
            }
        }
    }

    find_possible_moves(m, n, mapa, pm, pn, possible_moves);

    for (int i = 0; i < 4; i++){
        if (possible_moves[i] == 1){
            move(i, m, n, mapa, pm, pn, &counter);
        }
    }

    printf("Total de bolinhas devoradas: %d\n", counter);
    printf("Mapa final:\n");
    print_map(m, n, mapa);
}