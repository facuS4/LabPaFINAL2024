#include "dtDireccion.h"

dtDireccion::dtDireccion(){
    this->pais = nullptr;
    this->ciudad = nullptr;
    this->numero = nullptr;
    this->calle = nullptr;
}


dtDireccion::dtDireccion(string _pais, string _ciudad, string _numero, string _calle){
    this->pais = _pais;
    this->ciudad = _ciudad;
    this->numero = _numero;
    this->calle = _calle;
}

string dtDireccion::getPais(){
    return this->pais;
}

string dtDireccion::getCiudad(){
    return this->ciudad;
}

string dtDireccion::getNumero(){
    return this->numero;
}

string dtDireccion::getCalle(){
    return this->calle;
}
