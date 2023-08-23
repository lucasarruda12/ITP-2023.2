#include <stdio.h>

int main(){
    float A, B, C;
    double pi = 3.14159;
    scanf("%f%f%f", &A, &B, &C);

    float TRIANGULO = (A*C)/2;
    float CIRCULO = (pi * C * C);
    float TRAPEZIO = ((A+B)*C)/2;
    float QUADRADO = (B*B);
    float RETANGULO = (A*B);

    printf("TRIANGULO: %.3f\n", TRIANGULO);
    printf("CIRCULO: %.3f\n", CIRCULO);
    printf("TRAPEZIO: %.3f\n", TRAPEZIO);
    printf("QUADRADO: %.3f\n", QUADRADO);
    printf("RETANGULO: %.3f\n", RETANGULO);
    
    return 0;
}