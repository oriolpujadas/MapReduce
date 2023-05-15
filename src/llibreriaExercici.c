#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "rlutil.h"
#include "llibreriaPropia.h"
#include "llibreriaExercici.h"


int contarPalabras(FILE *archivo) {
    int contadorPalabras = 0;
    char caracter;
    int dentroDePalabra = 0;

    while ((caracter = fgetc(archivo)) != EOF) {
        if (isalpha(caracter)) {
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

    return contadorPalabras;
}

int contarLetras(FILE *archivo) {
    int contadorLetras = 0;
    char caracter;

    while ((caracter = fgetc(archivo)) != EOF) {
        if (isalpha(caracter)) {
            contadorLetras++;
        }
    }

    return contadorLetras;
}
