/**LIBRERIAS**/
#include <iostream>


/**DECLARACIONES**/
using namespace std;

/**PROTOTIPOS**/
void mostrarMatriz(int **,int,int);


void mostrarMatriz(int **matriz,int nFilas,int nCol){
	
	//cout<<"Los contenidos de la matriz son: \n\n";
	
	for (int i=0;i<nFilas;i++){
		cout<<"| ";
		for(int j=0;j<nCol;j++){
			cout<<*(*(matriz+i)+j)<<" | ";
		}
		
		cout<<"\n";
	}
	cout<<"\n";
	
}
