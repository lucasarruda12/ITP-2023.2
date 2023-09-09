#include <stdio.h>

double fib(int n){
    double t0 = 1;
    double t1 = 1;
    double ts = 1;

    while(n > 0){
        n--;

        ts = t0 + t1;
        t0 = t1;
        t1 = ts;
    }

    return ts;
}

int main(){
    int num;
    scanf("%d", &num);

    printf("%.f", fib(num - 2));
}