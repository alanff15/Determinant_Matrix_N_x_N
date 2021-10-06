/* 
 * File:   determinante.h
 * Author: Alan
 *
 * Created on 29 de Junho de 2021, 19:38
 */

#ifndef DETERMINANTE_H
#define DETERMINANTE_H

#include <stdlib.h>

//ordem máxima da matriz
//defina como 0 para alocação dinâmica de memória
#define ORDEM_MAX_MEM_ALOC 0

#ifdef __cplusplus
extern "C" {
#endif

    double Determinante(double *m, int n);

#ifdef __cplusplus
}
#endif

#endif /* DETERMINANTE_H */

