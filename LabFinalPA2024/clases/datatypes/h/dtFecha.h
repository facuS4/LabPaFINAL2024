#ifndef DTFECHA_H
#define DTFECHA_H
#include <iostream>
#include <ctime>

using namespace std;

class dtFecha {

	private:
		int dia;
		int mes;
		int anio;
	
	public:
		//Constructores
		dtFecha();
		dtFecha(int dia, int mes, int anio);
		//Getters
		int getDia();
		int getMes();
		int getAnio();
		
		//Funciones

		//Sobrecarga

};


#endif //DTFECHA_H
