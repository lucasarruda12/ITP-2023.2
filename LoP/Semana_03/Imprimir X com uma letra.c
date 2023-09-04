#include <stdio.h>

int main() {
    int num;    
    char letra;
    scanf("%d\n%c", &num, &letra);

    for (int i = 1; i < num; i++) {
        for (int j = 1; j < num; j++) {
            if (i == j || i + j == num) {
                printf("%c", letra);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}