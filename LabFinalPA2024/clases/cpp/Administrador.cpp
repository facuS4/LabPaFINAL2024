#include "../h/Administrador.h"

// Default constructor
Administrador::Administrador() : Usuario() {}

// Constructor with parameters (can inherit from Usuario's constructor)
Administrador::Administrador(string email, string password) : Usuario(email, password){
  email = email;
  password = password;
}

// Destructor (assuming no custom logic needed)
Administrador::~Administrador() {};

//ESTO ES UN DUMMY
void Administrador::Asociar(Conversacion *c){
  c->~Conversacion();
  //IMPLEMENTAR LOGICA
}
