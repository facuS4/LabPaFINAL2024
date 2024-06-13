#include "../h/Conversacion.h"

// Default
//Conversacion::Conversacion() : mensajes(new List()), inmobiliarias(new List()) {}
Conversacion::Conversacion(){
    mensajes = new List();
    inmobiliaria = nullptr;
    interesado = nullptr;
}

Conversacion::~Conversacion() {
  delete mensajes;
 // delete inmobiliarias;
}

// Removes links to other entities
void Conversacion::eliminarVinculosConversacion() {
  // Implement logic to remove any links to other entities (e.g., usuarios, propiedades)
  // This might involve updating related entities or removing references in the collections
}

// Adds a message to the conversation
void Conversacion::AgregarMensaje(Mensaje * mensaje) {
    mensajes->add(mensaje);

}

// Creates a message with an author
void Conversacion::CrearMensaje(string mensaje, Usuario *u) {
    cout << mensaje;
    u->~Usuario();
}

Interesado * Conversacion::getInteresado() {
    return interesado;
}

void Conversacion::setInteresado(Interesado * interesado) {
    this->interesado = interesado;
}

Inmobiliaria * Conversacion::getInmobiliaria() {
    return inmobiliaria;
}

void Conversacion::setInmobiliaria(Inmobiliaria * inmobiliaria) {
    this->inmobiliaria = inmobiliaria;
}

ICollection * Conversacion::getMensajes() {
    return mensajes;
}

void Conversacion::setMensajes(ICollection * mensajes) {
    this->mensajes = mensajes;
}


