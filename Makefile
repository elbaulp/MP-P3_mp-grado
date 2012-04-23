
SRC = src
INC = include
OBJ = obj
CXX = g++
CPPFLAGS = -Wall -g -v  -I$(INC) -c

all: negativo desplazar

negativo: $(OBJ)/negativo.o $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/transformar.o
	$(CXX) -Wall -g -v  $^ -o $@
desplazar: $(OBJ)/desplazar.o $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/transformar.o
	$(CXX) -Wall -g -v  $^ -o $@
	
$(OBJ)/transformar.o: $(SRC)/transformar.cpp $(INC)/transformar.h
	$(CXX) $(CPPFLAGS) $(SRC)/transformar.cpp -o $(OBJ)/transformar.o
$(OBJ)/imagenES.o : $(SRC)/imagenES.cpp $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o
$(OBJ)/negativo.o : $(SRC)/negativo.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/negativo.cpp -o $(OBJ)/negativo.o
$(OBJ)/desplazar.o : $(SRC)/desplazar.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/desplazar.cpp -o $(OBJ)/desplazar.o
$(OBJ)/imagen.o : $(SRC)/imagen.cpp $(INC)/imagen.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o

#all: ocultar revelar

## ************ Generación de ocular   ************
#ocultar: $(OBJ)/ocultar.o $(OBJ)/imagenES.o $(OBJ)/codificar.o
#	$(CXX) -Wall -g -v  $^ -o $@
#	
#$(OBJ)/ocultar.o : $(SRC)/ocultar.cpp
#	$(CXX) $(CPPFLAGS) $(SRC)/ocultar.cpp -o $(OBJ)/ocultar.o
## ************ Generación de revelar   ************
#revelar: $(OBJ)/revelar.o $(OBJ)/imagenES.o $(OBJ)/codificar.o
#	$(CXX) -Wall -g -v  $^ -o $@
#
#$(OBJ)/revelar.o : $(SRC)/revelar.cpp
#	$(CXX) $(CPPFLAGS) $(SRC)/revelar.cpp -o $(OBJ)/revelar.o
## ************ Compilación de módulos ************
##programa: $(OBJ)/main.o $(OBJ)/imagenES.o $(OBJ)/codificar.o
##	$(CXX) -Wall -g -v  $^ -o $@
#
##$(OBJ)/main.o : $(SRC)/main.cpp
##	$(CXX) $(CPPFLAGS) $(SRC)/main.cpp -o $(OBJ)/main.o
#
#$(OBJ)/imagenES.o : $(SRC)/imagenES.cpp $(INC)/imagenES.h
#	$(CXX) $(CPPFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o
#
#$(OBJ)/codificar.o : $(SRC)/codificar.cpp $(INC)/codificar.h
#	$(CXX) $(CPPFLAGS) $(SRC)/codificar.cpp -o $(OBJ)/codificar.o
#
## ************ Generación de documentación ******************

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************
clean :
	rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
