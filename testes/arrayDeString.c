#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);

    char array[][11];
    array[0] = {'t', 'e', 's', 't', 'e', '\0'};

    for (int i = 0; i < n+1; i++){
        fgets(array[i], 10, stdin);
    }

    printf("%s", array[0]);
}