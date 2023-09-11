#include <stdio.h>

int rcrs(int n){
    int maior = 0;

    while(n > 0){
        int a;
        scanf("%d", &a);

        if (a>maior){
            maior = a;
        }
        
        n--;
    }

    return maior;
}

int main(){
    int n;
    scanf("%d", &n);

    int vel = rcrs(n);

    if(vel < 10){
        printf("Level 1");
    }

    if((vel >= 10) & (vel < 20)){
        printf("Level 2");
    }
    
    if(vel >= 20){
        printf("Level 3");
    }
}