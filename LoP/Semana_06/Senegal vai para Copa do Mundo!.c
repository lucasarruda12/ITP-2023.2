#include <stdio.h>

int calcular_aposta(int largura, int altura, int bandeira[altura][largura], char cor){
    int aposta = (largura/3) * altura;
    int cmc = bandeira[0][0];

    if (cor == 'G'){
        aposta = aposta * (cmc + 1);
    }

    if (cor == 'Y'){
        aposta = aposta * (cmc + 2);
    }

    if (cor == 'R'){
        aposta = aposta * (cmc + 3) - 12;
    }

    return aposta;
}

int main(){
    int larg, cmc;
    char cor;

    scanf("%d%d %c", &larg, &cmc, &cor);

    int alt = larg * 0.75;
    int bandeira[alt][larg];

    bandeira[0][0] = cmc;

    int aposta = calcular_aposta(larg, alt, bandeira, cor);

    printf("%d", aposta);
}