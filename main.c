/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Alan
 *
 * Created on 29 de Junho de 2021, 19:37
 */

#include <stdio.h>
#include <stdlib.h>

#include "determinante.h"

#define TAM 5

int main(int argc, char** argv) {
    double m[TAM][TAM];

    m[0][0] = -9;   m[0][1] = 4;    m[0][2] = -2;   m[0][3] = 8;    m[0][4] = -1;
    m[1][0] = 5;    m[1][1] = -3;   m[1][2] = -5;   m[1][3] = -9;   m[1][4] = -8;
    m[2][0] = -9;   m[2][1] = 2;    m[2][2] = 1;    m[2][3] = 9;    m[2][4] = 8;
    m[3][0] = 9;    m[3][1] = 1;    m[3][2] = 7;    m[3][3] = 6;    m[3][4] = 3;
    m[4][0] = -2;   m[4][1] = 4;    m[4][2] = -1;   m[4][3] = 4;    m[4][4] = -7;

    printf("matriz:\n");
    for (int j, i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%5g", m[i][j]);
        }
        printf("\n");
    }

    double det = Determinante((double*) m, TAM);

    printf("\ndet = %f\n", det);

    printf("matriz:\n");
    for (int j, i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%5g", m[i][j]);
        }
        printf("\n");
    }

    getchar();

    return (EXIT_SUCCESS);
}