#include "../h/Propiedad.h"

// Default constructor
Propiedad::Propiedad() : codigo(""), dormitorios(0), ambientes(0), banios(0), garage(false), direccion(dtDireccion()), medif(0.0f), MetrosTotales(0.0f) {}

// Constructor with parameters
Propiedad::Propiedad(string codigo, int dormitorios, int ambientes, int banios, bool garage, dtDireccion direccion, float medif, float metrosTotales){
  this->codigo = codigo;
  this->dormitorios = dormitorios;
  this->ambientes = ambientes;
  this->banios = banios;
  this->garage = garage;
  this->direccion = direccion;
  this->medif = medif;
  this->MetrosTotales = metrosTotales;
}

// Destructor (assuming no custom logic needed)
Propiedad::~Propiedad(){};

// Getter and Setter methods
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

dtDireccion Propiedad::getDireccion() {
  return direccion;
}

void Propiedad::setDireccion(dtDireccion dirPropiedad) {
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

// Implementations for pure virtual methods are left empty as they require specific logic in derived classes
