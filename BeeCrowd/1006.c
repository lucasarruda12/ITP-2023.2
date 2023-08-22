#include <stdio.h>

int main(){
    double a, b, c;

    scanf("%lf%lf%lf", &a, &b, &c);

    double MEDIA = (a*2+b*3+c*5)/10;

    printf("MEDIA = %.1lf\n", MEDIA);
    
    return 0;
}