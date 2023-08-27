#include <stdio.h>

int main(){
    int a, b, c, d;

    scanf("%d%d%d%d", &a, &b, &c, &d);

    int maior = a;

    if (b > maior){
        maior = b;
    }
    if(c > maior){
        maior = c;
    }
    if(d > maior){
        maior = d;
    }

    printf("Maior: %d", maior);
    

    return 0;
}