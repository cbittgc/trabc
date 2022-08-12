#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double varA,varB,varC,varD;

double f(double x) {
    return varA*pow(x,3)+varB*pow(x,2)+varC*x+varD;
}

double area(double limA, double limB) {
    double resLimA = f(limA);
    double resLimB = f(limB);
    double h = resLimB - resLimA;
    double b = fabs((limA-limB));
    return b*h;
}

double integral(double limA, double limB) {
    double b = fabs((limA-limB));
    double areaAnterior = -1;
    double areaAtual;
    do {
        printf("rodou");
        areaAnterior = areaAtual;
        areaAtual = 0;
        for(double x = limA; x < limB; x+=b){
            areaAtual += area(x, x+b);
        }
        b /= 2;
        printf("aAt: %lf\naAn: %lf\nfabs: %lf\n",areaAtual,areaAnterior,fabs(areaAnterior - areaAtual));
    } while(fabs(areaAnterior - areaAtual) > 0.000001);
    
    return areaAtual;
}


int main() {
    double limA, limB;

    printf("Digite o valor de A: ");
    scanf("%lf", &varA);
    printf("Digite o valor de B: ");
    scanf("%lf", &varB);
    printf("Digite o valor de C: ");
    scanf("%lf", &varC);
    printf("Digite o valor de D: ");
    scanf("%lf", &varD);
    printf("Digite o valor de limite esquerdo: ");
    scanf("%lf", &limA);
    printf("Digite o valor de limite direito: ");
    scanf("%lf", &limB);
    
    printf("%lf",integral(limA, limB));

    return 0;
}
