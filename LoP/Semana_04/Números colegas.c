#include <stdio.h>

int somaDivisores(int n){
    int counter = n-1;
    int divisores = 0;

    while(counter > 0){
        if(n % counter == 0){
            divisores = divisores + counter;
        }

        counter--;
    }

    return divisores;
}

int main(){
    int a, b;
    scanf("%d%d", &a, &b);

    if(((somaDivisores(a) == b) || 
    (somaDivisores(a) == b - 1) || 
    (somaDivisores(a) == b + 1) || 
    (somaDivisores(a) == b - 2) || 
    (somaDivisores(a) == b + 2)) 
    & 
    ((somaDivisores(b) == a) || 
    (somaDivisores(b) == a - 1) || 
    (somaDivisores(b) == a + 1) || 
    (somaDivisores(b) == a - 2) || 
    (somaDivisores(b) == a + 2))){
        printf("S");
        return 0;
    }

    printf("N");
}