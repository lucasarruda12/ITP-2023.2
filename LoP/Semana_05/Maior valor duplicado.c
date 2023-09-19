#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int vetor[n];

    int mais_rep, n_rep;
    int n_rep_at;

    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }

    for(int i = 0; i < n; i++){
        n_rep_at = 0;

        for(int j = 0; i < n; i++){
            if(vetor[i] == vetor[j]){
                n_rep_at++;
            }
        }

        if(n_rep_at > n_rep){
            n_rep = n_rep_at;
            mais_rep = vetor[i];
        }
    }

    printf("%d", mais_rep);
}