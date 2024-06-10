#include "Venta.h"

// Default constructor
Venta::Venta() : precioVenta(0.0f) {}

// Constructor with parameter
Venta::Venta(float precio) : precioVenta(precio) {}

// Destructor (assuming no custom logic needed)
Venta::~Venta() = default;

// Getter and Setter methods for precioVenta
float Venta::getPrecioVenta() {
  return precioVenta;
}

void Venta::setPrecioVenta(float nuevoPrecio) {
  precioVenta = nuevoPrecio;
}

// Method to desvincular a Venta (replace with your logic)
void Venta::desvincularVenta(string codigoPropiedad) {
  // Implement logic to potentially remove association with a Propiedad identified by 'codigoPropiedad'
  // This might involve:
  //  - Updating the related Propiedad to indicate it's no longer en venta
  //  - Removing the Venta from a collection of ventas associated with the Propiedad (if applicable)
  //  - Notifying other interested parties (optional)
}
