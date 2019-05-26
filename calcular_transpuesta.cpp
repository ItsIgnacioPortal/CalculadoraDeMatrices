/*

ON ERROR: RETURN 0

*/
/**LIBRERIAS**/
#include <iostream>
#include <stdlib.h>

/**DECLARACIONES**/
using namespace std;

/**PROTOTIPOS DE FUNCION**/
int calcularTranspuesta(int **,int,int,bool,bool,int **);

/**PROTOTIPOS**/
int **matriz_transpuesta;

/**FUNCIONES**/


//ON ERROR: RETURNS 999

int calcularTranspuesta(int **matriz, int nFilas, int nCol, bool modoSilencioso, bool devolverMatriz, int **matriz_objetivo){

	
	if(nCol==nFilas){
	
	
		//Guardamos espacio para las filas y columnas
		matriz_transpuesta = new int*[nFilas];
		for (int i=0;i<nFilas;i++){
		
			matriz_transpuesta[i] = new int[nCol];
		
		}
		
		
		
		//Guardamos los numeros transpuestos en la matriz
		for (int i=0;i<nFilas;i++){
			for(int j=0;j<nCol;j++){
				
				*(*(matriz_transpuesta+j)+i) = *(*(matriz+i)+j);
							
			}
		}


		if(modoSilencioso==false){
			
			
			cout<<"\n\n\tLa matriz transpuesta es: \n";	
			mostrarMatriz(matriz_transpuesta,nFilas,nCol);
			
		}
		
		
		if(devolverMatriz==true){
			
			for (int i=0;i<nFilas;i++){
				for(int j=0;j<nCol;j++){
					
					*(*(matriz_objetivo+j)+i) = *(*(matriz_transpuesta+j)+i);
								
				}
			}
			
		}
	
	
		delete[] matriz_transpuesta;
		return 0;
			
	} else {
		
		system("cls");
		cout<<"\n\tLamentablemente por el momento este asistente solo transpone matrices cuadradas :,/"<<endl;
		system("pause");
		return 999;

	}
	

}

