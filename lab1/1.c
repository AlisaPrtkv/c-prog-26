#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv) {
    while (1) {
        double a, b, c;
        double x1, x2;
        double D;

        printf("Vvedite a, b, c: ");
        scanf("%lf %lf %lf", &a, &b, &c);

        if (a == 0) {
            printf("Eto lineynoe uravnenie\n");
            continue;
        }

        D = b * b - 4 * a * c;

        if (D > 0) {
            x1 = (-b + sqrt(D)) / (2 * a);
            x2 = (-b - sqrt(D)) / (2 * a);
            printf("%f, %f\n", x1, x2);
        } else if (fabs(D) < 1e-9) {
            double x0 = -b / (2 * a);
            printf("%f\n", x0);
        } else {
            printf("Korney net\n");
        }

        int repeat;
        printf("escho raz? da - 1, net - 0\n");
        scanf("%d", &repeat);
        if (!repeat) break;
    }
    return 0;
}