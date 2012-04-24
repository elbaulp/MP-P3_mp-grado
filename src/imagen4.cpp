#include "../include/imagen4.h"
#include "../include/imagenES.h"

#include <iostream>

using namespace std;

void Imagen::crear(int f, int c) {

		this->columnas = c;

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
		delete ptCelda; //Ultimo elemento de la estructura //TODO, borrarlo
}

//-------------------------

int Imagen::get_filas(){
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
			destruir();
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
		auxBuffer = 0;

	}
	return resul;
}

void Imagen::set_buffer(int i, int j, unsigned char v) {
	Celdas* aux = pt;

	while (i--)
		aux = aux->nextRow;

	aux->fila[j] = v;
	aux = 0;
}

//-------------------------

unsigned char Imagen::get_buffer(int i, int j) const {
	Celdas* aux = pt;

	while (i++)
		aux = aux->nextRow;
	return aux->fila[j];
}

//-------------------------

void Imagen::destruir() {
//	Celdas* aux = pt;
//	while(aux){
//		delete[] aux->fila;
//		Celdas* aux2 = aux->nextRow;
//		delete aux->nextRow;
//		aux = aux2;
//	}
}

//-------------------------

bool Imagen::escribir_imagen(const char file[]){
	//Pasamos de la estructura de buffer2 a la simple
	int filas = get_filas();
	unsigned char* auxBuffer = new unsigned char[filas * columnas];

	for (int i = 0; i < filas; i++)
		for (int j = 0; j < columnas; j++)
			auxBuffer[i*columnas + j] = get_buffer(i,j); //2d Array to 1D

	if (EscribirImagenPGM(file, auxBuffer, filas, columnas))
		return true;
	delete[] auxBuffer;

	return false;
}
