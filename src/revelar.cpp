/**
  * @file ocultar.cpp
  * @brief Fichero principal encargado de revelar el mensaje
  *
  *	Created on: Mar 15, 2012
  *		@author: Alejandro Alcalde
  */
#include "../include/imagenES.h"
#include "../include/codificar.h"
#include <string.h>
#include <iostream>

using namespace std;

/**********************************************************************************
 * @brief Descifra un mensaje en una imagen de tipo ppm
 * @param inputImage[] nombre de la imagen en la que ocultar el mensaje
 * @param filas Filas de la imagen, es decir, la anchura
 * @param columnas Columnas de la imagen, es decir, la altura
 * @param buffer[] Vector unidimensional con los valores de cada uno de los pixeles de la imagen
 * @param type Tipo de imagen de la que queremos extraer el mensaje oculto
 **********************************************************************************/
void descifrarSMS(char inPutImage[], int& filas, int& columnas, unsigned char buffer[], TipoImagen type){

	bool execResult;
	int tamImage;

	if (type == IMG_PGM){
		execResult = LeerImagenPGM(inPutImage, filas, columnas, buffer);
		tamImage = filas*columnas;
	}else{
		execResult = LeerImagenPPM(inPutImage, filas, columnas, buffer);
		tamImage = filas*columnas*3;
	}

	if (execResult) {
		const int MAX_SMS = 125000;
		char sms[MAX_SMS];
		switch (revelar(buffer, tamImage, sms, MAX_SMS)) {
		case 0:
			cout << "DEBUG: " << strlen(sms);
			cout << "SMS: " << sms << endl;
			break;
		case -1:
			cout << "Cadena de mayor tamaño que que la cadena donde almacenarlo" << endl;
			break;
		case -2:
			cout << "No se ha encontrado el caracter de fin de cadena." << endl;
			break;
		}
	} else
		cout << "Error al leer la imagen" << endl;
}

int main(){
	const int MAX_BUFFER = 1000000;
	const int MAX_NAME	 = 100;

	char inPutImage[MAX_NAME];
	unsigned char buffer[MAX_BUFFER];
	int filas, columnas;

	cout << "Introduzca la imagen a descifrar: ";
	cin >> inPutImage;

	TipoImagen tipo = LeerTipoImagen(inPutImage, filas, columnas);

	switch (tipo) {
		case IMG_PGM:
			descifrarSMS(inPutImage, filas, columnas, buffer, IMG_PGM);
			break;
		case IMG_PPM:
			descifrarSMS(inPutImage, filas, columnas, buffer, IMG_PPM);
			break;
		case IMG_DESCONOCIDO:
			cout << "Tipo de imagen desconocida" << endl;
			break;
	}
}
