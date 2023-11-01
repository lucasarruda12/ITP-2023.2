#include <stdio.h>
#include <stdbool.h>

int main(){
    int tam;
    scanf("%d", &tam);

    int v[tam];

    int counter = 0;
    int input;
    bool e_unico = true;
    for(int i = 0; i < tam; i++){
        e_unico = true;

        scanf("%d", &input);

        for (int j = 0; j < counter; j++){
            if (input == v[j]){
                e_unico = false;
            }
        }

        if (e_unico == true){
            v[counter] = input;
            counter++;
        }
    }

    int ph;
    int trocas = 1;
    while(trocas > 0){        
        trocas = 0;

        for (int i = 0; i < counter - 1; i++){
            if(v[i] > v[i + 1]){
                ph = v[i];
                v[i] = v[i + 1];
                v[i + 1] = ph;
                trocas++;
            }
        }
    }

    for (int j = 0; j < counter; j++){
        printf("%d ", v[j]);
    }
}
