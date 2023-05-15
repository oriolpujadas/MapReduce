#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "rlutil.h"
#include <windows.h>
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"

int main()
{
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	srand(time(NULL));

	FILE *archivo;
    char nombreArchivo[] = "lorem1.txt";
    int opcion;

    archivo = fopen(nombreArchivo, "w");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.");
        exit(1);
    }

    printf("Menú:\n");
    printf("1. Contar palabras\n");
    printf("2. Contar letras\n");
    printf("Ingrese su opción: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            printf("Número de palabras: %d\n", contarPalabras(archivo));
            break;
        case 2:
            printf("Número de letras: %d\n", contarLetras(archivo));
            break;
        default:
            printf("Opción inválida.\n");
    }

    fclose(archivo);

	 FILE *archivoEntrada, *archivoSalida;
    char nombreArchivoEntrada[] = "lorem1.txt";
    char nombreArchivoSalida[] = "archivo_salida.txt";
    char caracter;
    int contadorPalabras = 0;
    int contadorLetras = 0;
    int dentroDePalabra = 0;

    archivoEntrada = fopen(nombreArchivoEntrada, "w");
    archivoSalida = fopen(nombreArchivoSalida, "w");

    if (archivoEntrada == NULL || archivoSalida == NULL) {
        printf("Error al abrir los archivos.");
        exit(1);
    }

    while ((caracter = fgetc(archivoEntrada)) != EOF) {
        if (isalpha(caracter)) {
            contadorLetras++;
            dentroDePalabra = 1;
        } else if (caracter == ' ' || caracter == '\n' || caracter == '\t') {
            if (dentroDePalabra) {
                contadorPalabras++;
                dentroDePalabra = 0;
            }
        }
    }

    if (dentroDePalabra) {
        contadorPalabras++;
    }

    fprintf(archivoSalida, "Número de palabras: %d\n", contadorPalabras);
    fprintf(archivoSalida, "Número de letras: %d\n", contadorLetras);

    fclose(archivoEntrada);
    fclose(archivoSalida);

	acabament();
	return 0;  
} 
