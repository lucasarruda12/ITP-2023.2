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
            printf("%d", sudoku[i][j]);
        }
        printf("\n");
    }
}

int check_possible_moves(int sudoku[9][9], int m, int n, int possible_moves[9]){
    int num_possible_moves = 9;

    for (int i = 0; i < 9; i++){
        if (sudoku[m][i] != 0 && possible_moves[sudoku[m][i]-1] == 0){
            possible_moves[sudoku[m][i]-1] = 1;
            num_possible_moves--;
        }

        if (sudoku[i][n] != 0 && possible_moves[sudoku[i][n]-1] == 0){
            possible_moves[sudoku[i][n]-1] = 1;
            num_possible_moves--;
        }
    }

    for (int i = (m/3)*3; i < (((m/3)+1)*3); i++){
        for (int j = (n/3)*3; j < (((n/3)+1)*3); j++){
            if (sudoku[i][j] != 0 && possible_moves[sudoku[i][j]-1] == 0){
                possible_moves[sudoku[i][j]-1] = 1;
                num_possible_moves--;
            }
        }
    }

    return num_possible_moves;
}

int change_to_single_possible_move(int sudoku[9][9], int m, int n, int possible_moves[9]){
    for (int i = 0; i < 9; i++){
        if(possible_moves[i] == 0){
            sudoku[m][n] = i+1;
            return 1;
        }
    }

    return 0;
}

int solve_sudoku(int sudoku[9][9]){
    // PARAR RECURSÃO QUANDO NÃO TIVER MAIS ESPAÇOS BRANCOS NO SUDOKU
    // SUDOKU RESOLVIDO
    int check_for_zeros = 0;

    for(int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (sudoku[i][j] == 0){
                check_for_zeros++;
            }
        }
    }

    if(check_for_zeros == 0){
        return 1;
    }

    // PARAR RECURSÃO QUANDO ALGUM DOS ESPAÇOS NÃO TIVER MAIS JOGADAS VÁLIDAS
    // NÃO TEM SOLUÇÃO
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            int possible_moves[9] = {0};
            if ((sudoku[i][j] == 0) && (check_possible_moves(sudoku, i, j, possible_moves) == 0)){
                return 0;
            }
        }
    }

    // REMOVER ---------
    print_board(sudoku);
    printf("\n");
    // REMOVER ---------

    // EM TODOS OS ESPAÇOS COM UMA ÚNICA OPÇÃO, COLOCAR A ÚNICA OPÇÃO
    int changes = -1;

    while (changes != 0){
        changes = 0;

        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if(sudoku[i][j] == 0){
                    int possible_moves[9] = {0};
                    if (check_possible_moves(sudoku, i, j, possible_moves) == 1){
                        changes++;
                        change_to_single_possible_move(sudoku, i, j, possible_moves);
                    }
                }
            }
        }
    }

    // QUANDO NÃO TIVEREM MAIS ESPAÇOS COM UMA ÚNICA OPÇÃO, TENTAR COLOCAR
    // ALGUM DOS NÚMEROS POSSÍVEIS NO PRIMEIRO ESPAÇO LIVRE

    for(int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (sudoku[i][j] == 0){
                int possible_moves[9] = {0};
                check_possible_moves(sudoku, i, j, possible_moves);

                for (int k = 0; k < 9; k++){
                    if (possible_moves[k] == 0) {
                        sudoku[i][j] = k + 1;
                        if (solve_sudoku(sudoku) == 1) {
                            return 1;
                        }
                        sudoku[i][j] = 0;
                    }
                }
            }
        }
    }
}

int main(){
    int sudoku[9][9];
    read_input(sudoku);

    if(solve_sudoku(sudoku) == 1){
        // print_board(sudoku);
    }
}