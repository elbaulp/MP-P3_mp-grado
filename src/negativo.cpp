/**
  * @file ocultar.cpp
  * @brief Fichero principal encargado de ocultar el mensaje
  *
  *	Created on: Mar 15, 2012
  *		@author: Alejandro Alcalde
  */
#include "../include/imagenES.h"
#include "../include/imagen.h"

#include <iostream>

using namespace std;

int main(){
	int filas;
	int columnas;
	//TODO -> Comprobar el tipo devuelto
	TipoImagen tipo = LeerTipoImagen("./imagenes/hombro.pgm", filas, columnas);
	Imagen img(filas,columnas);
	char file[] = "./imagenes/hombro.pgm";

	if(img.leer_imagen(file)){
		cout << "s";
	}

	//cout << img.get_filas() << " " << img.get_columnas();
}
