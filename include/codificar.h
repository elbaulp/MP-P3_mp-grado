/**
  * @file codificar.h
  * @brief Fichero cabecera que oculta/revela mensajes
  *
  * @author Alejandro Alcalde Barros
  * 	@date 16/03/2012
  *
  */

#ifndef CODIFICAR_H_
#define CODIFICAR_H_

/**
  * @brief Oculta un mensaje en los bytes de la imagen dada
  *
  * @param buffer Datos de la imagen
  * @param filas Filas de la imagen.
  * @param columnas Columnas de la imagen.
  * @param mensaje Mensaje a ocultar en la imagen
  * @param tamaño Tamaño del mensaje a cifrar.
  * @return 0 si todo fue bien
  * @return -1 si la imagen es demasiado pequeña para el mensaje a cifrar
  * @pre buffer debe ser una zona de memoria suficientemente grande como para
  * almacenar @a filas x @a columnas bytes de datos de la imagen.
  */
int ocultar(unsigned char[],int , char[], int);

/**
  * @brief Revela un mensaje en los bytes de la imagen dada
  *
  * @param buffer Datos de la imagen
  * @param filas Filas de la imagen.
  * @param columnas Columnas de la imagen.
  * @param mensaje Parámetro de salida donde se almacenará el mensaje extraido.
  * @param tamaño Tamaño máximo de la cadena de caracteres.
  * @return si ha  tenido éxito en la lectura
  * @pre buffer debe ser una zona de memoria suficientemente grande como para
  * almacenar @a filas x @a columnas bytes de datos de la imagen.
  */
int revelar(unsigned char[],int, char[], int);

//int revelar(int image[], char& menssage[]);

#endif /* CODIFICAR_H_ */
