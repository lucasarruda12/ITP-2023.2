#include <stdio.h>

int main(){
    int cod01, qnt01;
    float prc01;

    int cod02, qnt02;
    float prc02;

    scanf("%d%d%f", &cod01, &qnt01, &prc01);
    scanf("%d%d%f", &cod02, &qnt02, &prc02);

    float total = qnt01*prc01 + qnt02*prc02;

    printf("VALOR A PAGAR: R$ %.2lf\n", total);

    return 0;
}