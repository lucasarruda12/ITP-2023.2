#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    if(n > 10){
        printf("Muitos elementos");
        return 0;
    }

    int a[n];

    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++){
        int input;
        scanf("%d", &input);

        a[i] = a[i] + input;
    }

    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}