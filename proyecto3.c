#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
int reserva(int N, double* puntero) 
{
    if (N <= 0) 
    {
        return -1;
    }

    double* arreglo = (double*) malloc(N * sizeof(double));

    if (arreglo == NULL)
    {
        return -1;
    }

    for (size_t i = 0; i < N; i++)
    {
        arreglo[i] = 0.0;
    }
    
    memcpy(puntero, arreglo, N * sizeof(double));
    free(arreglo);
    
    return 0;

}