/**LIBRERIAS**/
#include <iostream>
#include <limits>


/**DECLARACIONES**/
using namespace std;


/**PROTOTIPOS DE FUNCION**/
bool getBoolNumber();
double getDoubleNumber();
float getFloatNumber();
int getIntNumber();


//Sanitases the input for BOOLs
//On failure to sanitise the input, returns FALSE.
bool getBoolNumber(){
	
	bool num=false;
	
	cout<<flush;
	cin.clear();
	
	cin>>num;
	
	if (cin.fail()) {
		//cerr<<"\n\tSorry, I cannot read that. Please try again."<<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    } else {
       	return num;
    }
    
}

//Sanitases the input for FLOATs
//On failure to sanitise the input, returns NULL.
//TESTING TIP:  1.40239846e–45f  |  3.40282347e+38f
float getFloatNumber(){
	
	float num=0;
	
	cout<<flush;
	cin.clear();
	
	cin>>num;
	
	if (cin.fail()) {
        //cerr<<"\n\tSorry, I cannot read that. Please try again."<<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return NULL;
    } else {
       	return num;
    }
    
}

//Sanitases the input for DOUBLEs
//On failure to sanitise the input, returns NULL.
//TESTING TIP:   4.94065645841246544e–324d   |   1.7976931348623157e+308d  
double getDoubleNumber(){
	
	double num=0;
	
	cout<<flush;
	cin.clear();
	
	cin>>num;
	
	if (cin.fail()) {
        //cerr<<"\n\tSorry, I cannot read that. Please try again."<<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return NULL;
    } else {
       	return num;
    }
    
}

//Sanitases the input for INTegers
//On failure to sanitise the input, returns NULL.
//TESTING TIP: Maximum posible value: 2147483647  |  -2147483648
int getIntNumber(){
	
	int num=1;
	
	cout<<flush;
	cin.clear();
	
	cin>>num;
	
	if (cin.fail()) {
        //cerr<<"\n\tSorry, I cannot read that. Please try again."<<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return NULL;
    } else {
       	return num;
    }
    
}
