#include <stdio.h>

void compute_votes(int n, int votes[n], int *most_voted, int *second_most_voted){
    int votes_chapa[2][n];

    for (int i = 0; i < n; i++){
        votes_chapa[0][i] = i+1;
        votes_chapa[1][i] = 0;
    }
    
    for (int i = 0; i < n; i++){
        votes_chapa[1][votes[i] - 1]++;
    }

    int trocas = 1;

    while(trocas != 0){
        trocas = 0;

        for (int i = 0; i < n - 1; i++){
            if (votes_chapa[1][i] < votes_chapa[1][i+1]){
                int temp_chapa = votes_chapa[0][i];
                int temp_votes = votes_chapa[1][i];

                votes_chapa[0][i] = votes_chapa[0][i+1];
                votes_chapa[1][i] = votes_chapa[1][i+1];

                votes_chapa[0][i+1] = temp_chapa;
                votes_chapa[1][i+1] = temp_votes;

                trocas++;
            }
        }
    }

    *most_voted = votes_chapa[0][0];
    *second_most_voted = votes_chapa[0][1];
}

int main(){
    int n;
    scanf("%d", &n);

    int votes[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &votes[i]);
    }

    int most_voted = 0, second_most_votes = 0;

    compute_votes(n, votes, &most_voted, &second_most_votes);
    printf("%d %d", most_voted, second_most_votes);
}