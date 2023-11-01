#include <stdio.h>

int main(){
    int lista[6];
    int legal = 1;

    for(int i = 0; i < 6; i++){
        scanf("%d", &lista[i]);
    }

    for(int i = 1; i < 6; i++){
        if((lista[i] - lista[i-1]) % 2 != 0){
            legal = 0;
        }
    }

    if(legal == 1){
        printf("Legal");
    } else {
        printf("Chato");
    }
}