#include <stdio.h>

int main(){
    char nome[10];
    double salario, vendas;
    
    scanf("%s%lf%lf", &nome, &salario, &vendas);

    salario = salario + vendas*0.15;
    
    printf("TOTAL = R$ %.2lf\n", salario);

    return 0;
}