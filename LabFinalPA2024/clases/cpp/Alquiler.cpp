
#include "../h/Alquiler.h"

// Default constructor
Alquiler::Alquiler() : precioAlquiler(0.0f) {}

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

void Alquiler::desvincualarAlquiler(string codigo) {
  // Implement logic to disassociate Alquiler from a property
  // This might involve removing the Alquiler from the property's list of Alquiler objects
  // Or it might involve setting the property's Alquiler reference to null
  // The specific implementation will depend on the design of the system
}
