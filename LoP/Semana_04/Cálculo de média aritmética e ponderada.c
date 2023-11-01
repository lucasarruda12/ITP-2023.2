#include <stdio.h>

float calculaMedia(char tipo, float n1, float n2, float n3){
    if(tipo == 'A'){
        return (n1+n2+n3)/3;
    }

    if (tipo == 'P'){
        return (n1*4 + n2*5 + n3*6)/15;
    }
}

int main(){
    char tipo;
    float n1, n2, n3;

    scanf("%c", &tipo);
    scanf("%f%f%f", &n1, &n2, &n3);

    printf("Média %.2f", calculaMedia(tipo, n1, n2, n3));

    return 0;
}