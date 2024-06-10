#include "../h/Propiedad.h"

// Default constructor
Propiedad::Propiedad() : codigo(""), dormitorios(0), ambientes(0), banios(0), garage(false), direccion(dtDireccion()), medif(0.0f), MetrosTotales(0.0f) {}

// Constructor with parameters
Propiedad::Propiedad(string codigoPropiedad, int cantDormitorios, int cantAmbientes, int cantBanios, bool tieneGarage, dtDireccion dirPropiedad, float precioMedif, float metrosPropiedad) :
    codigo(codigoPropiedad), dormitorios(cantDormitorios), ambientes(cantAmbientes), banios(cantBanios), garage(tieneGarage), direccion(dirPropiedad), medif(precioMedif), MetrosTotales(metrosPropiedad) {}

// Destructor (assuming no custom logic needed)
Propiedad::~Propiedad() = default;

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
void Propiedad::eliminarVinculosPropiedad() override {}
void Propiedad::AgregarMensaje(string mensaje) override {}
void Propiedad::CrearMensaje(string mensaje, Usuario u) override {}
set<dtEdificio> Propiedad::ListarPropiedades() override { return set<dtEdificio>(); }
void Propiedad::Vincular(Venta v) override {}
void Propiedad::Vincular(Alquiler a) override {}
