#include "../include/imagen4.h"
#include "../include/imagenES.h"

#include <iostream>

using namespace std;

void Imagen::crear(int f, int c) {

		columnas = c;

		Celdas primero;

		primero.fila = new unsigned char[columnas];
		pt = &primero;

		Celdas* ptCelda = &primero;

		for (int i = 1; i < f; i++) {
			Celdas* aux = new Celdas;
			aux->fila = new unsigned char[columnas];
			ptCelda->nextRow = aux;
			ptCelda = aux;
		}
		ptCelda->nextRow = 0; //Ultimo elemento de la estructura //TODO, borrarlo
}

//-------------------------

int Imagen::contar_filas(){
	int filas = 0;
	Celdas* aux = pt;

	while(aux){
		aux = aux->nextRow;
		filas++;
	}
	aux = 0;

	return filas;
}

//-------------------------

bool Imagen::leer_imagen(const char file[]) {
	int f;
	int c;
	bool resul = false;
	unsigned char* auxBuffer;

	TipoImagen tipo = LeerTipoImagen(file, f, c);

	if (tipo == IMG_PGM) {
		auxBuffer = new unsigned char[f * c];
		if (LeerImagenPGM(file, f, c, auxBuffer)) {
			//destruir();
			crear(f, c);
			//Cambio de estructura
			Celdas* aux = pt;
			for (int i = 0; i < f; i++){
				for (int j = 0; j < columnas; j++)
					aux->fila[j] = auxBuffer[i * columnas + j];
				aux = aux->nextRow;
			}
			aux = 0;
			resul = true;
		}
		delete[] auxBuffer;

	}
	return resul;
}

void Imagen::set_buffer(int i, int j, unsigned char v) {
;
}

//-------------------------

unsigned char Imagen::get_buffer(int i, int j) const {
}

//-------------------------

void Imagen::destruir() {

}

//-------------------------

bool Imagen::escribir_imagen(const char file[]) const {

}
