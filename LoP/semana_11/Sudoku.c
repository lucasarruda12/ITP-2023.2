#include <stdio.h>

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
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int sudoku[9][9];

    read_input(sudoku);
    print_board(sudoku);    
}