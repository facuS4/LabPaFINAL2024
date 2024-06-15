
#include "../h/Alquiler.h"

Alquiler::Alquiler() : precioAlquiler(0.0f), p(nullptr) {}

Alquiler::Alquiler(float precio) : precioAlquiler(precio) {}

Alquiler::~Alquiler() {
  this->p = nullptr;
};

float Alquiler::getPrecioAlquiler() {
  return precioAlquiler;
}

void Alquiler::setPrecioAlquiler(float nuevoPrecio) {
  precioAlquiler = nuevoPrecio;
}

void Alquiler::setPropiedad(Propiedad * pp){

  this->p=pp;

}

Propiedad * Alquiler::getPropiedad(){

  return this->p;
}


//ESTO ES UN DUMMY
void Alquiler::desvincualarAlquiler(string codigo) {
  cout << codigo;
  // IMPLEMENTAR LOGICA
}
