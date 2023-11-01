#include <stdio.h>

int get_range(int n, int cells[n], int distance, int user, int *left_index, int *right_index){
    for (int i = 0; i < n; i++){
        if ((cells[i] >= user & cells[i] - distance <= user) || (cells[i] <= user && cells[i] + distance >= user)){
            if (*left_index == -1){
                *left_index = i;
            }

            *right_index = i;
        }
    }
}

int main(){
    int n, d, u, right_index, left_index = -1;
    scanf("%d %d %d", &n, &d, &u);

    int cells[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &cells[i]);
    }

    get_range(n, cells, d, u, &left_index, &right_index);

    if (left_index == -1){
        printf("USUARIO DESCONECTADO");
        return 1;
    }

    for (int i = left_index; i <= right_index; i++){
        printf("%d ", cells[i]);
    }
}