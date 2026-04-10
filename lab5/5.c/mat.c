#include <stdlib.h>
#include "mat.h"

int** matrix_calc(int** A, int** B, int n, char op) {
    int** C = (int**)malloc(n * sizeof(int*));
    if (!C) return NULL;
    
    for (int i = 0; i < n; i++) {
        C[i] = (int*)malloc(n * sizeof(int));
        if (!C[i]) {
            for (int j = 0; j < i; j++) free(C[j]);
            free(C);
            return NULL;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            switch (op) {
                case '+':
                    C[i][j] = A[i][j] + B[i][j];
                    break;
                case '-':
                    C[i][j] = A[i][j] - B[i][j];
                    break;
                case '*':
                    C[i][j] = 0;
                    for (int k = 0; k < n; k++) {
                        C[i][j] += A[i][k] * B[k][j];
                    }
                    break;
                default:
                    C[i][j] = 0;
            }
        }
    }
    return C;
}