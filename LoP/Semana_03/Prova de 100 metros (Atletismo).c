#include <stdio.h>
#include <math.h>

int main(){
    float input, raias = 0;
    float min;

    scanf("%f", &min);

    while(input != -1){
        scanf("%f", &input);

        if((input <= min) & (input != -1)){
            raias++;
        }
    }

    printf("%.f %.f", raias, ceil(raias/8.0));

    return 0;
}