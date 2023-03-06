/*
    Autor: Jose Rodolfo Rojas Ocampo / Luis Fernando / Kevin Campos Castro
    Fecha: 28/02/2023
    Version: 1.0
*/
/*
    Programa que lee un txt de doubles e imprime en pantalla 
    en forma ordenada la lista que se encuientra en el txt
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    // Para detectar cantidad correcta de parametros
    if (argc != 2) {
        printf("La cantidad de argumentos ingresados es incorrecto, solo se debe ingresar un archivo.\n");
        return -1;
        exit(0);
    }

    // Puntero para leer el archivo
    FILE *fp = fopen("./lista_numeros.txt", "r");
    if (!fp) {
        printf("El archivo no pudo ser leido.\n");
        return -1;
        exit(0);
    }

    int c;  // Contador
    int newlines = 1;

    // Busca cada nueva linea (\n)
    for (c = getc(fp); c != EOF; c = getc(fp)) {
        if (c == '\n') {
            newlines += 1;
        }
    }
    
    // Volver el puntero que lee el archivo al inicio
    rewind(fp);

    float arreglo[newlines];
    int i = 0;

    // Verificar que los datos ingresados sean flotantes
    for (i; i < newlines; i++) {
        if (fscanf(fp, "%f", &arreglo[i]) != 1) {
            printf("Uno de los datos ingresados no es un flotante.\n");
            return -1;
            exit(0);
        }
    }

    // Guardar valores encontrados en el archivo en un arreglo
    while(i < newlines && fscanf(fp, "%f", &arreglo[i]) == 1) {
        i++;
    }

    // Metodo burbuja
    for (int indice = 0; indice < newlines - 1; ++indice) {
        int k = 0;
        
        // Comparacion de elementos de arreglo
        while (k < newlines - indice - 1) {
            // Ver cual numero es mayor
            if (arreglo[k] > arreglo[k + 1]) {
                
                // Guardar el valor de la posicion k y realizar el cambio del valor
                float memoria = arreglo[k]; // Se debe guardar el valor, sino se pierde el dato
                arreglo[k] = arreglo[k + 1];
                arreglo[k + 1] = memoria;
            }
            k++;
        }
    }

    // Imprimir arreglo ordenado
    for (int z = 0; z != newlines; z++) {
        printf("%f\n", arreglo[z]);
    }
    return 0;
}
