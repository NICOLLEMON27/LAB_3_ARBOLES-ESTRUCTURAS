#include<iostream>

#include "binario.h"

using std::cout;//Salida Estandar
using std::endl;//Fin de linea
using std::cin;// Entrada Estandar

using arbol::binario;//Arbol binario generico

int main (int argc, char *argv[]) {
	
	//crear una instncia del arbol binario
	binario<int> a;
	
	cout<<(a.es_vacio()?
		   "El arbol esta vacio":
		   "El arbol no esta vacio") <<endl;
	
	//insetar datos
	cout<<"insertar datos"<<endl;
	a.insertar(30);
	a.insertar(25);
	a.insertar(36);
	a.insertar(47);
	a.insertar(32);
	a.insertar(27);
	//impriir en preoOrden
	a.preorden();
	cout<<endl;
	a.inorden();
	cout<<endl;
	a.posorden();
	return 0;
}

