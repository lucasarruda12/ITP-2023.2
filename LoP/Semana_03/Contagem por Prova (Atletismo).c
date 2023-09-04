#include <stdio.h>

int main(){
    int equipes;
    char mod;
    int salto = 0, corr = 0, lanc = 0;
    
    scanf("%d", &equipes);
    
    for(equipes; equipes > 0; equipes--){
        mod = ' ';

        while(mod != 'F'){
            scanf("%c", &mod);

            
            if(mod == 'S'){
                salto++;
            }
            if(mod == 'L'){
                lanc++;
            }
            if(mod == 'C'){
                corr++;
            }
        }
    }

    int sum = salto + corr + lanc;

    printf("%d %d %d %d", corr, salto, lanc, sum);

    return 0;
}