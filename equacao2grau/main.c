#include <stdio.h>
#include <math.h>

#define EPSILON 0.00001


double sqrt_newton_raphson(double x) {
    if (x < 0) {
        printf("Numero negativo nao tem raiz quadrada real.\n");
        return -1; // Indicando erro
    }

    // Caso especial para 0 e 1
    if (x == 0 || x == 1) return x;

    double guess = x; // Chute inicial
    double previous_guess;

    do {
        previous_guess = guess;
        guess = (guess + x / guess) / 2;
    } while (fabs(guess - previous_guess) >= EPSILON);

    return guess;
}


int main() {
    double delta;
    double resultado1,resultado2,a,b,c;

    printf("calcular equacao do 2 grau\n_________________________________");

    printf("\n\nDigite o valor A: ");
    scanf("%lf",&a);

    printf("\nDigite o valor B: ");
    scanf("%lf",&b);

    printf("\nDigite o valor C: ");
    scanf("%lf",&c);

    delta = (b*b) - (4 * a * c);

    if (a == 0) {
        printf("O coeficiente A nao pode ser zero.\n");
        return 1;
    }

    if (delta < 0) {
        printf("A equacao nao tem raizes reais.\n");
        return 1;
    }


    double raiz_delta = sqrt_newton_raphson(delta);



    resultado1 = (-b + raiz_delta) / (2 * a);
    resultado2 = (-b - raiz_delta) / (2 * a);


    printf("_________________________________\nO primeiro resultado soma: %lf",resultado1);
    printf("\nO segundo resultado subtracao : %lf",resultado2);


    return 0;
}