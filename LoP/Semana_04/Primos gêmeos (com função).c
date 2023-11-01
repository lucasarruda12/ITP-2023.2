#include <stdio.h>

int e_primo(int num){
    if ((num == 1) || (num == 0)){
        return 0;
    }

    int counter = num - 1;
    while(counter > 1){
        if (num % counter == 0){
            return 0;
        }

        counter--; 
    }

    return 1;
}

int main(){
    int num;
    scanf("%d", &num);

    if(!e_primo(num)){
        printf("Numero nao forma par de gemeos");
        return 0;
    }

    if((!e_primo(num + 2)) & (!e_primo(num - 2))){
        printf("Numero nao forma par de gemeos");
        return 0;
    }

    printf("Numero forma par de gemeos");
}