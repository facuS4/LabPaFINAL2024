#include "../h/Mensaje.h"

// Default constructor
Mensaje::Mensaje() : fecha(dtFecha()), texto("") {}

// Constructor with parameters
Mensaje::Mensaje(dtFecha fecha, string texto) : fecha(fecha), texto(texto) {}

// Destructor (assuming no custom logic needed)
Mensaje::~Mensaje() = default;

// Getter methods
dtFecha Mensaje::getFecha() {
  return fecha;
}

string Mensaje::getTexto() {
  return texto;
}

// Setter methods
void Mensaje::setFecha(dtFecha nuevaFecha) {
  fecha = nuevaFecha;
}

void Mensaje::setTexto(string nuevoTexto) {
  texto = nuevoTexto;
}
