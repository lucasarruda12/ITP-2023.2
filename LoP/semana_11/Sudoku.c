#include <stdio.h>
#include <stdbool.h>

void read_input(int sudoku[9][9]){
    char input;

    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            scanf("%c", &input);

            if (input == '*'){
                sudoku[i][j] = 0;
            } else {
                sudoku[i][j] = input - '0';
            }
        }

        getchar();
    }
}

void print_board(int sudoku[9][9]){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            printf("%d", sudoku[i][j]);
        }

        printf("\n");
    }
}

bool is_valid_3by3(int matriz[3][3]){
    for (int i = 0; i < 9; i++){
        for (int j = i+1; j < 9; j++){
            if (matriz[i/3][i % 3] != 0 && matriz[i/3][i % 3] == matriz[j/3][j % 3]){
                return false;
            }
        }
    }

    return true;
}

bool is_valid_sudoku(int sudoku[9][9]){
    for(int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            for (int k = j+1; k < 9; k++){
                if (sudoku[i][j] == sudoku[i][k] && sudoku[i][j] != 0){
                    return false;
                }
                
                if (sudoku[j][i] == sudoku[k][i] && sudoku[j][i] != 0){
                    return false;
                }
            }
        }
    }

    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            int matriz[3][3] = {0};

            for (int x = 0; x < 3; x++){
                for (int y = 0; y < 3; y++){
                    matriz[x][y] = sudoku[x + (3*i)][y + (3*j)];
                }
            }

            if (!is_valid_3by3(matriz)){
                return false;
            }
        }
    }

    return true;
}

bool solve_sudoku(int sudoku[9][9]){
    if (!is_valid_sudoku(sudoku)){
        return false;
    }

    for(int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (sudoku[i][j] == 0){
                for (int k = 1; k <= 9; k++){
                    sudoku[i][j] = k;
                    if(is_valid_sudoku(sudoku) && solve_sudoku(sudoku)){
                        return true;
                    } else {
                        sudoku[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
}

int main(){
    int sudoku[9][9];

    read_input(sudoku);
    if (solve_sudoku(sudoku)){
        print_board(sudoku);
    } else{
        printf("Não tem solução!");
    }
}