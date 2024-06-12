#include "../h/Apartamento.h"

// Default constructor
Apartamento::Apartamento() : Propiedad(), disponible(true), edificio(nullptr) {}

// Constructor with parameters
Apartamento::Apartamento(string codigo, int dormitorios, int ambientes, int banios, bool garage,dtDireccion * direccion, float medif, float metrosTotales, bool disponible, Edificio * edificio): Propiedad(codigo, dormitorios, ambientes, banios, garage, direccion, medif, metrosTotales){
  this->disponible = disponible;
  this->edificio = edificio;
}

// Destructor (assuming no custom logic needed)
Apartamento::~Apartamento(){};

// Getter and Setter for 'disponible'
float Apartamento::getMetrosTotales(){ // Getter name mismatch in header
  return Propiedad::getMetrosTotales();
}

void Apartamento::setMetrosTotales(float _metrostotales){
  Propiedad::setMetrosTotales(_metrostotales);
}


void Apartamento::ListarPropiedadesEdificio(){
}

void Apartamento::eliminarVinculosPropiedad(){
}

//ESTO ES UN DUMMY

void Apartamento::AgregarMensaje(string mensaje) {
  cout<< mensaje;
}
//ESTO ES UN DUMMY

void Apartamento::CrearMensaje(string mensaje, Usuario *u){
    cout<< mensaje;
    u->~Usuario();

}
//ESTO ES UN DUMMY

void Apartamento::VincularV(Venta * v){
  v->~Venta();
}
//ESTO ES UN DUMMY

void Apartamento::VincularA(Alquiler * a){
  a->~Alquiler();
}
