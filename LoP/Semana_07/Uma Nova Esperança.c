#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
    int chave_en;
    scanf("%d\n", &chave_en);

    if(chave_en > 9999){
        printf("Chave invalida!");
        return 0;
    }

    int chave[4];
    chave[0] = chave_en / 1000;
    chave[1] = (chave_en / 100) % 10;
    chave[2] = (chave_en / 10) % 10;
    chave[3] = chave_en % 10;

    char mensagem[201] = {0};
    fgets(mensagem, 200, stdin);

    const char s[40] = 
        {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
         'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
         'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
         'U', 'V', 'W', 'X', 'Y', 'Z', '.', ',', '?', ' '};
    
    int tam = strlen(mensagem);

    bool safe = false;

    for (int i = 0; i < tam-1; i++){
        safe = false;

        for (int j = 0; j < 40; j++){
            if (mensagem[i] == s[j]){
                safe = true;
            }
        }

        if (safe == false){
            printf("Caractere invalido na entrada!");
            return 0;
        }    
    }

    for (int i = 0; i < tam; i += 4){
        for (int j = 0; j < 4; j++){
            for (int k = 0; k < 40; k++){
                if (mensagem[i + j] == s[k]){
                    mensagem[i + j] = s[(k + chave[j]) % 40];
                    break;
                }
            }
        }
    }

    printf("%s", mensagem);
}