#include <stdio.h>
#include <math.h>

int main(){
    int input;
    float ma, mg, mh, err_g, err_h, err_m;

    ma = 0;
    mg = 1;
    mh = 0;

    for(int i =0 ; i <10; i++){
        scanf("%d", &input);
        ma = ma + input;
        mg = mg*input;
        mh = mh + (1.0/input);
    }

    ma = ma/10;
    mg = pow(mg, 1.0/10);
    mh = 10/mh;

    err_h = (mh - ma)*100/ma;
    err_g = (mg - ma)*100/ma;
    err_m = (err_h + err_g)/2;

    printf("Média aritmética é %.2f\n", ma);
    printf("Média harmônica é %.2f\n", mh);
    printf("Média geométrica é %.2f\n", mg);
    printf("Erro médio é %.2f %%", err_m);

    return 0;
}