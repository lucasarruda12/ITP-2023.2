#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[40];
    int idade;
    char sexo;
} Registro;

Registro criarRegistro(char nome[], int idade, char sexo){
    Registro registro;
    nome[strlen(nome) - 1] = 0; // PRA TIRAR O \n QUE VEM COM O FGETS
    
    strcpy(registro.nome, nome);
    registro.idade = idade;
    registro.sexo = sexo;

    return registro;
}

void inserirRegistro(Registro *registros, Registro registro, int index){
    strcpy(registros[index].nome, registro.nome);
    registros[index].idade = registro.idade;
    registros[index].sexo = registro.sexo;
}

void deletarRegistro(Registro *registros, Registro registro, int *qnt_registros){
    for (int i = 0; i < (*qnt_registros); i++){

        if (strcmp(registros[i].nome, registro.nome) == 0 &&
            registros[i].idade == registro.idade &&
            registros[i].sexo  == registro.sexo) {
            
            for (int j = i; j < (*qnt_registros) - 1; j++) {
                registros[j] = registros[j+1];
            }

            *qnt_registros = *qnt_registros - 1;
            break;
        }
    }
}

void imprimirRegistros(Registro *registros, int qnt_registros){
    for(int i = 0; i < qnt_registros; i++){
        printf("%s,%d,%c\n", registros[i].nome, registros[i].idade, registros[i].sexo);
    }
}

int main(){
    Registro *registros;
    int tam_array = 10;
    int qnt_registros = 0;
    registros = (Registro *)malloc(tam_array * sizeof(Registro));

    char op = ' ';
    char nome[40];
    int idade;
    char sexo;

    while(1){
        scanf("%c", &op);

        if(op == 'p'){
            imprimirRegistros(registros, qnt_registros);
            return 0;
        }
        getchar();
        fgets(nome, 39, stdin);
        scanf("%d %c", &idade, &sexo);
        getchar();

        Registro registro = criarRegistro(nome, idade, sexo);

        if (op == 'd') {deletarRegistro(registros, registro, &qnt_registros);}
        else {qnt_registros++;}
        
        if(tam_array == qnt_registros){
            tam_array = tam_array * 2;
            registros = realloc(registros, sizeof(Registro) * tam_array);
        }

        if (op == 'i') {inserirRegistro(registros, registro, (qnt_registros-1));}
    }
}