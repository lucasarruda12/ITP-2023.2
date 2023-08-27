#include <stdio.h>

int main(){
    int a, b;

    scanf("%d%d", &a, &b);

    if(a%b == 0){
        int quo = a/b;
        printf("Resultado: %d", quo);
    }

    return 0;
}