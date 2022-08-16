#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double varA,varB,varC,varD;

double f(double x) {
    return varA*pow(x,3)+varB*pow(x,2)+varC*x+varD;
}

double area(double limA, double limB) {
    double resLimA = f(limA);
    double h = f(limA);
    double b = fabs((limA-limB));
    return b*h;
}

double integral(double limA, double limB) {
    double b = fabs((limA-limB));
    double areaAnterior = -999999999;
    double areaAtual = -999999999;
    do { 
        areaAnterior = areaAtual;
        areaAtual = 0;
        for(double x = limA; x < limB; x+=b){
            areaAtual += area(x, x+b);
        }
        b /= 2;
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
    
    printf("\n%lf\n",integral(limA, limB));

    return 0;
}
