///////////////////////////////////////////////////////////////////////////////
#ifndef MATRIZ
#define MATRIZ


#include <iostream>
#include <string.h>
using namespace std;


class Matriz2D{

private:

	static const int MAX_FILAS = 100;
	static const int MAX_COLUMNAS = 100;

	int cols = 0;
	int filas = 0;
	int * * datos = 0;


public:

	///////// INICIALIZAR////////////

	void reservarFilas();				// En caso de querer hacer una matriz que no fuese regular
	void reservarColumna(int fila);		// Emplear reservarFilas y luego reservarColumna y hacerlo de forma individual

	void reservarMem();
	void reservarMem(int n_filas, int n_cols);
	

	//////// AJUSTAR MATRIZ//////////
	void setFilas(int n_filas);/*{			//Hacen la matriz rectangular
		filas = n_filas;
	}*/
	void setCols(int n_cols);/*{			// si se inicializa tal cual
		cols = n_cols;
	}*/

	void valorFila(int fila, int elementos); // dar valores uno a uno de una fila entera

	void eliminarMem();

	void setElemento(int valor, int fila, int columna);

	void clonar(const Matriz2D & otro);

	//////////CONSTRUCTORES Y DESTRUCTORES/////////

	Matriz2D (void);

	~Matriz2D (void);

	Matriz2D (const Matriz2D & otro);

	Matriz2D (int num);

	Matriz2D (int fils, int columnas);


	//////////OBTENER VALORES/////////

	int getNfilas() const;
	int getNcols() const;

	int & getElement(int fila, int col);

	int * getFila(int fila);		// Devuelve un vector que contiene todos los datos de una fila

	void muestraMatriz();

	///////COMPARACIONES////////////

	bool esIgual(const Matriz2D & otro);


	//////////SOBRECARGA OPERADORES///////

	Matriz2D & operator = (const Matriz2D & otro);	//Llama al método clonar sobrecargando el símbolo =

	Matriz2D operator + (void);
	
	Matriz2D operator +(const Matriz2D & otro) const;

	Matriz2D operator + (int num) const;

	Matriz2D operator - (void);

	Matriz2D operator - (const Matriz2D & otro) const;



	int & operator () (const int fila, const int columna);	//getElement

	bool operator == (const Matriz2D & otro);
	bool operator != (const Matriz2D & otro);

	bool operator > (const Matriz2D & otro);
	bool operator < (const Matriz2D & otro);

};

#endif