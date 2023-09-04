#include <stdio.h>

int main(){
    int n, counter;
    float input, media;
    scanf("%d", &n);

    media = 0;
    counter = 0;

    while(n > 0){
        n--;

        scanf("%f", &input);
        if (input > -1){
            media = media + input;
            counter++;
        }
    }

    media = media/counter;
    if(counter!=0){printf("%.2f", media);}
    else{printf("A competicao nao possui dados historicos!");}

    return 0;
}