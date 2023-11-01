#include <stdio.h>

int main(){
    char letra;
    float pont;
    float pop;

    scanf("%c", &letra);
    scanf("%f", &pont);
    scanf("%f", &pop);

    float indice = pont * pop;
    
    printf("A popularidade de %c é %.1f", letra, indice);

    return 0;
}