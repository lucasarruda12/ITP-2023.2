#include <stdio.h>

int main(){
    int combo, custo, pago;

    scanf("%d%d", &combo, &pago);

    switch (combo)
    {
    case 1:
        custo = 12;
        break;
    case 2:
        custo = 23;
        break;
    case 3:
        custo = 31;
        break;
    case 4:
        custo = 28;
        break;
    case 5:
        custo = 15;
        break;
    }

    if(pago > custo){
        printf("Troco = %d reais", pago - custo);
    } else if (pago == custo){
        printf("Deu certim!");
    } else if (pago < custo){
        printf("Saldo insuficiente! Falta %d reais", custo - pago);
    }

    return 0;
}