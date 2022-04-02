#include "determinante.h"

#define MOD(EXP) ( (EXP)<0?-(EXP):(EXP) )

double Determinante(double *mat, int ord) {
    if (ord < 1) {
        return 0;
    }

    double multi = 1;
    double aux;
    /*construir triangulo de 0's abaixo da diagonal principal*/
    for (int l, k, i, j = 0; j < ord; j++) //varrer matriz da esquerda pra direita
    {
        //ordenar linhas pela coluna j, crescente de cima pra baixo,
        //da diagonal princiapal até a ultima linha
        for (i = j; i < ord; i++) //seleção direta
        {
            //apontar pra linha atual
            k = i;
            //comparar em módulo com valores das demais linhas, selecionar o menor deles
            for (l = i + 1; l < ord; l++) {
                if (MOD(mat[l * ord + j]) < MOD(mat[k * ord + j])) {
                    k = l;
                }
            }
            //se o menor valor estiver enrte as demais linhas, trocar linhas
            if (k != i) {
                multi *= -1; //troca de filas inverte sinal do determinante
                for (l = 0; l < ord; l++) {
                    aux = mat[k * ord + l];
                    mat[k * ord + l] = mat[i * ord + l];
                    mat[i * ord + l] = aux;
                }
            }
        }
        //rolar linhas para cima (shift), da ultima linha até a diagonal principal
        //até que o elemento da diagonal principal não seja 0
        for (k = 0; mat[j * ord + j] == 0 && k < ord; k++) {
            //trocar linha 'i' com linha 'i+1'
            for (i = j; i < ord - 1; i++) {
                multi *= -1; //troca de filas inverte sinal do determinante
                for (l = 0; l < ord; l++) {
                    aux = mat[i * ord + l];
                    mat[i * ord + l] = mat[(i + 1) * ord + l];
                    mat[(i + 1) * ord + l] = aux;
                }
            }
        }
        //zerar elementos
        for (i = ord - 1; i > j; i--) {
            if (mat[i * ord + j] != 0) {
                //elemento a ser zerado apontado por (i,j)
                //pivo
                aux = -mat[i * ord + j] / mat[j * ord + j];
                mat[i * ord + j] = 0;
                //somar a fila atual com o produto entre outra fila e uma constante
                //não altera o determinante (teorema de Jacobi)
                for (l = j + 1; l < ord; l++) {
                    mat[i * ord + l] += mat[j * ord + l] * aux;
                }
            }
        }
    }
    /*calcular determinante multiplicando elementos da diagonal principal*/
    aux = mat[0 * ord + 0];
    for (int i = 1; i < ord; i++) {
        aux *= mat[i * ord + i];
    }
    aux *= multi;

    return aux;
}