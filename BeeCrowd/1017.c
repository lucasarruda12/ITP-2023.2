#include <stdio.h>

int main(){
    int time, speed;

    scanf("%d%d", &time, &speed);

    int distance = time * speed;
    float liters = distance / 12.0;

    printf("%.3f\n", liters);

    return 0;
}