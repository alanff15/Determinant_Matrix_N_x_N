/* 
 * File:   main.c
 * Author: Alan
 *
 * Created on 29 de Junho de 2021, 19:37
 */

#include <stdio.h>
#include <stdlib.h>

#include "determinante.h"

#define ORD 5

void printMat(double *mat, int ord) {
    for (int j, i = 0; i < ord; i++) {
        for (j = 0; j < ord; j++) {
            printf("%10.6g", mat[j + i * ord]);
        }
        printf("\n");
    }
}

int main(int argc, char** argv) {
    double det, m[ORD][ORD];

    //matriz
    m[0][0] = -9;   m[0][1] = 4;    m[0][2] = -2;   m[0][3] = 8;    m[0][4] = -1;
    m[1][0] = 5;    m[1][1] = -3;   m[1][2] = -5;   m[1][3] = -9;   m[1][4] = -8;
    m[2][0] = -9;   m[2][1] = 2;    m[2][2] = 1;    m[2][3] = 9;    m[2][4] = 8;
    m[3][0] = 9;    m[3][1] = 1;    m[3][2] = 7;    m[3][3] = 6;    m[3][4] = 3;
    m[4][0] = -2;   m[4][1] = 4;    m[4][2] = -1;   m[4][3] = 4;    m[4][4] = -7;

    //original
    printf("original:\n");
    printMat((double*) m, ORD);

    //determinante
    det = Determinante((double*) m, ORD);
    printf("\n");
    printf("det = %f\n", det);

    //triangular
    printf("\n");
    printf("triangular:\n");
    printMat((double*) m, ORD);

    //final
    getchar();
    return (EXIT_SUCCESS);
}