#include <stdio.h>

int main(){
    int valor;

    scanf("%d", &valor);

    int cem, cinq, vinte, dez, cinco, dois;   

    printf("%d\n", valor);

    cem = valor/100;
    valor = valor%100;

    cinq = valor/50;
    valor = valor%50;

    vinte = valor/20;
    valor = valor%20;

    dez = valor/10;
    valor = valor%10;

    cinco = valor/5;
    valor = valor%5;

    dois = valor/2;
    valor = valor%2;

    printf("%d nota(s) de R$ 100,00\n", cem);
    printf("%d nota(s) de R$ 50,00\n", cinq);
    printf("%d nota(s) de R$ 20,00\n", vinte);
    printf("%d nota(s) de R$ 10,00\n", dez);
    printf("%d nota(s) de R$ 5,00\n", cinco);
    printf("%d nota(s) de R$ 2,00\n", dois);
    printf("%d nota(s) de R$ 1,00\n", valor);

    return 0;
}