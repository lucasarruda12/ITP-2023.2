#include <stdio.h>
#include <math.h>

int main(){
    double n = 3.14159;
    double r;

    scanf("%lf", &r);
    double area = pow(r, 2)*n;

    printf("A=%.4lf\n", area);

    return 0;
}