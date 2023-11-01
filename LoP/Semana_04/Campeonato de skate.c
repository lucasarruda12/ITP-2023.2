#include <stdio.h>


int score(int a, int b, int c){
    if ((a == b) || (a == c)){
        return a;
    }

    if(b == c){
        return b;
    }

    if (((a > b) & (a < c) || (a < b) & (a > c))){
        return a;
    }

    if (((b > a) & (b < c) || (b < a) & (b > c))){
        return b;
    }

    if (((c > a) & (c < b) || (c < a) & (c > b))){
        return c;
    }
}

int main(){
    int a11, a12, a13;
    scanf("%d%d%d", &a11, &a12, &a13);
    int a1 = score(a11,a12,a13);

    int a21, a22, a23;
    scanf("%d%d%d", &a21, &a22, &a23);
    int a2 = score(a21,a22,a23);

    int a31, a32, a33;
    scanf("%d%d%d", &a31, &a32, &a33);
    int a3 = score(a31, a32, a33);

    int a = score(a1, a2, a3);

    int b11, b12, b13;
    scanf("%d%d%d", &b11, &b12, &b13);
    int b1 = score(b11,b12,b13);

    int b21, b22, b23;
    scanf("%d%d%d", &b21, &b22, &b23);
    int b2 = score(b21,b22,b23);

    int b31, b32, b33;
    scanf("%d%d%d", &b31, &b32, &b33);
    int b3 = score(b31, b32, b33);

    int b = score(b1, b2, b3);

    if(a>b){
        printf("A");
    }
    
    if(b>a){
        printf("B");
    }

    if(a==b){
        printf("empate");
    }
}