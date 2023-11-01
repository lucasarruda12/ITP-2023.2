#include <stdio.h>
#include <string.h>

int main(){
    int n;
    int m;
    scanf("%d", &n);

    float alunos[n][2];
    int qnt_aprvd = 0; 
    int qnt_rec = 0;
    int qnt_rep = 0;

    for (int i = 0; i < n; i++) {
        scanf("%f", &alunos[i][0]);
        scanf("%d", &m);
        scanf("%f", &alunos[i][1]);

        if (alunos[i][1] >= 7) {
            qnt_aprvd++;
        } else if (alunos[i][1] >= 5) {
            qnt_rec++;
        } else {
            qnt_rep++;
        }
    }

    float aprvd[qnt_aprvd], rec[qnt_rec], rep[qnt_rep];

    qnt_aprvd = 0; 
    qnt_rec = 0; 
    qnt_rep = 0;

    for (int i = 0; i < n; i++) {
        if (alunos[i][1] >= 7) {
            aprvd[qnt_aprvd] = alunos[i][0];
            qnt_aprvd++;
        } else if (alunos[i][1] >= 5) {
            rec[qnt_rec] = alunos[i][0];
            qnt_rec++;
        } else {
            rep[qnt_rep] = alunos[i][0];
            qnt_rep++;
        }
    }

    for (int i = 0; i < qnt_aprvd; i++){
        printf("%.f\n", aprvd[i]);
    }

    printf("Aprovados: ");

    for (int i = 0; i < qnt_aprvd; i++){
        printf("%.f ", aprvd[i]);
        printf("(%.1f)", alunos[(int)aprvd[i] - 1][1]);

        if (i + 1 != qnt_aprvd){
            printf(", ");
        }
    }

    printf("\n");

    printf("Recuperação: ");

    for (int i = 0; i < qnt_rec; i++){
        printf("%.f ", rec[i]);
        printf("(%.1f)", alunos[(int)rec[i] - 1][1]);

        if (i + 1 != qnt_rec){
            printf(", ");
        }
    }

    printf("\n");

    printf("Reprovados: ");

    for (int i = 0; i < qnt_rep; i++){
        printf("%.f ", rep[i]);
        printf("(%.1f)", alunos[(int)rep[i] - 1][1]);

        if (i + 1 != qnt_rep){
            printf(", ");
        }
    }

    printf("\n");
}