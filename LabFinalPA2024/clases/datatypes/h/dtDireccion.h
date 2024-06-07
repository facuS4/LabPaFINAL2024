#ifndef DTDIRECCION_H
#define DTDIRECCION_H
#include <iostream>

using namespace std;

class dtDireccion{

	private:
		string pais;
		string ciudad;
		string numero;
		string calle;
	public:
		//Constructor
		dtDireccion();
		dtDireccion(string, string, string, string);
		//Getter
		string getPais();
		string getCiudad();
		string getNumero();
		string getCalle();

		//Funciones

		//Sobrecarga


};

#endif //DTDIRECCION_H

// prueba commit