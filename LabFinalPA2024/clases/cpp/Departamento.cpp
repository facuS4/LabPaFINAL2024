#include "../h/Departamento.h"

Departamento::Departamento() : Letradpto(' '), nombre(""), Zonas(nullptr) {}

Departamento::Departamento(char letraDpto, string nombreDpto) :
    Letradpto(letraDpto), nombre(nombreDpto), Zonas(new List()) {}

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

void Departamento::setZona(Zona * z)
{
  this->getZonas()->add(z);
}

ICollection* Departamento::getZonas() {
  return Zonas;
}

void Departamento::SeleccionarDepartamento(char letraDpto) {
  cout << letraDpto;
  // Implement logic to select departamentos based on letraDpto
  // This might involve iterating through all zonas and checking their departamento letra
  // You'll likely need to include Zona.h for zona access
}

Propiedad * Departamento::SeleccionarPropiedad(string codigo) {
  cout << codigo;
  // Implement logic to select a specific Propiedad based on codigo
  // This might involve iterating through zonas and searching for propiedades
  // You might need to include Zona.h and Propiedad.h for zona and propiedad access

  // Implement selection logic here
  return nullptr; // Replace with actual implementation logic and return value
}

void Departamento::SeleccionarZona(string codigo) {
  cout << codigo;
  // Implement logic to select propiedades within a specific zona based on codigo
  // This might involve finding the zona and then accessing its propiedades
  // You might need to include Zona.h and Propiedad.h for zona and propiedad access
}

void Departamento::BuscarZona(string codigo) {
  cout << codigo;
  // Implement logic to search for a zona based on codigo
  // This might involve iterating through zonas and checking their codigo
  // You might need to include Zona.h for zona access
}

void Departamento::listarZonas(){
  IIterator * it;
  IIterator * it2;
  for(it=Zonas->getIterator();it->hasCurrent();it->next()){
    it2=it;
    Zona * z = dynamic_cast<Zona*>(it->getCurrent());
    cout << "El codigo de la zona es " << z->getCodigo() << endl;
    cout << "El nombre de la zona es " << z->getNombre() << endl;
  }
  if(it2 == nullptr){
      cout << "No hay zonas para mostrar" << endl;
  }

}