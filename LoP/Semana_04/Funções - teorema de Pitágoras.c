#include <stdio.h>

int e_privitiva(int a, int b, int c){
    int ph;
    if(a > b) {ph = a; a = b; b = ph;}
    if(b > c) {ph = b; b = c; c = ph;}
    if(a > b) {ph = a; a = b; b = ph;}

    int counter = a;
    while(counter > 1){
        if((a % counter == 0) & (b % counter == 0 ) & (c %counter == 0)){
            return 0;
        }

        counter--;
    }

    return 1;
}

int e_trinaPitagorica(int a, int b, int c){
    int ph;
    if(a > b) {ph = a; a = b; b = ph;}
    if(b > c) {ph = b; b = c; c = ph;}
    if(a > b) {ph = a; a = b; b = ph;}

    if(c*c == b*b + a*a){
        return 1;
    }

    return 0;
}

int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    if(e_trinaPitagorica(a, b, c) & e_privitiva(a, b, c)){
        printf("tripla pitagorica primitiva");
        return 0;
    }

    if(e_trinaPitagorica(a, b, c)){
        printf("tripla pitagorica");
        return 0;
    }

    printf("tripla");
}