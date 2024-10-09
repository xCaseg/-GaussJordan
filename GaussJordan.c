/*
Fecha: 06/02/2024
Universidad Tecmilenio. Campus Ferrería
Métodos numéricos
Profesor: Rodrigo David Cruz Serrano
Alumno: Carlos Alberto Segura Gámez
Matrícula: Al03056597
Modulo: 1
Ejercicio 6. Matriz de eliminación por Gauss-Jordan
*/

#include <stdio.h>
#include <stdlib.h>

#define max_m 10
#define max_n 11 

int main() {
    printf("Solución de sistemas de ecuaciones por el método de Gauss Jordan\n");

    int filas, columnas;

    printf("\nIngrese el número de filas 'm': ");
    scanf("%d", &filas);

    printf("Ingrese el número de columnas 'n', (Incluya la columna del resultado de las ecuaciones):");
    scanf("%d", &columnas);

    if (filas > max_m || columnas > max_n) {
        printf("Error: El tamaño de la matriz es demasiado grande.\n");
        return 1;
    }

    float matriz[max_m][max_n];

    printf("\nIngrese los coeficientes de las ecuaciones y el resultado:\n");
    for (int i = 0; i < filas; i++) {
        printf("\nEcuación %d: \n", i + 1);
        for (int j = 0; j < columnas; j++) {
            printf("coeficiente (%d, %d):", i + 1, j + 1);
            scanf("%f", &matriz[i][j]);
        }
    }

    // Imprimir matriz
    printf("\nLa matriz que ingresó es la siguiente:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }

    // Método de Gauss
    for (int i = 0; i < filas; i++) {
        if (matriz[i][i] == 0) {
            printf("Error, hay más de una solución\n");
            return 0;
        }

        for (int j = 0; j < filas; j++) {
            if (i != j) {
                float cociente = matriz[j][i] / matriz[i][i];

                for (int k = 0; k < columnas; k++) {
                    matriz[j][k] -= cociente * matriz[i][k];
                }
            }
        }
    }

    // Solución
    printf("\nRespuestas:\n");
    for (int i = 0; i < filas; i++) {
        float respuestas = matriz[i][columnas - 1] / matriz[i][i];
        printf("x%d = %.2f\n", i + 1, respuestas);
    }

    return 0;
}

	


