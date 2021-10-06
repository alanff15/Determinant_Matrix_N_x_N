#include "determinante.h"

#define MOD(EXP) ( (EXP)<0?-(EXP):(EXP) )

double Determinante(double *mat, int n) {
    if (n < 1) {
        return 0;
    }

#if (ORDEM_MAX_MEM_ALOC == 0)
    //alocar memória do sistema linear
    double *m = (double*) malloc(n * n * sizeof (double));
#else
    double m[(ORDEM_MAX_MEM_ALOC * ORDEM_MAX_MEM_ALOC)];
#endif

    //copiar valores da matriz
    for (int i = 0; i < (n * n); i++) m[i] = mat[i];

    double multi = 1;
    double aux;
    /*construir triangulo de 0's abaixo da diagonal principal*/
    for (int l, k, i, j = 0; j < n; j++) //varrer matriz da esquerda pra direita
    {
        //ordenar linhas pela coluna j, crescente de cima pra baixo,
        //da diagonal princiapal até a ultima linha
        for (i = j; i < n; i++) //seleção direta
        {
            //apontar pra linha atual
            k = i;
            //comparar em módulo com valores das demais linhas, selecionar o menor deles
            for (l = i + 1; l < n; l++) {
                if (MOD(m[l * n + j]) < MOD(m[k * n + j])) {
                    k = l;
                }
            }
            //se o menor valor estiver enrte as demais linhas, trocar linhas
            if (k != i) {
                multi *= -1; //troca de filas inverte sinal do determinante
                for (l = 0; l < n; l++) {
                    aux = m[k * n + l];
                    m[k * n + l] = m[i * n + l];
                    m[i * n + l] = aux;
                }
            }
        }
        //rolar linhas para cima (shift), da ultima linha até a diagonal principal
        //até que o elemento da diagonal principal não seja 0
        for (k = 0; m[j * n + j] == 0 && k < n; k++) {
            //trocar linha 'i' com linha 'i+1'
            for (i = j; i < n - 1; i++) {
                multi *= -1; //troca de filas inverte sinal do determinante
                for (l = 0; l < n; l++) {
                    aux = m[i * n + l];
                    m[i * n + l] = m[(i + 1) * n + l];
                    m[(i + 1) * n + l] = aux;
                }
            }
        }
        //zerar elementos
        for (i = n - 1; i > j; i--) {
            if (m[i * n + j] != 0) {
                //elemento a ser zerado apontado por (i,j)
                //pivo
                aux = -m[i * n + j] / m[j * n + j];
                m[i * n + j] = 0;
                //somar a fila atual com o produto entre outra fila e uma constante
                //não altera o determinante (teorema de Jacobi)
                for (l = j + 1; l < n; l++) {
                    m[i * n + l] += m[j * n + l] * aux;
                }
            }
        }
    }
    /*calcular determinante multiplicando elementos da diagonal principal*/
    aux = m[0 * n + 0];
    for (int i = 1; i < n; i++) {
        aux *= m[i * n + i];
    }
    aux *= multi;

#if (ORDEM_MAX_MEM_ALOC == 0)
    //liberar memória do sistema linear
    free(m);
#endif
    return aux;
}