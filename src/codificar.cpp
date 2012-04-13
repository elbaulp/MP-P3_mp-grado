/*
 * @file codificar.cpp
 * @brief Encargada de codificar y descodificar mensajes ocultos
 *  Created on: Mar 15, 2012
 *      @author: Alejandro Alcalde
 */
#include "../include/codificar.h"

int ocultar(unsigned char buffer[],int tamImage, char sms[], int tamSms){

	unsigned short int indiceLetra		  = 0;
	char letra							  = sms[indiceLetra];
	short int bitsLetraRestantes 		  = 7;
	//Empezamos por el bit más significativo (10000000)
	unsigned char mask[]				  = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};

	//Imagen demasiado pequeña para la cadena suministrada
	if (tamImage < tamSms)
		return -1;

	for (int i = 0; i <= tamImage && i < tamSms; i++){
		buffer[i] = buffer[i] >> 1; //Ponemos a 0 el ultimo bit haciendo dos desplazamientos
		buffer[i] = buffer[i] << 1;

		if (bitsLetraRestantes < 0){
			bitsLetraRestantes = 7;
			letra 			   = sms[++indiceLetra];
		}
		// Sacamos el bit de la letra en su posición y lo desplazamos a la pos menos significativa
		char c = (letra & mask[7-bitsLetraRestantes]) >> bitsLetraRestantes--;
		buffer[i] ^= c; //Almacenamos en el ultimo bit del pixel el valor del caracter
		//buffer[i] ^= 0xff; //Negativo e invertido
		//buffer[i] = ~buffer[i];
		//buffer[i] >>= 1; //Más oscura
		//buffer[i] <<=1; //Más clara
	}

	return 0;
}

//____________________________________________________________________________

int revelar(unsigned char buffer[], int tamImage, char sms[], int tamSMS){

	int indice		  		  = 0;
	char value 		  		  = 0;
	bool finCadena 	  		  = false;

	for (int i = 0; i < tamImage && /*sms[indice] != '\0'*/!finCadena; i++){
		value = value << 1 | (buffer[i]&0x01); //vamos almacenando en value los 8 bits
		//Cuando recorramos 7 bits, lo almacenamos al array, almacenamos cada 8 iteraciones (1byte).
		//Para que el if sea mas rápido (Ya que es una op ||), pongo la condicion i == 7 al final, ya que solo se va a evaluar una vez
		if (((i-7)%8) == 0 || i == 7){
			sms[indice] = value;
			value = 0;
			if(sms[indice++] == '\0')
				finCadena = true;
			if(indice > tamSMS)
				return -1; //cadena de mayor tamaño que que la cadena donde almacenarlo
		}
	}

	if(!finCadena)
		return -2; //Si finCadena == false, no hemos encontrado caracter \0
	return 0;
}
