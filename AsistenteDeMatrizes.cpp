/**LIBRERIAS**/
#include <iostream>
#include <conio.h>
#include <stdlib.h>


//====================================================================================================================
//EDITA ESTO:

//Library by yours truly that sanitases the input for numbers.
#include <path\to\file\SANITASE_INPUT.cpp>
//Libreria con cosas basicas
#include <path\to\file\basic.cpp>
//Libreria para calcular el determinante
#include <path\to\file\calcular_determinante.cpp>
//Libreria para calcular la matriz transpuesta
#include <path\to\file\calcular_transpuesta.cpp>
//Libreria para calcular la adjunta de una matriz
#include <path\to\file\calcular_adjunta.cpp>
//Libreria para calcular la inversa de una matriz
#include <path\to\file\calcular_inversa.cpp>

//====================================================================================================================



/**DECLARACIONES**/
using namespace std;

int **matriz, nFilas, nCol;

/**PROTOTIPOS**/
void pedirDatos();

/**FUNCIONES**/

int main(){
	
	int opc=0;
	
	system("color 0a && title Asistente de Matrizes && mode 1000");
	
	pedirDatos();
	
	do{
		
		system("cls");
		mostrarMatriz(matriz, nFilas, nCol);
		cout<<"------------------------------------------------"<<endl
			<<"1 - Calcular la matriz transpuesta"<<endl
			<<"2 - Calcular determinante de la matriz"<<endl
			<<"3 - Calcular la matriz inversa"<<endl
			<<"4 - Calcular la matriz adjunta"<<endl
			<<"0 - Salir"<<endl
 			<<"------------------------------------------------"<<endl
			<<"Elija una opcion: ";
		opc=getIntNumber();
		
		
		switch(opc){
			case 1: calcularTranspuesta(matriz, nFilas, nCol, false,false,0);
					break;
			case 2: calcularDeterminante(matriz, nFilas, nCol, false);
					break;
			case 3: calcularInversa(matriz, nFilas, nCol,false,false,0);
					break;
			case 4:calcularAdjunta(matriz, nFilas, nCol, false,false,0);
					break;
		}
		
		
	}while(opc!=0);
	
	delete[] matriz;
	system("cls");
	cout<<"\n\t\tHasta luego!\n\n"<<endl;
	getch();
	return 0;
}


//Pide la informacion al usuario sobre el tamaño y contenidos de la matriz.
void pedirDatos(){
	
	cout<<"Ingrese el numero de Filas: ";
	nFilas=getIntNumber();
	cout<<"Ingrese el numero de Colunmas: ";
	nCol=getIntNumber();
	cout<<"\n";
	
	//Guardamos espacio para las filas y columnas
	matriz = new int*[nFilas];
	for (int i=0;i<nFilas;i++){
		matriz[i] = new int[nCol];
		
	}
	
	
	//Pedimos y guardamos contenido en la matriz
	for (int i=0;i<nFilas;i++){
		for(int j=0;j<nCol;j++){
			cout<<"Ingrese un elemento a la matriz ["<<i+1<<"]["<<j+1<<"]: ";
			*(*(matriz+i)+j) = getIntNumber();
		}
	}
}
