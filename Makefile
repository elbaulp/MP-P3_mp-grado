
SRC 	= src
INC 	= include
OBJ 	= obj
DIR_LIB = lib
LIB		= libimagen.a
CXX 	= g++
CPPFLAGS= -Wall -g -O3 -ansi -I$(INC) -c # Poner -O3 -ansi cuando deje de depuarar para optimizar
INC_LIB = -L./$(DIR_LIB) -limagen
IMAGENES= obj/imagen1.cpp obj/imagen2.cpp obj/imagen3.cpp obj/imagen4.cpp
IMAGENESO= $(IMAGENES:.cpp=.o)

all: negativo desplazar

negativo: $(OBJ)/negativo.o $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/transformar.o $(DIR_LIB)/$(LIB)
	@echo Creando la $@... con $^
	$(CXX) -Wall -g $^ $(INC_LIB) -o $@
desplazar: $(OBJ)/desplazar.o $(OBJ)/imagenES.o $(OBJ)/imagen.o $(OBJ)/transformar.o $(DIR_LIB)/$(LIB)
	@echo Creando la $@... con $^
	$(CXX) -Wall -g  $^ -o $@
	
$(OBJ)/imagenES.o : $(SRC)/imagenES.cpp $(INC)/imagenES.h
	@echo Creando la $@... con $^
	$(CXX) $(CPPFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o
$(OBJ)/negativo.o : $(SRC)/negativo.cpp
	@echo Creando la $@... con $^
	$(CXX) $(CPPFLAGS) $(SRC)/negativo.cpp -o $(OBJ)/negativo.o
$(OBJ)/desplazar.o : $(SRC)/desplazar.cpp
	@echo Creando la $@... con $^
	$(CXX) $(CPPFLAGS) $(SRC)/desplazar.cpp -o $(OBJ)/desplazar.o
$(OBJ)/transformar.o: $(SRC)/transformar.cpp $(INC)/transformar.h $(SRC)/imagen.cpp $(INC)/imagen.h
	@echo Creando la $@... con $^
	$(CXX) $(CPPFLAGS) $(SRC)/transformar.cpp -o $(OBJ)/transformar.o

$(OBJ)/imagen.o : $(IMAGENESO) $(INC)/imagen*.h
	@echo Creando la $@... con $^
	$(CXX) $(CPPFLAGS) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o

$(OBJ)/imagen1.o : $(SRC)/imagen1.cpp $(INC)/imagen1.h
	@echo Creando la $@... con $^
	$(CXX) $(CPPFLAGS) $(SRC)/imagen1.cpp -o $(OBJ)/imagen1.o
$(OBJ)/imagen2.o : $(SRC)/imagen2.cpp $(INC)/imagen2.h
	@echo Creando la $@... con $^
	$(CXX) $(CPPFLAGS) $(SRC)/imagen2.cpp -o $(OBJ)/imagen2.o
$(OBJ)/imagen3.o : $(SRC)/imagen3.cpp $(INC)/imagen3.h
	@echo Creando la $@... con $^
	$(CXX) $(CPPFLAGS) $(SRC)/imagen3.cpp -o $(OBJ)/imagen3.o
$(OBJ)/imagen4.o : $(SRC)/imagen4.cpp $(INC)/imagen4.h
	@echo Creando la $@... con $^
	$(CXX) $(CPPFLAGS) $(SRC)/imagen4.cpp -o $(OBJ)/imagen4.o


$(DIR_LIB)/$(LIB): $(OBJ)/imagenES.o $(OBJ)/transformar.o $(OBJ)/imagen.o
	@echo Creando la librería $@... con $^
	ar rvs $@ $^

documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Limpieza ************
.PHONY: clean
clean :
	@echo Limpiando archivos intermedios...
	rm $(DIR_LIB)/* $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
