/**LIBRERIAS**/
#include <iostream>
#include <stdlib.h>

#include <cmath>
//(Solo para usar "pow")


/**DECLARACIONES**/
using namespace std;

/**PROTOTIPOS DE FUNCION**/
int calcularadjunta(int **,int,int,bool,bool,int **);

/**PROTOTIPOS**/
int **matriz_adjunta;
int **matriz_adjunta_auxiliar;
int **matriz_adjunta_auxiliar2x2;


/**FUNCIONES**/

int calcularAdjunta(int **matriz_transpuesta,int nFilas,int nCol,bool modoSilencioso, bool devolverMatriz, int **matriz_objetivo){
	
	int aux_determinante=0;
	int power=0;
	
	
	/**-----------------------------------------------------------------------------------**/
	/**GUARDAR ESPACIO EN MEMORIA**/
	//Guardar espacio en memoria para la matriz "matriz_adjunta"
	matriz_adjunta = new int*[nFilas];
	for (int i=0;i<nFilas;i++){
		matriz_adjunta[i] = new int[nCol];
		
	}
	
	//Guardar espacio en memoria para la matriz "matriz_adjunta_auxiliar"
	matriz_adjunta_auxiliar = new int*[nFilas];
	for (int i=0;i<nFilas;i++){
		matriz_adjunta_auxiliar[i] = new int[nCol];
		
	}
	
	//Guardar espacio en memoria para la matriz auxiliar 2
	matriz_adjunta_auxiliar2x2 = new int*[2];
	for (int i=0;i<2;i++){
		matriz_adjunta_auxiliar2x2[i] = new int[2];
		
	}
	/**-----------------------------------------------------------------------------------**/
	
	//Se trabaja con "matriz_adjunta_auxiliar"
	for(int k=0;k<nFilas;k++){
		for(int m=0;m<nCol;m++){
				
			*(*(matriz_adjunta_auxiliar+m)+k) = *(*(matriz_transpuesta+m)+k);
			
		}
	}
	


	//Rellenar la matriz "matriz_adjunta" con 0 para quitar cualquier valor basura
	for(int k=0;k<nFilas;k++){
		for(int m=0;m<nCol;m++){
			
			*(*(matriz_adjunta+m)+k) = 0;
			
		}
	}
	
	
	//Calcular y guardar la adjunta de la matriz transpuesta
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nCol;j++){
			
			power=pow( (-1) , (j+1+i+1) );
			
			//"Tachar" la fila y columna correspondiente
			for(int k=0;k<nFilas;k++){
				for(int m=0;m<nCol;m++){
					
					if(k==i || m==j){
						

						*(*(matriz_adjunta_auxiliar+k)+m) = 2147483646;

						
					}
				}
			}
			system("cls");
			cout<<"\n\nSe han tachado los numeros..\n";
			mostrarMatriz(matriz_adjunta_auxiliar,nFilas,nCol);
			
			
			//Rellenar la matriz de 2x2 auxiliar
			int aux=0;
			//mostrarMatriz(matriz_adjunta_auxiliar,nFilas,nCol);
			for(int k=0;k<nCol;k++){
				for(int m=0;m<nFilas;m++){
					
					if(  *(*(matriz_adjunta_auxiliar+k)+m) != 2147483646  ){
						
						if(aux==0){
							*(*(matriz_adjunta_auxiliar2x2+0)+0) = 
							*(*(matriz_adjunta_auxiliar+k)+m);
							aux++;
						} else if(aux==1){
							*(*(matriz_adjunta_auxiliar2x2+1)+0) = 
							*(*(matriz_adjunta_auxiliar+k)+m);
							aux++;
						} else if(aux==2){
							*(*(matriz_adjunta_auxiliar2x2+0)+1) = 
							*(*(matriz_adjunta_auxiliar+k)+m);
							aux++;
						} else {
							*(*(matriz_adjunta_auxiliar2x2+1)+1) = 
							*(*(matriz_adjunta_auxiliar+k)+m);
							aux++;
						}
						
					}
				
				}
				
			}
			
			
			//Conseguir el determinante de la matriz "matriz_adjunta_auxiliar2x2"
			aux_determinante = calcularDeterminante(matriz_adjunta_auxiliar2x2, 2, 2,true);
			
			
			//Calculos finales
			*(*(matriz_adjunta+i)+j) = (  power * aux_determinante  );
			cout<<endl
				<<"ADJ(A)="
				<<"(-1)^("<<i+1<<"+"<<j+1<<")"
				<<" * "
				<<"DeterminanteDe(B)"
				<<" = "
				<<*(*(matriz_adjunta+i)+j)
				<<"\n\n---------------------------------------------\n\n";
				
			cout<<"La matriz B(2x2) es: \n";
			mostrarMatriz(matriz_adjunta_auxiliar2x2,2,2);
			cout<<"y su determinante es: "<<aux_determinante<<endl;
			
			cout<<"\n\n---------------------------------------------\n\n";
			mostrarMatriz(matriz_adjunta,nFilas,nCol);
			cout<<"---------------------------------------------\n";
			
			system("pause");
			


			
			//Reiniciar la matriz auxiliar
			for(int k=0;k<nFilas;k++){
				for(int m=0;m<nCol;m++){
					
					*(*(matriz_adjunta_auxiliar+k)+m) = *(*(matriz_transpuesta+k)+m);
				}
			}
			//Reiniciar la matriz auxiliar de 2x2
			for(int k=0;k<2;k++){
				for(int m=0;m<2;m++){
					
					*(*(matriz_adjunta_auxiliar2x2+k)+m) = 0;
				}
			}
			
			
		}
	}
	
	//Mostrar en pantalla la matriz adjunta
	if(modoSilencioso==false){
		
		system("cls");
		cout<<"\n\n\n\tLa adjunta de A es: \n\n";
		mostrarMatriz(matriz_adjunta,nFilas,nCol);
		system("pause");
		
	}
	
	
	
	if(devolverMatriz==true){
		
		for(int k=0;k<nFilas;k++){
			for(int m=0;m<nCol;m++){
				
				*(*(matriz_objetivo+k)+m) = *(*(matriz_adjunta+k)+m);
			}
		}
		
	}
	
	//FIN del programa xd
	delete[] matriz_adjunta_auxiliar;
	delete[] matriz_adjunta_auxiliar2x2;
	delete[] matriz_adjunta;


}
