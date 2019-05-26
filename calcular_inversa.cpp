/**LIBRERIAS**/
#include <iostream>
#include <stdlib.h>


/**DECLARACIONES**/
using namespace std;

/**PROTOTIPOS DE FUNCION**/
int calcularInversa(int **,int,int,bool);

/**PROTOTIPOS**/
int **matriz_transpuesta2;
int **matriz_adjunta2;
int **matriz_inversa;

/**FUNCIONES**/

int calcularInversa(int **matriz,int nFilas,int nCol, bool modoSilencioso, bool devolverMatriz, int **matriz_objetivo){
	
	int determinante=0;
	
	
	//Se calcula el determinante
	system("cls");
	cout<<"\n\n\n\t\tCalculando determinante...\n\n";
	determinante=calcularDeterminante(matriz, nFilas, nCol,false);
	
	//Si es 0, no se puede calcular
	if(determinante!=0){
		
		
		
		
		/**-----------------------------------------------------------------------------------**/
		//Se guarda memoria para la matriz_inversa
		matriz_inversa = new int*[nFilas];
		for (int i=0;i<nFilas;i++){
			matriz_inversa[i] = new int[nCol];
			
		}
		
		//Se guarda memoria para la matriz_transpuesta2
		matriz_transpuesta2 = new int*[nFilas];
		for (int i=0;i<nFilas;i++){
			matriz_transpuesta2[i] = new int[nCol];
			
		}
		
		//Se guarda memoria para la matriz_adjunta2
		matriz_adjunta2 = new int*[nFilas];
		for (int i=0;i<nFilas;i++){
			matriz_adjunta2[i] = new int[nCol];
			
		}
		/**-----------------------------------------------------------------------------------**/
		
		
		
		

		//Se guarda la matriz transpuesta
		cout<<"\n\n\n\t\tCalculando transpuesta...\n\n";
		if( calcularTranspuesta(matriz, nFilas, nCol,false,true,matriz_transpuesta2) == 999){
			
			//ON ERROR:
			system("cls");
			cout<<"\n\t-No se puede continuar-"<<endl;
			system("pause");
			return 999;
			
		}
		


		//Se calcula la adjunta de la matriz transpuesta
		cout<<"\n\n\n\t\tCalculando adjunta...\n\n";
		system("pause");
		calcularAdjunta(matriz_transpuesta2, nFilas, nCol,false,true,matriz_adjunta2);
		//No "ON ERROR" clause, becouse if it passed the 1st check, then its good 2 go

		
		
		cout<<"\n\n";
		//Se dividen a los elementos de la matriz adjunta con el determinante.
		for (int i=0;i<nFilas;i++){
			for(int j=0;j<nCol;j++){
				
				cout<<"\t"
					<<"A-1 sub"<<i+1<<j+1<<" "
					<< *(*(matriz_adjunta2+j)+i) 
					<< " * " 
					<< determinante 
					<< " = " 
					<< *(*(matriz_inversa+j)+i) 
					<<endl;
					
				*(*(matriz_inversa+j)+i) = *(*(matriz_adjunta2+j)+i) * determinante;
				
			}
		}
		
		cout<<"\n\n";
		
		
	} else {
		system("cls");
		cout<<"\n--------------------------------------------------------\n";
		cout<<"\n|\n|\t\tLa inversa de la matriz ingresada es 0\n\n";
		cout<<"\n--------------------------------------------------------\n";
		system("pause");
		return 0;
	}
	
	
	if(modoSilencioso==false){
	
		cout<<"\n\tA^(-1)= ( Adj (A)Transpuesta ) : ( DeterminanteDe(A) )\n";
		cout<<"\n El determinante de A es: \n\n";
		for (int i=0;i<nFilas;i++){
			
			cout<<"| ";
			for(int j=0;j<nCol;j++){
				cout<<*(*(matriz_inversa+i)+j)<<" | ";
			}
			
			cout<<"\n";
		}
		cout<<"\n";
		system("pause");
	
	}
	
	if(devolverMatriz==true){
		
		for (int i=0;i<nFilas;i++){
			for(int j=0;j<nCol;j++){
				
				*(*(matriz_objetivo+j)+i) = *(*(matriz_inversa+j)+i);
							
			}
		}
		
	}
	
	
	delete[] matriz_inversa;
	delete[] matriz_transpuesta2;
	delete[] matriz_adjunta2;
	return 0;
	
}
