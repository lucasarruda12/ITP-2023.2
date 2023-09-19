#include <stdio.h>

int main(){
    int n = 0;

    scanf("%d", &n);

    int d[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &d[i]);
    }

    for(int i = 0; i < n; i++){
        int input;
        scanf("%d", &input);

        d[i] = d[i] + input;
    }

    for(int i = 0; i < n; i++){
        int input;
        scanf("%d", &input);

        d[i] = d[i] + input;
    }

    for(int i = 0; i < n; i++){
        printf("%d ", d[i]);
    }
}