/* 
 * File:   determinante.h
 * Author: Alan
 *
 * Created on 29 de Junho de 2021, 19:38
 */

#ifndef DETERMINANTE_H
#define DETERMINANTE_H

#ifdef __cplusplus
extern "C" {
#endif

    /*
     * /////////////////////////////////////////////////////////////////////////
     * EN: Compute the determinant of a matrix transforming it into an upper
     * triangular matrix. Theorems of Jacobi and Laplace are used to zero matrix
     * elements and later multiply the main diagonal to obtain the result. Also,
     * to zero each matrix element, the pivot is choosen to be the biggest value
     * in module of that row or column in order to minimize the float point
     * operation truncation error
     * 
     * PT: Calcula o determinante de uma matriz transformando-a em uma matriz
     * triangular superior. Os teoremas de Jacobi e Laplace são usados para
     * zerar os elementos da matriz e depois multiplicar a diagonal principal e
     * obter o resultado. Além disso, para zerar cada elemento da matriz, o pivô
     * é escolhido de forma a ser o maior valor em módulo daquela fila para
     * minimizar o erro de truncamento inerente das operações de ponto flutuante
     * /////////////////////////////////////////////////////////////////////////
     * 
     * return - EN: returns the value of the determinant
     *          PT: retorna o valor do determinante
     * 
     * mat - EN: matrix cast into a vector
     *       PT: matriz convertida em vetor
     * 
     * ord - EN: matrix order
     *       PT: ordem da matriz
     */
    double Determinante(double *mat, int ord);

#ifdef __cplusplus
}
#endif

#endif /* DETERMINANTE_H */