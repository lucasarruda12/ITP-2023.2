#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
    int n, m;

    scanf("%d ", &n);
    char prefixos[n][11];

    for (int i = 0; i < n; i++){
        fgets(prefixos[i], 10, stdin);
    }

    scanf("%d ", &m);
    char sufixos[m][11];

    for (int i = 0; i < m; i++){
        fgets(sufixos[i], 10, stdin);
    }
    
    char str[21] = {0};
    char input[21] = {0};
    char palavras[25][21] = {0};
    int counter = 0;

    while(true){
        fgets(input, 21, stdin);

        if((input[0] == '-') & (input[1] == '1')){
            break;
        }

        strcpy(palavras[counter], input);

        bool match = true;
        int tamStr = strlen(palavras[counter]);

        for (int i = 0; i < m; i++){
            int tamSufixo = strlen(sufixos[i]);
            match = true;

            for (int j = (tamSufixo - 2); j >= 0; j--){
                if(!(palavras[counter][tamStr - 2 - j] == sufixos[i][tamSufixo - 2 - j])){
                    match = false;
                }
            }

            if (match == true){
                palavras[counter][tamStr - tamSufixo] = '\n';
                palavras[counter][tamStr - tamSufixo + 1] = '\0';
            }
        }

        for (int i = 0; i < n; i++){
            bool match = true;
            int tamStr = strlen(palavras[counter]);

            int tamPrefixo = strlen(prefixos[i]);
            match = true;

            for (int j = 0; j <= tamPrefixo - 2; j++){
                if(!(palavras[counter][j] == prefixos[i][j])){
                    match = false;
                }
            }

            if (match == true){
                for (int a = 0; a < (tamStr - tamPrefixo); a++){
                    palavras[counter][a] = palavras[counter][a + tamPrefixo - 1];
                }

                palavras[counter][tamStr - tamPrefixo] = '\n';
                palavras[counter][tamStr - tamPrefixo + 1] = 0;
            }
        }

        counter++;
    }

    for (int i = 0; i < counter; i++){
        printf("%s", palavras[i]);
    }  
}