#include <stdio.h>

int main() {
    double kek[3][3];
    int i;
    int j;
    double sum1 = 0;
    double sum2 = 0;

    printf("Enter the values for a 3x3 matrix: \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%lf", &kek[i][j]);
        }
    }
    for (int i = 0; i < 3; i++) {
        sum1 += kek[i][i];
        sum2 += kek[i][2 - i];
    }
    printf("%.2lf \n", sum1);
    printf("%.2lf \n", sum2);

    double array[2][2];
    double sqr[2][2];

    printf("Enter the values for a 2x2 matrix: \n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%lf", &array[i][j]);
        }
    }

    sqr[0][0] = array[0][0] * array[0][0] + array[0][1] * array[1][0];
    sqr[0][1] = array[0][0] * array[0][1] + array[0][1] * array[1][1];
    sqr[1][0] = array[1][0] * array[0][0] + array[1][1] * array[1][0];
    sqr[1][1] = array[1][0] * array[0][1] + array[1][1] * array[1][1];

    printf("2x2 matrix squared: \n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%.2lf", sqr[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}