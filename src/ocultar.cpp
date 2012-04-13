/**
  * @file ocultar.cpp
  * @brief Fichero principal encargado de ocultar el mensaje
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
 * @brief Oculta un mensaje en una imagen de tipo pgm
 * @param inputImage[] nombre de la imagen en la que ocultar el mensaje
 * @param filas Filas de la imagen, es decir, la anchura
 * @param columnas Columnas de la imagen, es decir, la altura
 * @param outputImage[] Nombre que tendrá la imagen con el mensaje oculto
 * @param buffer[] Vector unidimensional con los valores de cada uno de los pixeles de la imagen
 * @param mensaje[] Cadena de texto a ocultar en la imagen.
 **********************************************************************************/
void oculta_SMS_en_PGM(char inputImage[], int& filas, int& columnas,
		char outputImage[], unsigned char buffer[], char mensaje[]){

	int tamTotalImagen = filas*columnas,
		tamTotalMensaje= (strlen(mensaje)+1)*8; //(strlen(mensaje)+1)*8) -> tamaño cadena +1 (Caracter \0), por 8bits de cada caracter

	if (LeerImagenPGM(inputImage, filas, columnas, buffer)) {
			switch (ocultar(buffer, tamTotalImagen, mensaje, tamTotalMensaje)) {
				case 0:
					if (EscribirImagenPGM(strcat(outputImage,".pgm"), buffer, filas, columnas))
						cout << "Ok" << endl;
					else
						cout << "Error al escribir la imagen" << endl;
					break;
				case -1:
					cout << "Imagen demasiado pequeña para sms tan largo";
					break;
			}
		}
	else
		cout << "Error al leer la imagen." << endl;
}

/**********************************************************************************
 * @brief Oculta un mensaje en una imagen de tipo ppm
 * @param inputImage[] nombre de la imagen en la que ocultar el mensaje
 * @param filas Filas de la imagen, es decir, la anchura
 * @param columnas Columnas de la imagen, es decir, la altura
 * @param outputImage[] Nombre que tendrá la imagen con el mensaje oculto
 * @param buffer[] Vector unidimensional con los valores de cada uno de los pixeles de la imagen
 * @param mensaje[] Cadena de texto a ocultar en la imagen.
 **********************************************************************************/
void oculta_SMS_en_PPM(char inputImage[], int& filas, int& columnas,
		char outputImage[], unsigned char buffer[], char mensaje[]){

	int tamTotalImagen = filas*columnas*3,		//(filas*columnas)*3 -> ppm usa 3 bytes por cada pixel,
		tamTotalMensaje= (strlen(mensaje)+1)*8;

	if (LeerImagenPPM(inputImage, filas, columnas, buffer)) {
			switch (ocultar(buffer, tamTotalImagen, mensaje, tamTotalMensaje)) {
				case 0:
					if (EscribirImagenPPM(strcat(outputImage,".ppm"), buffer, filas, columnas))
						cout << "Ok" << endl;
					else
						cout << "Error al escribir la imagen" << endl;
					break;
				case -1:
					cout << "Imagen demasiado pequeña para sms tan largo";
					break;
			}
		}
	else
		cout << "Error al leer la imagen." << endl;
}

void obtenerDatos(char inputImage[], char outputImage[], char mensaje[]){
	cout << "Introduzca la imagen de entrada: ";
	cin >> inputImage;

	cout << "Nombre de la imagen de salida: ";
	cin >> outputImage;

	cout << "Introduzca el mensaje a ocultar: ";

	cin.get(); //Consumo el \n que hay al pulsar enter tras pulsar enter al introducir outputImage
	cin.getline(mensaje, 125000, '\n');
	cout << "DEBUG: " << strlen(mensaje);
}

int main(){
	const int MAX_BUFFER = 1000000;
	const int MAX_NAME	 = 100;
	const int MAX_SMS	 = 125000;

	char inPutImage[MAX_NAME];
	char outPutImage[MAX_NAME];
	unsigned char buffer[MAX_BUFFER];

	int filas, columnas;
	char mensaje[MAX_SMS];

	obtenerDatos(inPutImage, outPutImage, mensaje);

	TipoImagen tipo = LeerTipoImagen(inPutImage, filas, columnas);

	switch (tipo) {
		case IMG_PGM:
			cout << "Ocultando...";
			oculta_SMS_en_PGM(inPutImage, filas, columnas, outPutImage, buffer, mensaje);
			break;
		case IMG_PPM:
			cout << "Ocultando...";
			oculta_SMS_en_PPM(inPutImage, filas, columnas, outPutImage, buffer, mensaje);
			break;
		case IMG_DESCONOCIDO:
			cout << "Tipo de imagen desconocida" << endl;
			break;
		}
}
