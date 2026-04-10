#include <stdio.h>
#include <stdlib.h>
#include "mat.h"

void free_matrix(int** M, int n) {
    if (!M) return;
    for (int i = 0; i < n; i++) free(M[i]);
    free(M);
}

int** input_matrix(int n, const char* name) {
    printf("vvod mat %s (%d x %d):\n", name, n, n);
    int** M = (int**)malloc(n * sizeof(int*));
    if (!M) {
        printf("err vydel pamyat\n");
        return NULL;
    }
    
    for (int i = 0; i < n; i++) {
        M[i] = (int*)malloc(n * sizeof(int));
        if (!M[i]) {
            printf("err vydel pamyat\n");
            for (int j = 0; j < i; j++) free(M[j]);
            free(M);
            return NULL;
        }
        for (int j = 0; j < n; j++) {
            printf("%s[%d][%d] = ", name, i, j);
            scanf("%d", &M[i][j]);
        }
    }
    return M;
}

void print_matrix(int** M, int n, const char* title) {
    printf("\n%s:\n", title);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%8d ", M[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    char op;
    
    printf("vvod pazm mat n: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("ne tot razmer\n");
        return 1;
    }
    
    int** A = input_matrix(n, "A");
    if (!A) return 1;
    
    int** B = input_matrix(n, "B");
    if (!B) {
        free_matrix(A, n);
        return 1;
    }
    
    printf("vvod operac (+, -, *): ");
    scanf(" %c", &op);  

    int** C = matrix_calc(A, B, n, op);
    if (!C) {
        printf("err vydel pamyat for result\n");
        free_matrix(A, n);
        free_matrix(B, n);
        return 1;
    }
    
 
    print_matrix(A, n, "mat A");
    print_matrix(B, n, "mat B");
    
    switch (op) {
        case '+': print_matrix(C, n, "summ A + B"); break;
        case '-': print_matrix(C, n, "rasnost A - B"); break;
        case '*': print_matrix(C, n, "proisv A * B"); break;
        default: printf("noname operac\n");
    }
    
  
    free_matrix(A, n);
    free_matrix(B, n);
    free_matrix(C, n);
    
    return 0;
}
