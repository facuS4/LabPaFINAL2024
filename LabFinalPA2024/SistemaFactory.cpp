#include "SistemaFactory.h"
#include <iostream>

using namespace std;

// Constructor
SistemaFactory::SistemaFactory(){};

SistemaFactory * SistemaFactory::instancia = 0;

SistemaFactory * SistemaFactory::getInstancia(){
    if (instancia == 0){
        instancia = new SistemaFactory();
    }
    return instancia;
}

ISistema * SistemaFactory::crearSistema(){
    return Sistema::getInstancia();
}

// Destructor
SistemaFactory::~SistemaFactory(){};