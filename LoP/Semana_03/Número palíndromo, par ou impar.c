#include <stdio.h>
#include <math.h>

int main(){
    int num, i, tam, pal = 1, prim, ult, par = 1, output;

    scanf("%d", &num);
    tam = (int)floor(log10((float)num)) + 1;    
    ult = num;
    output = num;

    if(num % 2 != 0){
        par = 0;
    }

    while(num/10 > 10){
        tam = (int)floor(log10((float)num)) + 1;

        // printf("num: %d!\n", num);

        prim = num%10;
        ult = num;

        while(ult >= 10){
            ult = ult/10;
            // printf("ult: %d\n", ult);
        }

        // printf("prim, ult: %d%d\n", prim, ult);

        if (prim != ult){
            pal = 0;
        }

        num = num%((int)pow(10, (tam-1)));

        // printf("%d\n", num);

        num = num/10;

        // printf("%d\n", num);
    }


    if(pal){
        if(par){
            printf("%d é Palíndromo e par.", output);
        } else {
            printf("%d é Palíndromo e impar.", output);
        }
    } else {
        if(par){
            printf("%d não é Palíndromo e par.", output);
        } else {
            printf("%d não é Palíndromo e impar.", output);
        }
    }
    
    return 0;
}