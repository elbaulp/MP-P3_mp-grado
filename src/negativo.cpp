/**
  * @file ocultar.cpp
  * @brief Fichero principal encargado de ocultar el mensaje
  *
  *	Created on: Mar 15, 2012
  *		@author: Alejandro Alcalde
  */
#include "../include/imagenES.h"
#include "../include/imagen.h"
#include "../include/transformar.h"

#include <iostream>

using namespace std;

int main (int argc,char *argv[])
{
   Imagen img;
   if(argc < 3){
      cout <<"Uso: "<<"negativo imagenEntrada.pgm imagenSalida.pgm" << endl;
      return -1;
   }
   else{
      img.crear(0,0);
      if(!img.leer_imagen(argv[1])){ //PAsamos el archivo a leer
         cout << "No se puede leer la imagen " << endl;
         return -2;
      }
      else
         negativo(img); //En transformar
         if(!img.escribir_imagen(argv[2])){
            cout << "No se puede escribir la imagen " << endl;
            return -3;
         }

      img.destruir();
   }
   return 0;
}

