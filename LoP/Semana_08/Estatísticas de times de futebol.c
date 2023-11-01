#include <stdio.h>
#include <string.h>

typedef struct time
{
    char nome[21];
    int gm;
    int gs;
} Time;

void ordenar(Time times[], int n){
    Time ph;

    int trocas = -1;

    while (trocas != 0){
        trocas = 0;

        for (int i = 0; i < (n-1); i++){
            if (times[i].gm < times[i + 1].gm){
                strcpy(ph.nome, times[i].nome);
                ph.gm = times[i].gm;
                ph.gs = times[i].gs;

                strcpy(times[i].nome, times[i+1].nome);
                times[i].gm = times[i+1].gm;
                times[i].gs = times[i+1].gs;

                strcpy(times[i+1].nome, ph.nome);
                times[i+1].gm = ph.gm;
                times[i+1].gs = ph.gs;

                trocas++;
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    getchar();

    Time times[n];

    for(int i = 0; i < n; i++){
        fgets(times[i].nome, 20, stdin);
        scanf("%d %d", &times[i].gm, &times[i].gs);
        getchar();
    }

    ordenar(times, n);

    for(int i = 0; i < n; i++){
        printf("%d - %s", (i+1), times[i].nome);
        printf("Gols marcados: %d\n", times[i].gm);
        printf("Gols sofridos: %d\n", times[i].gs);
    }
}