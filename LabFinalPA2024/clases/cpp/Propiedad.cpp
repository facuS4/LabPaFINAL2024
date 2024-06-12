#include "../h/Propiedad.h"

// Default constructor
Propiedad::Propiedad() : codigo(""), dormitorios(0), ambientes(0), banios(0), garage(false), direccion(nullptr), medif(0.0f), MetrosTotales(0.0f),Conversaciones(new List()) {}

// Constructor with parameters
Propiedad::Propiedad(string codigo, int dormitorios, int ambientes, int banios, bool garage, dtDireccion *direccion, float medif, float metrosTotales){
  this->codigo = codigo;
  this->dormitorios = dormitorios;
  this->ambientes = ambientes;
  this->banios = banios;
  this->garage = garage;
  this->direccion = direccion;
  this->medif = medif;
  this->MetrosTotales = metrosTotales;
  this->Conversaciones=new List();
}

Propiedad::~Propiedad() {}

// Destructor

// Getter and Setter
string Propiedad::getCodigo() {
  return codigo;
}

void Propiedad::setCodigo(string codigoPropiedad) {
  codigo = codigoPropiedad;
}

int Propiedad::getDormitorios() {
  return dormitorios;
}

void Propiedad::setDormitorios(int cantDormitorios) {
  dormitorios = cantDormitorios;
}

int Propiedad::getAmbientes() {
  return ambientes;
}

void Propiedad::setAmbientes(int cantAmbientes) {
  ambientes = cantAmbientes;
}

int Propiedad::getBanios() {
  return banios;
}

void Propiedad::setBanios(int cantBanios) {
  banios = cantBanios;
}

bool Propiedad::getGarage() {
  return garage;
}

void Propiedad::setGarage(bool tieneGarage) {
  garage = tieneGarage;
}

dtDireccion * Propiedad::getDireccion() {
  return direccion;
}

void Propiedad::setDireccion(dtDireccion * dirPropiedad) {
  direccion = dirPropiedad;
}

float Propiedad::getMedif() {
  return medif;
}

void Propiedad::setMedif(float precioMedif) {
  medif = precioMedif;
}

float Propiedad::getMetrosTotales() {
  return MetrosTotales;
}

void Propiedad::setMetrosTotales(float metrosPropiedad) {
  MetrosTotales = metrosPropiedad;
}

void Propiedad::setConvo(Conversacion * c){

  Conversaciones->add(c);

}

