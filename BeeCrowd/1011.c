#include <stdio.h>
#include <math.h>

int main(){
    double R;
    double pi = 3.14159;
    scanf("%lf", &R);

    double volume = pow(R, 3)*pi*(4.0/3);

    printf("VOLUME = %.3lf\n", volume);

    return 0;
}