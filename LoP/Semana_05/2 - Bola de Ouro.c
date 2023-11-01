#include <stdio.h>
#include <math.h>

int main(){
    int n;
    scanf("%d", &n);

    int total = 0;
    int media_soma = 0;
    float subtotal = 0;
    int bp = 0;

    int apostas[n][2];

    for (int i = 0; i < n; i++){
        scanf("%d", &apostas[i][0]);
        scanf("%d", &apostas[i][1]);

        total = total + apostas[i][0];
    }

    printf("Total: R$ %d\n", total);
    bp = total/10;
    total = total - total/10;

    int vencedor;
    scanf("%d", &vencedor);

    for (int i = 0; i < n; i++){
        if(apostas[i][1] == vencedor){
            media_soma = media_soma + apostas[i][0];
        }
    }

    for (int i = 0; i < n; i++){
        if(apostas[i][1] == vencedor){
            printf(
                "Apostador %d: R$ %.0f\n",
                i + 1,
                floor(((apostas[i][0] * 1.0)/media_soma) * total)
            );
        }
    }

    for (int i = 0; i < n; i++){
        if(apostas[i][1] == vencedor){
            subtotal = subtotal + floor(((apostas[i][0] * 1.0)/media_soma) * total);
        }
    }

    bp = bp + (total - subtotal);

    if(bp - (bp/10) == total){
        media_soma = 0;
        subtotal = 0;

        for (int i = 0; i < n; i++){
            media_soma = media_soma + apostas[i][0];
        }

        for (int i = 0; i < n; i++){
            printf(
                "Apostador %d: R$ %.0f\n",
                i + 1,
                floor(((apostas[i][0] * 1.0)/media_soma) * total)
            );
        }

        for (int i = 0; i < n; i++){
            subtotal = subtotal + floor(((apostas[i][0] * 1.0)/media_soma) * total);
        }

        bp = bp/10 + (total - subtotal);
    }

    printf("Bebidas e petiscos: R$ %d", bp);
}