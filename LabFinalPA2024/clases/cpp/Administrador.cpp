#include "../h/Administrador.h"

// Default constructor
Administrador::Administrador() : Usuario() {}

// Constructor with parameters (can inherit from Usuario's constructor)
Administrador::Administrador(string email, string password) : Usuario(email, password){
}

// Destructor (assuming no custom logic needed)
Administrador::~Administrador() {};

// Override Asociar method (optional functionality for Administrador)
void Administrador::Asociar(Conversacion *c){
  // Implement logic for Administrador to associate with a Conversacion (optional)
  // This might involve storing a reference to the conversation for tracking purposes
  // Or it might not be relevant for Administrador to directly associate with conversations
}
