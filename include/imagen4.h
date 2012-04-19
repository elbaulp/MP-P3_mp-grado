/*
 * imagen4.h
 *
 *  Created on: Apr 18, 2012
 *      Author: hkr
 */

#ifndef IMAGEN4_H_
#define IMAGEN4_H_

class Imagen{

private:
	int filas;
	int columnas;

public:
	Imagen(int f, int c);						//Reserva recursos en memoria dinámica

	inline int get_filas() const{				//Devuelve el número de filas de m
		return filas;
	}
	inline int get_columnas() const{			//Devuelve el número de columnas de m
		return columnas;
	}
	void set_buffer(int, int, unsigned char);	//Hace img(i,j)=v
	unsigned char get_buffer(int, int) const; 	//Devuelve img(i,j)
	void destruir();							//Libera recursos de m
	bool leer_imagen(const char[]);				//Carga imagen en img
	bool escribir_imagen(const char[]) const;	//Salva img en un archivo
};


#endif /* IMAGEN4_H_ */
