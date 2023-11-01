#include <stdio.h>
#include <string.h>

typedef enum tipo_de_chocolates {
    BRANCO, AMARGO, AO_LEITE, COM_CASTANHAS
} tipoChocolates;

typedef struct chocolate{
    char nome[50];
    float peso;
    float valor;
    int tipo;
} Chocolate;

const char strBranco[10] = {'B', 'R', 'A', 'N', 'C', 'O', '\n', '\0'};
const char strAo_leite[10] = {'A', 'O', '_', 'L', 'E', 'I', 'T', 'E', '\n', '\0'};
const char strAmargo[10] = {'A', 'M', 'A', 'R', 'G', 'O', '\n', '\0'};
const char strCom_castanhas[20] = {'C', 'O', 'M', '_', 'C', 'A', 'S', 'T', 'A', 'N', 'H', 'A', 'S', '\n', '\0'};

int main(){
    int n;
    scanf("%d", &n);
    getchar();

    Chocolate chocolates[n];
    
    char tipoChocolateIn[20]= {0};

    int tb = 0, ta = 0, tao = 0, tc = 0, mais_caro_index = 0, mais_barato_index = 0;
    float mais_caro_valor, mais_barato_valor;

    for (int i = 0; i < n; i++){
        fgets(chocolates[i].nome, 50, stdin);
        scanf("%f%f", &chocolates[i].peso, &chocolates[i].valor);
        getchar();
        fgets(tipoChocolateIn, 20, stdin);

        // printf("b: %d\n", strcmp(tipoChocolateIn, strBranco));
        // printf("a: %d\n", strcmp(tipoChocolateIn, strAmargo));
        // printf("ao: %d\n", strcmp(tipoChocolateIn, strAo_leite));
        // printf("c: %d\n", strcmp(tipoChocolateIn, strCom_castanhas));

        
        if (strcmp(tipoChocolateIn, strBranco) == 0){
            chocolates[i].tipo = BRANCO;
        }

        else if (strcmp(tipoChocolateIn, strAmargo) == 0){
            chocolates[i].tipo = AMARGO;
        }

        else if (strcmp(tipoChocolateIn, strAo_leite) == 0){
            chocolates[i].tipo = AO_LEITE;
        }

        else if (strcmp(tipoChocolateIn, strCom_castanhas) == 0){
            chocolates[i].tipo = COM_CASTANHAS;
        }

        else {
            chocolates[i].tipo = -1;
        }
        
        mais_barato_valor = chocolates[0].valor;

        if (chocolates[i].tipo == BRANCO){
            tb++;
        }

        if (chocolates[i].tipo == AMARGO){
            ta++;
        }

        if (chocolates[i].tipo == AO_LEITE){
            tao++;
        }

        if (chocolates[i].tipo == COM_CASTANHAS){
            tc++;
        }

        if (chocolates[i].valor > mais_caro_valor){
            mais_caro_index = i;
            mais_caro_valor = chocolates[i].valor;
        }

        if(chocolates[i].valor < mais_barato_valor){
            mais_barato_index = i;
            mais_barato_valor = chocolates[i].valor;
        }
    }

    // if (chocolates[n - 1].tipo == BRANCO){
    //         tb++;
    // }

    // if (chocolates[n - 1].tipo == AMARGO){
    //     ta++;
    // }

    // if (chocolates[n - 1].tipo == AO_LEITE){
    //     tao++;
    // }

    // if (chocolates[n - 1].tipo == COM_CASTANHAS){
    //     tc++;
    // }

    printf("%d", chocolates[n-1].tipo);

    int tam_mc = strlen(chocolates[mais_caro_index].nome) - 1;
    int tam_mb = strlen(chocolates[mais_barato_index].nome) - 1;
    chocolates[mais_caro_index].nome[tam_mc] = 0;
    chocolates[mais_barato_index].nome[tam_mb] = 0;

    printf("Total de chocolates BRANCO: %d\n", tb);
    printf("Total de chocolates AMARGO: %d\n", ta);
    printf("Total de chocolates AO_LEITE: %d\n", tao);
    printf("Total de chocolates COM_CASTANHAS: %d\n", tc);
    printf("Chocolate mais caro: %s - R$%.2f\n", chocolates[mais_caro_index].nome, mais_caro_valor);
    printf("Chocolate mais barato: %s - R$%.2f", chocolates[mais_barato_index].nome, mais_barato_valor);
}