
/**LIBRERIAS**/
#include <iostream>
#include <stdlib.h>

//#include <SANITASE_INPUT.cpp>

/**DECLARACIONES**/
using namespace std;

/**PROTOTIPOS DE FUNCION**/
int calcularDeterminante(int **,int,int,bool);



/**FUNCIONES**/

//NOTA: Siempre retorna el determinante.
int calcularDeterminante(int **matriz,int nFilas,int nCol,bool modoSilencioso){
	
	bool modoGrafico=false;
	int primeraDiagonal=0,trianguloSuperiorUno=0,trianguloInferiorUno=0;
	int segundaDiagonal=0,trianguloSuperiorDos=0,trianguloInferiorDos=0;
	int determinante=0;
	
	
	if(modoSilencioso==false){
		cout<<"Desea que el calculo del determinante sea grafico? ( 1=\"si\" / 0=\"no\"): ";
		modoGrafico=getBoolNumber();
	}

	
	if(modoGrafico==true){
		
		//Se calcula el determinante en el modo GRAFICO
		
		if(nCol==3 && nFilas==3){
			
			cout<<"\tMatriz de 3x3 detectada."<<endl
				<<"\tUtilizando el metodo de Sarrus...\n\n";
				
			
			//Se calcula el determinante utilizando el metodo de Sarrus...
			
			//Se calcula la primera diagonal
			primeraDiagonal=(  
				*(*(matriz+0)+0)  *  
				*(*(matriz+1)+1)  *  
				*(*(matriz+2)+2)  
			);
			
			cout<< "Primera Diagonal: \n\t"
				<< *(*(matriz+0)+0) <<" * "
				<< *(*(matriz+1)+1) <<" * "
				<< *(*(matriz+2)+2) <<" = "
				<<primeraDiagonal<<"\n\n";
			
			
			//Se calcula el triangulo superior uno
			trianguloSuperiorUno=(  
				*(*(matriz+0)+1)  *  
				*(*(matriz+1)+2)  *  
				*(*(matriz+2)+0)  
			);
			
			cout<<"Triangulo Superior Uno: \n\t"
				<< *(*(matriz+0)+1) <<" * "
				<< *(*(matriz+1)+2) <<" * "
				<< *(*(matriz+2)+0) <<" = "
				<<trianguloSuperiorUno<<"\n\n";
			
			
			//Se calcula el triangulo inferior uno
			trianguloInferiorUno=(  
				*(*(matriz+1)+0)  *  
				*(*(matriz+2)+1)  *  
				*(*(matriz+0)+2)  
			);
			
			cout<<"Triangulo Inferior Uno: \n\t"
				<< *(*(matriz+1)+0) <<" * "
				<< *(*(matriz+2)+1) <<" * "
				<< *(*(matriz+0)+2) <<" = "
				<<trianguloInferiorUno<<"\n\n";
			
			
			//Se calcula la SEGUNDA diagonal
			segundaDiagonal=(  
				*(*(matriz+0)+2)  *  
				*(*(matriz+1)+1)  *  
				*(*(matriz+2)+0)  
			);
				
			cout<<"Segunda Diagonal: \n\t"
				<< *(*(matriz+0)+2) <<" * "
				<< *(*(matriz+1)+1) <<" * "
				<< *(*(matriz+2)+0) <<" = "
				<<segundaDiagonal<<"\n\n";

			
			//Se calcula el triangulo superior dos
			trianguloSuperiorDos=(  
				*(*(matriz+1)+0)  *  
				*(*(matriz+0)+1)  *  
				*(*(matriz+2)+2)  
			);
			
			cout<<"Triangulo Superior Dos: \n\t"
				<< *(*(matriz+1)+0) <<" * "
				<< *(*(matriz+0)+1) <<" * "
				<< *(*(matriz+2)+2) <<" = "
				<<trianguloSuperiorDos<<"\n\n";
			
			
			//Se calcula el triangulo inferior dos
			trianguloInferiorDos=(  
				*(*(matriz+2)+1)  *  
				*(*(matriz+1)+2)  *  
				*(*(matriz+0)+0)  
			);
			
			cout<<"Triangulo Inferior Dos: \n\t"
				<< *(*(matriz+2)+1) <<" * "
				<< *(*(matriz+1)+2) <<" * "
				<< *(*(matriz+0)+0) <<" = "
				<<trianguloInferiorDos<<"\n\n";
	
			
			
			//Se calcula el DETERMINANTE
			determinante = (  
				primeraDiagonal + 
				trianguloSuperiorUno + 
				trianguloInferiorUno - 
				segundaDiagonal - 
				trianguloSuperiorDos - 
				trianguloInferiorDos  
			);
			
			
			cout<<"\n\n\t\tEl determinante de la matriz ingresada es: "<<determinante<<endl;
			system("pause");
			
			
			
		} else if(nCol==2 && nFilas==2){
			
			determinante=(
				*(*(matriz+0)+0)  *  *(*(matriz+1)+1) +
				*(*(matriz+0)+1)  *  *(*(matriz+1)+0)
			);
			
			cout<<" ( "<< *(*(matriz+0)+0) <<" ) * ("
				<< *(*(matriz+1)+1) <<") + ("
				<< *(*(matriz+0)+1) <<") * ("
				<< *(*(matriz+1)+0) <<") = "
				<< determinante<<endl;
			
		} else {
			
			cout<<"\n\tLastimosamente actualmente no hay ningun metodo disponible actualmente para calcular "
				<<"matrizes de "<<nFilas<<"x"<<nCol<<" :( \n\n";
				system("pause");
			
		}
		
		
	} else {
		
		//Se calcula el determinante en el modo NO GRAFICO
		
		if(nCol==3 && nFilas==3){
			
			
			//Se calcula la primera diagonal
			primeraDiagonal=(  
				*(*(matriz+0)+0)  *  
				*(*(matriz+1)+1)  *  
				*(*(matriz+2)+2)  
			);
			//Se calcula el triangulo superior uno
			trianguloSuperiorUno=(  
				*(*(matriz+0)+1)  *  
				*(*(matriz+1)+2)  *  
				*(*(matriz+2)+0)  
			);
			//Se calcula el triangulo inferior uno
			trianguloInferiorUno=(  
				*(*(matriz+1)+0)  *  
				*(*(matriz+2)+1)  *  
				*(*(matriz+0)+2)  
			);
			
			//Se calcula la SEGUNDA diagonal
			segundaDiagonal=(  
				*(*(matriz+0)+2)  *  
				*(*(matriz+1)+1)  *  
				*(*(matriz+2)+0)  
			);
			//Se calcula el triangulo superior dos
			trianguloSuperiorDos=(  
				*(*(matriz+1)+0)  *  
				*(*(matriz+0)+1)  *  
				*(*(matriz+2)+2)  
			);
			//Se calcula el triangulo inferior dos
			trianguloInferiorDos=(  
				*(*(matriz+2)+1)  *  
				*(*(matriz+1)+2)  *  
				*(*(matriz+0)+0)  
			);
			
			//Se calcula el DETERMINANTE
			determinante = (  
				primeraDiagonal + 
				trianguloSuperiorUno + 
				trianguloInferiorUno - 
				segundaDiagonal - 
				trianguloSuperiorDos - 
				trianguloInferiorDos  
			);
			
			cout<<"\n\n\t\tEl determinante de la matriz ingresada es: "<<determinante<<endl;
			
			if(modoSilencioso==true){
				return determinante;
			}
			
		} else if(nCol==2 && nFilas==2){
			
			determinante=(
				*(*(matriz+0)+0)  *  *(*(matriz+1)+1) -
				*(*(matriz+0)+1)  *  *(*(matriz+1)+0)
			);
			
			
		} else {
			cout<<"\n\tLastimosamente actualmente no hay ningun metodo disponible actualmente para calcular "
				<<"matrizes de "<<nFilas<<"x"<<nCol<<" :( \n\n";
			system("pause");
			
		}
		
		
	}
	
	return determinante;
}

