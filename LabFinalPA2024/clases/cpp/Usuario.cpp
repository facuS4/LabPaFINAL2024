#include "Usuario.h"

// Default constructor
Usuario::Usuario() : CorreoElectronico(""), Contrasenia("") {}

// Constructor with parameters
Usuario::Usuario(string email, string password) : CorreoElectronico(email), Contrasenia(password) {}

// Destructor (assuming no custom logic needed)
Usuario::~Usuario() = default;

// Getter and Setter methods
string Usuario::getCorreoElectronico() {
  return CorreoElectronico;
}

void Usuario::setCorreoElectronico(string email) {
  CorreoElectronico = email;
}

string Usuario::getContrasenia() {
  return Contrasenia;
}

void Usuario::setContrasenia(string password) {
  Contrasenia = password;
}

// Implementation for the pure virtual method (assuming a collection is maintained)
void Usuario::Asociar(Conversacion c) override {
  // Implement logic to add the Conversacion 'c' to the user's collection
  // This might involve using a List or other collection to store associated Conversacion objects
  // You'll likely need to include Conversacion.h for access
}
