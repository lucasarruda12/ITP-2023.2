#include <stdio.h>

int main(){
    int trilhas;

    scanf("%d", &trilhas);

    if((trilhas >= 0) && (trilhas < 5)){
        printf("Iniciante");
    } else if ((trilhas >= 5) && (trilhas < 20)) {
        int saude;
        scanf("%d", &saude);

        if (saude == 0){
            printf("Iniciante");
        } else {
            printf("Intermediário");
        }
    } else{
        int saude;
        scanf("%d", &saude);

        if (saude == 0){
            printf("Intermediário");
        } else {
            printf("Avançado");
        }
    }
    

    return 0;
}