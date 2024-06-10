#include "../h/Apartamento.h"

// Default constructor
Apartamento::Apartamento() : Propiedad(), disponible(true), edificio(Edificio()) {}

// Constructor with parameters
Apartamento::Apartamento(string codigo, int dormitorios, int ambientes, int banios, bool garage, dtDireccion direccion, float medif, float metrosPropiedad, bool disp) : Propiedad(codigo, dormitorios, ambientes, banios, garage, direccion, medif, metrosPropiedad){
  
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

void Apartamento::AgregarMensaje(string mensaje) {
}

void Apartamento::CrearMensaje(string mensaje, Usuario *u){
}

void Apartamento::Vincular(Venta v){
}

void Apartamento::Vincular(Alquiler a){
}
