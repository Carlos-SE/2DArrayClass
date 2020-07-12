///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string.h>
#include <iomanip>
#include "Matriz2d.h"
using namespace std;



/////////INICIALIZAR///////
void Matriz2D :: reservarFilas(){
	datos = new int * [filas];
}
void Matriz2D ::reservarColumna(int fila){
	datos[fila] = new int [cols];
}
void Matriz2D ::reservarMem(){
	eliminarMem();

	datos = new int * [filas];
	for( int i = 0; i < filas; i++){
		datos[i] = new int [cols];
	}
}

void Matriz2D :: reservarMem(int n_filas, int n_cols){
	setFilas(n_filas);
	setCols(n_cols);
	
	reservarMem();
}


//////// AJUSTAR MATRIZ//////////
void Matriz2D ::setFilas(int n_filas){			//Hacen la matriz rectangular
	filas = n_filas;
}
void Matriz2D ::setCols(int n_cols){			// si se inicializa tal cual
	cols = n_cols;
}

void Matriz2D ::valorFila(int fila, int elementos){

	int valor;

	cout << "Introduzca los valores de la fila " << fila << ": ";

	for( int j = 0; j < elementos; j++){
		cin >> valor;
		datos[fila][j] = valor;
	}
	cout << endl;
}


void Matriz2D :: eliminarMem(){
	if (datos != 0){

		for(int i = 0; i < filas; i++){
			delete [] datos[i];
		}

		delete [] datos;

		datos=0;
		filas = 0;
		cols = 0;
	}
}


void Matriz2D :: setElemento(int valor, int fila, int columna){
	datos[fila][columna] = valor;	
}

void Matriz2D :: clonar(const Matriz2D & otro){

	eliminarMem();

	filas = otro.filas;
	cols = otro.cols;

	reservarMem(filas, cols);

	for (int i = 0; i < filas; i++){
		memcpy(&(datos[i][0]), &(otro.datos[i][0]),sizeof((otro.datos[i][0])) * cols);
	}


}

//////////CONSTRUCTORES Y DESTRUCTORES/////////

Matriz2D :: Matriz2D (void){

}

Matriz2D :: ~Matriz2D(void){
	eliminarMem();
}

Matriz2D :: Matriz2D(const Matriz2D & otro){
	clonar(otro);
}

Matriz2D :: Matriz2D (int num){
	filas = num;
	cols = num;
	reservarMem();
}

Matriz2D :: Matriz2D(int fils, int columnas){
	filas = fils;
	cols = columnas;

	reservarMem();
}

//////////OBTENER VALORES/////////

int Matriz2D ::getNfilas() const{
	return filas;
}
int Matriz2D ::getNcols() const{
	return cols;
}

int & Matriz2D ::getElement(int fila, int col){
	return datos[fila][col];
}

int * Matriz2D ::getFila(int fila){
	return datos[fila];
}

void Matriz2D :: muestraMatriz(){

	for( int f = 0; f < filas; f++){
		for( int c = 0; c < cols; c++){
			cout << setw(4) << datos[f][c] << " ";
		}
		cout << endl;
	}

}


////////COMPARACIONES////////////

bool Matriz2D :: esIgual(const Matriz2D & otro){
	bool iguales = false;

	if (filas == otro.filas && cols == otro.cols)
		iguales = true;

	if(iguales){

		for( int i = 0; i < filas && iguales == true; i++){
			for( int j = 0; j < cols && iguales == true; j++){
				if(datos[i][j] != otro.datos[i][j])
					iguales = false;
			}
		}
	}


	return iguales;
};


////////SOBRECARGA DE OPERADORES/////////////

Matriz2D & Matriz2D :: operator = (const Matriz2D & otro){

	clonar(otro);

	return(*this);
}

Matriz2D Matriz2D :: operator + (void){

	return (*this);
}

Matriz2D Matriz2D :: operator +(const Matriz2D & otro) const{

	Matriz2D tmp;

	if(getNfilas() == otro.getNfilas() && getNcols() == otro.getNcols()){

		
		tmp = otro;

		for (int i = 0; i < getNfilas(); i++){
			for ( int j = 0; j < getNcols(); j++){
				tmp(i,j) = tmp(i,j) + datos[i][j];
			}
		}
	}

	return tmp;

}

Matriz2D Matriz2D :: operator + (int num) const{

	Matriz2D tmp;

	tmp.setFilas(getNfilas());
	tmp.setCols(getNcols());

	tmp.reservarMem();

	for (int i = 0; i < tmp.getNfilas(); i++){
		for ( int j = 0; j < tmp.getNcols(); j++){
			tmp(i,j) = datos[i][j]+num;
		}
	}

	return (tmp);
}

Matriz2D Matriz2D :: operator -(const Matriz2D & otro) const{

	Matriz2D tmp;

	if(getNfilas() == otro.getNfilas() && getNcols() == otro.getNcols()){

		
		tmp.setFilas(getNfilas());
		tmp.setCols(getNcols());
		tmp.reservarMem();

		for (int i = 0; i < getNfilas(); i++){
			for ( int j = 0; j < getNcols(); j++){
				tmp(i,j) = datos[i][j] - otro.datos[i][j];
			}
		}
	}

	return tmp;

}

Matriz2D Matriz2D :: operator - (void){
	Matriz2D tmp;
	tmp.setFilas(filas);
	tmp.setCols(cols);
	tmp.reservarMem();


	for (int i = 0; i < filas; i++){
		for( int j = 0; j < cols; j++){
			tmp(i,j) = datos[i][j]*(-1);
		}
	}

	return (tmp);
}

int &  Matriz2D :: operator () (const int fila, const int columna){

	return getElement(fila, columna);
}

bool Matriz2D :: operator == (const Matriz2D & otro){
	//El tamaño de ambas matrices ha de ser igual. De lo contrario devolverá false

	return esIgual(otro);

}

bool Matriz2D :: operator != (const Matriz2D & otro){
	//El tamaño de ambas matrices ha de ser igual. De lo contrario devolverá true

	return !(esIgual(otro));

}

bool Matriz2D :: operator > (const Matriz2D & otro){
	//Será mayor o menor dependiendo únicamente del tamaño, sin tener en cuenta los valores
	
	bool esMayor = (getNfilas()*getNcols() > otro.getNfilas()*otro.getNcols() ? true:false);

	return esMayor;
}

bool Matriz2D :: operator < (const Matriz2D & otro){

	return !(*this>otro);
}