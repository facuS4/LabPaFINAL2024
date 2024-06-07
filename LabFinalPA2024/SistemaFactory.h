#ifndef SISTEMAFACTORY_H
#define SISTEMAFACTORY_H

#include "ISistema.h"
#include "Sistema.h"
#include <iostream>
#include <string.h>

using namespace std;

class SistemaFactory{
	private:
		static SistemaFactory * instancia;
		SistemaFactory();
	public:
		static ISistema * crearSistema();
		static SistemaFactory * getInstancia();
		virtual ~SistemaFactory();
};

#endif