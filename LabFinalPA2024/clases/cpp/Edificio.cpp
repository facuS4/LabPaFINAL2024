#include "../h/Edificio.h"

// Default constructor
Edificio::Edificio() : nombre(""), cantPisos(0), gastosComunes(0.0f) {}

// Constructor with parameters
Edificio::Edificio(string nombreEdificio, int cantidadPisos, float costoGastosComunes) :
  nombre(nombreEdificio), cantPisos(cantidadPisos), gastosComunes(costoGastosComunes) {}

// Destructor (assuming no custom logic needed)
Edificio::~Edificio() = default;

// Getter and Setter methods
string Edificio::getNombre() {
  return nombre;
}

void Edificio::setNombre(string nombreEdificio) {
  nombre = nombreEdificio;
}

int Edificio::getCantPisos() {
  return cantPisos;
}

void Edificio::setCantPisos(int cantidadPisos) {
  cantPisos = cantidadPisos;
}

float Edificio::getGastosComunes() {
  return gastosComunes;
}

void Edificio::setGastosComunes(float costoGastosComunes) {
  gastosComunes = costoGastosComunes;
}

// Method to desvincular a Propiedad (assuming a collection is maintained)
void Edificio::desvincularPropiedad(string codigoPropiedad) {
  // Implement logic to remove the propiedad identified by codigoPropiedad from the Edificio's collection
  // This might involve iterating through a List or other collection and removing the matching propiedad
  // You'll likely need to include Propiedad.h for propiedad access
}

// Optional methods for Edificio specific functionalities (replace with your logic)
// dtEdificio getEdificioDt(); // Assuming a method to create a dtEdificio object

// ... other methods for managing Edificio properties or functionalities
