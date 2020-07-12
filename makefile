HOME = .
BIN = $(HOME)/bin
INCLUDE = $(HOME)/include
SRC = $(HOME)/src
OBJ = $(HOME)/obj
LIB = $(HOME)/lib


all : presentacion $(BIN)/SobrecargaIgual clean final

$(BIN)/SobrecargaIgual : $(OBJ)/SobrecargaIgual.o $(OBJ)/Matriz2d.o
	g++ -o $(BIN)/SobrecargaIgual $(OBJ)/SobrecargaIgual.o $(OBJ)/Matriz2d.o

$(OBJ)/SobrecargaIgual.o : $(SRC)/SobrecargaIgual.cpp
	g++ -c -o $(OBJ)/SobrecargaIgual.o $(SRC)/SobrecargaIgual.cpp -I$(INCLUDE)

$(OBJ)/Matriz2d.o : $(SRC)/Matriz2d.cpp
	g++ -c -o $(OBJ)/Matriz2d.o $(SRC)/Matriz2d.cpp -I$(INCLUDE)





##########################

presentacion :
	@echo "################################################"
	@echo
	@echo "Comienzo de compilación de ./bin/SobrecargaIgual"
	@echo "  ____ _   _________  __   ____  ___   ___ "
	@echo " / __ \\ | / / __/ _ \\/ /  / __ \\/ _ | / _ \\"
	@echo "/ /_/ / |/ / _// , _/ /__/ /_/ / __ |/ // /"
	@echo "\\____/|___/___/_/|_/____/\\____/_/ |_/____/ "
	@echo
	@echo "################################################"
	@echo
	@echo
	@echo

clean :
	-rm $(OBJ)/*

mr.proper : clean
	-rm $(BIN)/*

final :
	@echo
	@echo Terminado
	@echo