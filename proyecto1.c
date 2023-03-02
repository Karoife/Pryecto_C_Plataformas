/*
    Autor: Jose Rodolfo Rojas Ocampo / Luis Fernando / Kevin
    Fecha: 28/02/2023
    Version: 1.0
*/
/*
    Programa que imprime la cantidad de pasos necesaria segun el tipo de paso
    1, 2, 3, 4 para subir un numero de escalones y todas sus combinaciones
*/

#include <stdio.h>
#include <stdlib.h>
// Funcion que imprime los valores de los pasos, simplemente recibe
// una arreglo y su tamano 
void imprimir_pasos(int pasos[], int cantidad_pasos)
{
    for (int i = 0; i < cantidad_pasos; i++)
    {
        if (i == cantidad_pasos-1)
        {
            printf("%d", pasos[i]); // en final de cola solo imprime el numero
        }
        else
        {
            printf("%d,", pasos[i]); // si no es final de cola imprime con ,
        }        
    }
    printf("\n");
}

void calculoPasos(int valor, int pasos[], int cantidad_pasos)
{
    // casi canonico
    if (valor == 0) 
    {
        imprimir_pasos(pasos, cantidad_pasos);
        return;
    }
    else if (valor < 0) // si el valor es negativo no deberia hacer nada
    {
        return;
    }

    // Toma cada posible tamano del paso
    for (int i = 1; i <= 4; i++)
    {
        pasos[cantidad_pasos] = i;
        calculoPasos(valor-i, pasos, cantidad_pasos+1);
    }
    
}

int main(int argc, char *argv[])
{
    if (argc < 2 )
    {
        fprintf(stderr, "Debe ingresar un argumento\n");
        exit(-1);
    }
    else if (argc > 2)
    {
        fprintf(stderr, "Solo puede ingresar un arrgumewnto\n");
        exit(-1);
    }
    else
    {
        int n;
        n = atoi(argv[1]);
        if ( n < 0 )
        {
            fprintf(stderr, "El valor debe ser mayor a 0\n");
            exit(-1);
        }
        else
        {
            int pasos[n];
            calculoPasos(n, pasos, 0);
        }
    }
    return 0;
}