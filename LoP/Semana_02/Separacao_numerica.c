#include <stdio.h>

int main(){
    int num;

    scanf("%d", &num);

    if(num >= 10000){
        int alg = num/10000;

        printf("%d\n", alg);
    }
    if(num >= 1000){
        num = num%10000;
        int alg = num/1000;

        printf("%d\n", alg);
    }
    if(num >= 100){
        num = num%1000;
        int alg = num/100;

        printf("%d\n", alg);
    }
    if(num >= 10){
        num = num%100;
        int alg = num/10;

        printf("%d\n", alg);
    }
    int alg = num%10;
    printf("%d", alg);
}