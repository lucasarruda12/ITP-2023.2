#include <stdio.h>

int main(){
    int input;

    scanf("%d", &input);

    if(input <= 0){
        printf("Você entrou com %d, tente de novo na próxima", input);
        return 0;
    }

    int colunas = 0;
    int linhas = 1;
    int counter = 1;

    for (int i = 1; i <= input; i++){

        while(colunas < linhas){
            printf("%2d ", counter);
            counter++;
            colunas++;
        }

        printf("\n");
        colunas = 0;
        linhas++;
    }
}