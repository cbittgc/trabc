#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f(double varA, double varB, double varC, double varD, double x) {
    return varA*pow(x,3)+varB*pow(x,2)+varC*x+varD;
}


int main() {
    double varA,varB,varC,varD;
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
    
    double resLimA = f(varA, varB, varC, varD, limA);
    double resLimB = f(varA, varB, varC, varD, limB);
    double b = resLimB - resLimA;
    double h = abs((limA-limB));
    double areaN = b*h;
    printf("area: %lf\n",areaN);
    h = h/2;
    resLimA = f(varA, varB, varC, varD, limA);
    resLimB = f(varA, varB, varC, varD, h);
    double areaN1 = b*h;
    
    printf("area: %lf\n",areaN1);
    
    while(areaN-areaN1 > 0.000001) {
        areaN = areaN1;
        h = h/2;
        resLimA = f(varA, varB, varC, varD, limA);
        resLimB = f(varA, varB, varC, varD, h);
        areaN1 = b*h;
        printf("area: %lf\n",areaN1);
  
    }

    printf("A area do trapézio é: %lf\n", areaN1);

    return 0;
}
