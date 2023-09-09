#include <stdio.h>

int main(){
    float input = 0;
    float qnt_und = 0;
    float val_und = 0;
    float qnt_total = 0;
    float val_total = 0;

    while(1){
        scanf("%f", &input);
        qnt_und = input;

        if(input == -1){
            break;
        }

        scanf("%f", &input);
        val_und = input;

        if(input == -1){
            break;
        }

        qnt_total = qnt_total + qnt_und;
        val_total = val_total + val_und*qnt_und;
    }
    
    printf("%.f %.2f", qnt_total, val_total);

    return 0;
}