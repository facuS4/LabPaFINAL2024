
#include "Alquiler.h"

// Default constructor
Alquiler::Alquiler() : precioAlquiler(0.0f) {}

// Constructor with parameter (assuming price is passed)
Alquiler::Alquiler(float precio) : precioAlquiler(precio) {}

// Destructor (assuming no custom logic needed)
Alquiler::~Alquiler() = default;

// Getter and Setter methods for precioAlquiler
float Alquiler::getPrecioAlquiler() {
  return precioAlquiler;
}

void Alquiler::setPrecioAlquiler(float nuevoPrecio) {
  precioAlquiler = nuevoPrecio;
}

// Method to desvincular the alquiler (replace with your logic)
void Alquiler::desvincularAlquiler(string codigoPropiedad) {
  // Implement logic to potentially remove association with a Propiedad identified by 'codigoPropiedad'
  // This might involve updating the related Propiedad or other entities
}
