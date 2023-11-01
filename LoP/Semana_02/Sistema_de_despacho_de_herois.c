#include <stdio.h>
#include <math.h>

int main(){
    int qnt, classe, total, ameaca;

    scanf("%d%d%d", &qnt, &classe, &ameaca);

    if((ameaca == 5) && (classe < 5)){
        printf("Melhor chamar Saitama!");
        return 0;
    } else if ((classe == 5) && (qnt > 0)) {
        printf("Heróis vencerão!");
        return 0;
    }

    ameaca = pow(3, ameaca);
    classe = pow(3, classe - 1);

    total = classe * qnt;

    if(total >= ameaca){
        printf("Heróis vencerão!");
    } else {
        printf("Melhor chamar Saitama!");
    }

    return 0;
}