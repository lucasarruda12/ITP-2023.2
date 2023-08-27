#include <stdio.h>

int main(){
    int temp;
    char escala;

    scanf("%d", &temp);
    scanf(" %c", &escala);

    if(escala == 'C'){
        float temp_c, temp_f, temp_k;

        temp_c = temp;
        temp_f = temp*1.8 + 32;
        temp_k = temp + 273.15;

        printf("Celsius: %.2f\n", temp_c);
        printf("Farenheit: %.2f\n", temp_f);
        printf("Kelvin: %.2f\n", temp_k);  
    }
    if(escala == 'K'){
        float temp_c, temp_f, temp_k;

        temp_c = temp - 273.15;
        temp_f = ((temp - 273.15) * 1.8) + 32;
        temp_k = temp;

        printf("Celsius: %.2f\n", temp_c);
        printf("Farenheit: %.2f\n", temp_f);
        printf("Kelvin: %.2f\n", temp_k);  
    }
    if(escala == 'F'){
         float temp_c, temp_f, temp_k;

        temp_c = (temp - 32) / 1.8;
        temp_f = temp;
        temp_k = ((temp - 32) / 1.8) + 273.15;

        printf("Celsius: %.2f\n", temp_c);
        printf("Farenheit: %.2f\n", temp_f);
        printf("Kelvin: %.2f\n", temp_k);  
    }

    return 0;
}