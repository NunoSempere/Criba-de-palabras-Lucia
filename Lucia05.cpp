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

int entreinfysup(string palabra, int inf, int sup, bool control3){
	if(control3==false){
		return true;
	}
	
	return (inf<=palabra.length() && palabra.length()<=sup);

}

int main() {

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
	
	char mi_caracter;
	
	bool Palabraaimprimir;

	
	cout<<"Enter the file name"<<endl;
	cin>>filename;

	fin.open(filename.c_str(), ios::in);
	
	while(fin.fail())
	{
	    fin.clear();
	    cout<<"Incorrect filename, please enter again"<<endl;
	    cin>>filename;
	    fin.open(filename.c_str(), ios::in);
	}
	
		cout<<"Hay algún caracter imprescindible? 0=No, 1=Si"<<endl;
	cin>>Existenimprescindibles;
	
	if(Existenimprescindibles==1){
		cout <<"Son imprescindibles los caracteres..."<<endl;
		cin>>caracteresnecesarios;	
		
	}


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
	
	
	
	while (fin.good() ) { // http://www.cplusplus.com/reference/ios/ios/good/ No solo cesa cuando llega al final del fichero, sino también cuando da un error.
		
		fin.get(mi_caracter);
		
				
		if (mi_caracter != '\n'){ 		
			palabra = palabra + mi_caracter;
		}

		if (mi_caracter == '\n'){ 		
			
			Palabraaimprimir = limitadoalasletras(palabra, limitadoa,Eslimitado)*tienetodosloscaracteres(palabra, caracteresnecesarios,Existenimprescindibles)*entreinfysup(palabra, inferior, superior, Acotado);
			
			if(Palabraaimprimir){
				cout<<"Nueva palabra: "<<palabra<<endl;
			}
			
			palabra="";
		}		

	}
	
}
