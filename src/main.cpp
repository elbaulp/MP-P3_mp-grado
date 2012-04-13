/**
  * @file main.cpp
  * @brief Fichero principal
  *
  *	Created on: Mar 15, 2012
  *		@author: Alejandro Alcalde
  *
  */

#include "../include/imagenES.h"
#include "../include/codificar.h"
#include <string.h>
#include <iostream>

using namespace std;


int main(){
	const int MAX_BUFFER = 1000000;
	const int MAX_NAME	 = 100;
	const int MAX_SMS	 = 125000;

	char imageName[MAX_NAME] = "imagenes/lenna.pgm";
	char imageName2[MAX_NAME] = "salida.pgm";
	unsigned char buffer[MAX_BUFFER];

	int filas, columnas;
	char mensaje[] = "Nas, Buenas, ¿Qué tal?";

	TipoImagen tipo = LeerTipoImagen(imageName, filas, columnas);

	switch (tipo) {
		case IMG_PGM:
			if(LeerImagenPGM(imageName,filas, columnas, buffer)){
				switch(ocultar(buffer, filas, columnas, mensaje, strlen(mensaje))){
					case 0:
						if(EscribirImagenPGM("salida.pgm",buffer,filas, columnas))
							cout << "Ok";
						else
							cout << "Error al escribir la imagen" ;
						break;
					case -1:
						cout << "Imagen demasiado pequeña para sms tan largo";
						break;
				}
			}
			if(LeerImagenPGM(imageName2, filas, columnas, buffer)){
				char sms[MAX_NAME];
				switch (revelar(buffer, filas, columnas, sms, 120)) {
					case 0:
						cout << "SMS: " << sms << endl;
						break;
					case -1:
						cout << "Cadena de mayor tamaño que que la cadena donde almacenarlo";
						break;
					case -2:
						cout << "No se ha encontrado el caracter de fin de cadena.";
						break;
				}
			}
			else
				cout << "Error al leer la imagen";
			break;
		case IMG_PPM:

			break;
		case IMG_DESCONOCIDO:

		default:
			break;
	}
}
