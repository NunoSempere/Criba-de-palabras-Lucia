#include <iostream>
#include <fstream>
#include <string>
using std::cout;


using namespace std;

int tienetodosloscaracteres(string palabra, string caracteresquebuscamos,bool control1){
	
	if(control1==false){
		return true;
	}
	bool tienetodosloschar = true;
	bool estalaletrai;
	
	for(int i = 0; i < caracteresquebuscamos.length(); i++) {
		estalaletrai = false;
		for (int j = 0; j<palabra.length();j++){
			if (palabra[j] == caracteresquebuscamos[i]){
				estalaletrai=true;
			}
		}
		
		if (estalaletrai==false){
			tienetodosloschar =false;
		}
	}
	
	return tienetodosloschar;
}

int limitadoalasletras(string palabra, string caracteresquebuscamos, bool control2){
	
	if(control2==false){
		return true;
	}
	
	bool limitadoaloschar = true;
	bool compuestoporalgunaletrai;
	
	for(int i = 0; i < palabra.length(); i++) {
		compuestoporalgunaletrai = false;
		for (int j = 0; j< caracteresquebuscamos.length();j++){
			if (palabra[i] == caracteresquebuscamos[j]){
				compuestoporalgunaletrai=true;
			}
		}
		
		if (compuestoporalgunaletrai==false){
			limitadoaloschar =false;
		}
	}
	
	return limitadoaloschar;
	
}

int comienzapor(string palabra, string comienzo, bool control3){
	
	if(control3==false){
		return true;
	}
	
	bool comienzapor=true;
	for(int i =0; i<comienzo.length(); i++){ // lo mismo que i<= comienzo.lenght()-1
		if (palabra[i] != comienzo[i]){
			comienzapor = false;
		}
	}
	
	return comienzapor;
}

int terminapor(string palabra, string terminacion, bool control4){
	
	if(control4==false){
		return true;
	}
		
	bool terminapor=true;
	
	int longituddelaterminacion=terminacion.length();
	int longitudelapalabra = palabra.length();
	
	for(int i =0; i<longituddelaterminacion; i++){
		if (palabra[longitudelapalabra-longituddelaterminacion+i] != terminacion[i]){
			terminapor = false;
		}
	}
	
	return terminapor;
	
	
}

int entreinfysup(string palabra, int inf, int sup, bool control5){
	if(control5==false){
		return true;
	}
	
	return (inf<=palabra.length() && palabra.length()<=sup);

}

int main() {

	cout<< "Achtung! Achtung! El programa se volverá loco si no introduces inputs adecuados"<<endl<<endl;

	ifstream fin;
	
	string filename;
	string palabra;

	bool Existenimprescindibles;
	string caracteresnecesarios; //Nota, no el lo mismo que caracteresquebuscamos. La segunda es un parámetro de una función, la primera una variable.

	bool Eslimitado;
	string limitadoa;
	
	bool Acotado;
	int inferior;
	int superior;
	
	bool Comienzaporalgo;
	string comienzaporesto;
	
	bool Terminaporalgo;
	string terminaporesto;
	
	char mi_caracter;
	
	bool Palabraaimprimir;

	
	cout<<"Escribe el nombre del fichero. No te olvides del .algo (.txt) "<<endl;
	cin>>filename;

	fin.open(filename.c_str(), ios::in);
	
	while(fin.fail())
	{
	    fin.clear();
	    cout<<"Error. Escribe el nombre del fichero. No te olvides del .algo (.txt) "<<endl;
	    cin>>filename;
	    fin.open(filename.c_str(), ios::in);
	}
	
	cout<<"Hay algún caracter imprescindible? 0=No, 1=Si"<<endl;
	cin>>Existenimprescindibles;

	
	if(Existenimprescindibles==1){
		cout <<"Son imprescindibles los caracteres..."<<endl;
		cin>>caracteresnecesarios;		
		
	}

	//while (cin.fail()){
	//	cin.clear();
	//}

	cout<<"Está limitado a un conjunto de letras? 0=No, 1=Si"<<endl;
	cin>>Eslimitado;
	
	
	if(Eslimitado==1){
		cout <<"Está limitado a..."<<endl;
		cin>>limitadoa;	
		
	}	
	
	cout<<"Está la longitud acotada? 0=No, 1=Si"<<endl;
	cin>>Acotado;
	
	if(Acotado==1){
		cout <<"Acotada inferiormente por x>=... "<<endl;
		cin>>inferior;	
		cout <<"Acotada superiormente por x<=... "<<endl;
		cin>>superior;			
		
	}
	
	cout << "Quieres determinar el comienzo de tu palabra? 0=No, 1=Sí"<<endl;
	cin>>Comienzaporalgo;
	
	if(Comienzaporalgo==1){
		cout<<"Comienza por..."<<endl;
		cin>>comienzaporesto;
	}
	
	cout << "Quieres determinar el fin de tu palabra? 0=No, 1=Sí"<<endl;
	cin>>Terminaporalgo;
	
	if(Terminaporalgo==1){
		cout<<"Termina por..."<<endl;
		cin>>terminaporesto;
	}
	
	while (fin.good() ) { // http://www.cplusplus.com/reference/ios/ios/good/ No solo cesa cuando llega al final del fichero, sino también cuando da un error.
		
		fin.get(mi_caracter);
		
				
		if (mi_caracter != '\n'){ 		
			palabra = palabra + mi_caracter;
		}

	
		if(mi_caracter == '\n'){
			
			if (limitadoalasletras(palabra, limitadoa, Eslimitado) 
			&& tienetodosloscaracteres(palabra, caracteresnecesarios, Existenimprescindibles) 
			&& entreinfysup(palabra, inferior, superior, Acotado) 
			&& comienzapor(palabra, comienzaporesto, Comienzaporalgo) 
			&& terminapor(palabra, terminaporesto, Terminaporalgo) ){
	
				cout<<"Nueva palabra: "<<palabra<<endl;			
			
			}
				palabra="";
		}
						
		

	}
	
	system("pause"); // solo funciona en Windows
	
}
