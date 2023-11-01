#include <stdio.h>

typedef struct Lanchonete
{
    int cod;
    char nome[30];
    float valor;
} Lanche;


int main(){
    int n;
    scanf("%d", &n);
    getchar();

    Lanche cardapio[n];

    for (int i = 0; i<n; i++){
        scanf("%d", &cardapio[i].cod);
        getchar();
        fgets(cardapio[i].nome, 30, stdin);
        scanf("%f", &cardapio[i].valor);
    }
    int codIn = 0;
    int qntdIn = 0;
    float total = 0;

    while (1){
        scanf("%d", &codIn);

        if (codIn == 0){
            break;
        }

        scanf("%d", &qntdIn);

        for (int i = 0; i < n; i++){
            if (codIn == cardapio[i].cod){
                total = total + (cardapio[i].valor * qntdIn);
            }
        }
    }

    printf("%.2f", total);
}