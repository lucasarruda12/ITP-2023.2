#include <stdio.h>

int calc_fuso(int s, int t, int f){
    int saida = s + t + f;
    if (saida == 24) {saida = 0;}
    if (saida > 24) {saida = saida - 24;}
    if (saida < 0) {saida = 24 + saida;}

    printf("Hora de saída: %d\n", s);
    printf("Hora de chegada: %d", saida);

    return 0;
}

int main(){
    int s, t, f;
    scanf("%d%d%d", &s, &t, &f);
    
    calc_fuso(s, t, f);
}