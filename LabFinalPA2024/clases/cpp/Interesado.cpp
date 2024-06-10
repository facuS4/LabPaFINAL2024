#include "Interesado.h"

// Default constructor
Interesado::Interesado() : Usuario(), nombre(""), edad(0), apellido(""), conversaciones(new List<Conversacion>()) {}

// Constructor with parameters
Interesado::Interesado(string nombreUsuario, string apellidoUsuario, int edadUsuario, string emailUsuario) :
  Usuario(emailUsuario, ""), nombre(nombreUsuario), edad(edadUsuario), apellido(apellidoUsuario), conversaciones(new List<Conversacion>()) {}

// Destructor (assuming no custom logic needed)
Interesado::~Interesado() {
  delete conversaciones; // Deallocate the dynamically allocated collection
}

// Getter and Setter methods for nombre, apellido, and edad
string Interesado::getNombre() {
  return nombre;
}

void Interesado::setNombre(string nombreUsuario) {
  nombre = nombreUsuario;
}

string Interesado::getApellido() {
  return apellido;
}

void Interesado::setApellido(string apellidoUsuario) {
  apellido = apellidoUsuario;
}

int Interesado::getEdad() {
  return edad;
}

void Interesado::setEdad(int edadUsuario) {
  edad = edadUsuario;
}

// Implementations for pure virtual methods inherited from Usuario
void Interesado::Asociar(Conversacion c) override {
  conversaciones->add(c); // Add the Conversacion to the collection
}

void Interesado::Desvincular(Conversacion c) override {
  conversaciones->remove(c); // Remove the Conversacion from the collection
}
