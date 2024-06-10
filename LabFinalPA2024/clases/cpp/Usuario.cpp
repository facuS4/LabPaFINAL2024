#include "../h/Usuario.h"

// Default constructor
Usuario::Usuario() : CorreoElectronico(""), Contrasenia("") {}

// Constructor with parameters
Usuario::Usuario(string email, string password){
  CorreoElectronico = email;
  Contrasenia = password;
}

// Destructor (assuming no custom logic needed)
Usuario::~Usuario(){};

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

