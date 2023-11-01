#include <stdio.h>
#include <string.h>

typedef struct party
{
    int id;
    char name[20];
    int votes;
} Party;

void compute_votes
(
    int num_votes, int votes[num_votes], 
    int num_parties, Party parties[num_parties], 
    Party *most_voted, Party *second_most_voted
){
    for (int i = 0; i < num_votes; i++){
        for (int j = 0; j < num_parties; j++){
            if(votes[i] == parties[j].id){
                parties[j].votes++;
            }
        }
    }

    int trocas = 1;

    while(trocas != 0){
        trocas = 0;

        for (int i = 0; i < num_parties - 1; i++){
            if (parties[i].votes < parties[i+1].votes){
                int temp_id = parties[i].id;
                char temp_name[20]; strcpy(temp_name, parties[i].name);
                int temp_votes = parties[i].votes;

                parties[i].id = parties[i+1].id;
                strcpy(parties[i].name, parties[i+1].name);
                parties[i].votes = parties[i+1].votes;

                parties[i+1].id = temp_id;
                strcpy(parties[i+1].name, temp_name);
                parties[i+1].votes = temp_votes;

                trocas++;
            }
        }
    }

    most_voted->id = parties[0].id;
    strcpy(most_voted->name, parties[0].name);
    most_voted->votes = parties[0].votes;

    second_most_voted->id = parties[0].id;
    strcpy(second_most_voted->name, parties[1].name);
    second_most_voted->votes = parties[1].votes;
}

int main(){
    int num_parties, num_votes;
    scanf("%d", &num_parties);

    Party parties[num_parties];
    
    for (int i = 0; i < num_parties; i++){
        scanf("%d ", &parties[i].id);
        fgets(parties[i].name, 20, stdin);
        parties[i].name[strlen(parties[i].name) - 1] = 0;
        parties[i].votes = 0;
    }

    scanf("%d", &num_votes);

    int votes[num_votes];

    for (int i = 0; i < num_votes; i++){
        scanf("%d", &votes[i]);
    }

    Party most_voted;
    Party second_most_voted;

    compute_votes(num_votes, votes, num_parties, parties, &most_voted, &second_most_voted);

    float votos_validos = 0;
    for(int i = 0; i < num_parties; i++){
        votos_validos = votos_validos + parties[i].votes;
    }

    printf("VENCEDOR: %s (%d votos = %.2f%)\n", most_voted.name, most_voted.votes, ((most_voted.votes * 100) / votos_validos));
    printf("VICE: %s (%d votos = %.2f%)\n", second_most_voted.name, second_most_voted.votes, ((second_most_voted.votes * 100) / votos_validos));
}