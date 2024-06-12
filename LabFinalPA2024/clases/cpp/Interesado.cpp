#include "../h/Interesado.h"

Interesado::Interesado() : Usuario() {
  nombre = "";
  edad = 0;
  apellido = "";
}

Interesado::Interesado(string email, string password, string nombreUsuario, int edadUsuario, string apellidoUsuario) : Usuario(email, password) {
  nombre = nombreUsuario;
  edad = edadUsuario;
  apellido = apellidoUsuario;
}

// Destructor (assuming no custom logic needed)
Interesado::~Interesado() {
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
void Interesado::Asociar(Conversacion *c){
  c->~Conversacion();
}

void Interesado::Desvincular(Conversacion *c){
    c->~Conversacion();

}
