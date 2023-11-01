#include <stdio.h>

int main(){
    int b[3], c[3], d[3];

    for (int i = 0; i < 3; i++){
        int input;
        scanf("%d", &input);

        b[i] = input;
    }

    for (int i = 0; i < 3; i++){
        int input;
        scanf("%d", &input);

        b[i] = b[i] + input;
    }

    for (int i = 0; i < 3; i++){
        int input;
        scanf("%d", &input);

        b[i] = b[i] - (5*input);
    }
    printf("A = [%d,%d,%d]", b[0], b[1], b[2]);
}   