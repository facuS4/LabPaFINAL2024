#ifndef DTDEPARTAMENTO_H
#define DTDEPARTAMENTO_H
#include <iostream>

using namespace std;

class dtDepartamento{

	private:
		string nombre;
        char letraDpto;
	public:
        //Constructor
        dtDepartamento();
        dtDepartamento(string, char);
        //Getter
        string getNombre();
        char getLetraDpto();

        //Funciones

        //Sobrecarga


};

#endif //DTDEPARTAMENTO_H

// prueba commit