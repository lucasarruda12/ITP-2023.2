#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const char s[40] = 
    {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
    'U', 'V', 'W', 'X', 'Y', 'Z', '.', ',', '?', ' '};

void decifrar_mensagem(char c[], char chave[]){
    int tamC = strlen(c);
    int cIndex;

    for (int i = 0; i < tamC - 4; i = i + 4){
        for (int k = 0; k < 4; k++){
            for (int j = 0; j < 40; j++){
                if(c[i + k] == s[j]){
                    cIndex = j;
                }
            }
            c[i + k] = s[(cIndex - chave[k] + 40) % 40];
        }
    }

    printf("%s", c);
}

void decifrar_chave(char c[], char kp[], char chave[]){
    bool match = true;
    int tamC = strlen(c);
    int tamKp = strlen(kp);
    int cIndex, kpIndex;
    int diff[8] = {0};

    for(int k = 0; k < tamC; k++){
        for (int i = 0; i < 8; i++){
            for (int j = 0; j < 40; j++){
                if(c[i + k] == s[j]){
                    cIndex = j;
                }

                if(kp[i] == s[j]){
                    kpIndex = j;
                }
            }
            diff[i] = (cIndex - kpIndex + 40) % 40;
        }

        if((diff[0] == diff[4]) & (diff[1] == diff[5]) & (diff[2] == diff[6]) & (diff[3] == diff[7])){
            for (int i = 0; i < 4; i++){
                chave[i] = diff[i + (k % 4)];
            }
            break;
        }
    }

    if (chave[0] == 0 & chave[1] == 0 & chave[2] == 0 & chave[3] == 0){
        printf("Mensagem nao e da Resistencia!");
        return;
    } 

    for (int i = 0; i < 4; i++){
        printf("%d", chave[i]);
    }

    printf("\n");

    decifrar_mensagem(c, chave);
}

int main(){
    char chave[4] = {0};
    char c[201] = {0};
    char kp[30] = {'Q', 'U', 'E', ' ', 'A', ' ', 'F', 'O', 'R', 'C', 'A', 'E', 'S', 'T', 'E', 'J', 'A', ' ', 'C', 'O', 'M', ' ', 'V', 'O', 'C', 'E', '\0'};

    fgets(c, 200, stdin);

    decifrar_chave(c, kp, chave);
}