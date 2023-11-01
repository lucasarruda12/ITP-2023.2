#include <stdio.h>

int main(){
    int num, hrs;
    double sal;

    scanf("%d%d%lf", &num, &hrs, &sal);

    sal = sal * hrs;

    printf("NUMBER = %d\n", num);
    printf("SALARY = U$ %.2lf\n", sal);    

    return 0;
}