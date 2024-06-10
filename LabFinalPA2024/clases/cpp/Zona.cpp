#include "Zona.h"

// Default constructor
Zona::Zona() : codigo(""), nombre(""), Propiedades(nullptr), departamento(nullptr) {}

// Constructor with parameters
Zona::Zona(string codigoZona, string nombreZona) :
    codigo(codigoZona), nombre(nombreZona), Propiedades(new List<Propiedad>()) {}

// Destructor
Zona::~Zona() {
  if (Propiedades != nullptr) {
    delete Propiedades;
  }
}

// Getters and Setters for codigo
string Zona::getCodigo() {
  return codigo;
}

void Zona::setCodigo(string codigoZona) {
  codigo = codigoZona;
}

// Getters and Setters for nombre
string Zona::getNombre() {
  return nombre;
}

void Zona::setNombre(string nombreZona) {  
  nombre = nombreZona;
}

// Method to remove a Propiedad by codigo
void Zona::EliminarPropiedad(string codigoPropiedad) {
  // Implement logic to remove Propiedad from Propiedades collection
  // This might involve iterating through the collection and removing the matching propiedad
  // You'll likely need to include Propiedad.h for propiedad access
}

// Implementations for Zona specific methods (assuming dtPropiedad, dtEdificio exist)
set<dtPropiedad> Zona::SeleccionarZona(string codigo) {
  // Implement logic to select all propiedades within this zona
  // This might involve iterating through the Propiedades collection
  // You might need to include Propiedad.h for propiedad access
  set<dtPropiedad> selectedPropiedades;
  // Implement selection logic here
  return selectedPropiedades;
}

Propiedad Zona::SeleccionarPropiedad(string codigoPropiedad, string nombreUsuario) {
  // Implement logic to select a specific Propiedad based on codigo and potentially user access
  // This might involve iterating through Propiedades and checking codigo and user access
  // You might need to include Propiedad.h for propiedad access
  Propiedad selectedPropiedad;
  // Implement selection logic here
  return selectedPropiedad;
}

set<dtEdificio> Zona::ListarEdificios() {
  // Implement logic to list all edificios within this zona (assuming dtEdificio exists)
  // This might involve checking propiedad types within Propiedades
  // You might need to include Propiedad.h for propiedad access
  set<dtEdificio> edificios;
  // Implement logic to identify and add edificios to the set
  return edificios;
}

// Methods for adding Apartamento and Casa (assuming dtDireccion exists)
bool Zona::altaApartamento(int cantAmbientes, int cantDormitorios, int cantBaños, bool garage, dtDireccion direccion, int piso) {
  // Implement logic to create and add an Apartamento Propiedad to the Propiedades collection
  // You might need to include Propiedad.h for propiedad access
  return false; // Replace with actual implementation logic and return value
}

bool Zona::altaCasa(int cantAmbientes, int cantDormitorios, int cantBaños, bool garage, dtDireccion direccion, int cantPlantas, int terreno) {
  // Implement logic to create and add a Casa Propiedad to the Propiedades collection
  // You might need to include Propiedad.h for propiedad access
  return false; // Replace with actual implementation logic and return value
}
