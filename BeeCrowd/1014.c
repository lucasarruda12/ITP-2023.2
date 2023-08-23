#include <stdio.h>

int main(){
    int x;
    float y;

    scanf("%d%f", &x, &y);

    float distancia = x/y;
    printf("%.3f km/l\n", distancia);

    return 0;
}