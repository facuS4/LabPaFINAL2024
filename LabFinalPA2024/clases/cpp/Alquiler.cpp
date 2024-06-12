
#include "../h/Alquiler.h"

// Default constructor
Alquiler::Alquiler() : precioAlquiler(0.0f), p(nullptr) {}

// Constructor with parameter (assuming price is passed)
Alquiler::Alquiler(float precio) : precioAlquiler(precio) {}

// Destructor (assuming no custom logic needed)
Alquiler::~Alquiler() {};

// Getter and Setter methods for precioAlquiler
float Alquiler::getPrecioAlquiler() {
  return precioAlquiler;
}

void Alquiler::setPrecioAlquiler(float nuevoPrecio) {
  precioAlquiler = nuevoPrecio;
}

void Alquiler::setPropiedad(Propiedad * pp){

  this->p=pp;

}



//ESTO ES UN DUMMY
void Alquiler::desvincualarAlquiler(string codigo) {
  cout << codigo;
  // IMPLEMENTAR LOGICA
}
