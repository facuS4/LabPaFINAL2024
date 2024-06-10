#include "Departamento.h"

Departamento::Departamento() : Letradpto(' '), nombre(""), Zonas(nullptr) {}

Departamento::Departamento(char letraDpto, string nombreDpto) :
    Letradpto(letraDpto), nombre(nombreDpto), Zonas(new List<Zona>()) {}

Departamento::~Departamento() {
  if (Zonas != nullptr) {
    delete Zonas;
  }
}

char Departamento::getLetradpto() {
  return Letradpto;
}

void Departamento::setLetradpto(char letraDpto) {
  Letradpto = letraDpto;
}

string Departamento::getNombre() {
  return nombre;
}

void Departamento::setNombre(string nombreDpto) {
  nombre = nombreDpto;
}

ICollection* Departamento::getZonas() {
  return Zonas;
}

set<dtZonas> Departamento::SeleccionarDepartamento(char letraDpto) {
  // Implement logic to select departamentos based on letraDpto
  // This might involve iterating through all zonas and checking their departamento letra
  // You'll likely need to include Zona.h for zona access
  set<dtZonas> selectedDepartamentos;
  // Implement selection logic here
  return selectedDepartamentos;
}

Propiedad Departamento::SeleccionarPropiedad(string codigo) {
  // Implement logic to select a specific Propiedad based on codigo
  // This might involve iterating through zonas and searching for propiedades
  // You might need to include Zona.h and Propiedad.h for zona and propiedad access
  Propiedad selectedPropiedad;
  // Implement selection logic here
  return selectedPropiedad;
}

set<dtPropiedad> Departamento::SeleccionarZona(string codigo) {
  // Implement logic to select propiedades within a specific zona based on codigo
  // This might involve finding the zona and then accessing its propiedades
  // You might need to include Zona.h and Propiedad.h for zona and propiedad access
  set<dtPropiedad> selectedPropiedades;
  // Implement selection logic here
  return selectedPropiedades;
}

dtZona Departamento::BuscarZona(string codigo) {
  // Implement logic to search for a zona based on codigo
  // This might involve iterating through zonas and checking their codigo
  // You might need to include Zona.h for zona access
  dtZona foundZona;
  // Implement search logic here
  return foundZona;
}