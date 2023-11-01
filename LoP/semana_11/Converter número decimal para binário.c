#include <stdio.h>
#include <string.h>

char *decimalParaBinario(char binario[], int decimal){
    if (decimal == 0){
        binario[0] = '0';
        return binario;
    } else if (decimal == 1) {
        binario[0] = '1';
        return binario;
    } else {
        char digito = (decimal % 2) + '0';
        char string[2] = {digito, '\0'};
        strcat(decimalParaBinario(binario, (decimal/2)), string);
    }
}

int main(){
    int n;
    char binario[64] = {0};
    scanf("%d", &n);

    decimalParaBinario(binario, n);

    printf("%s\n", binario);
}