#include "../h/Apartamento.h"

// Default constructor
Apartamento::Apartamento() : Propiedad(), disponible(true), edificio(nullptr) {}

// Constructor with parameters
Apartamento::Apartamento(string codigo, int dormitorios, int ambientes, int banios, bool garage,dtDireccion * direccion, float medif, float metrosTotales, bool disponible, Edificio * edificio, Zona * zon): Propiedad(codigo, dormitorios, ambientes, banios, garage, direccion, medif, metrosTotales, zon){
  this->disponible = disponible;
  this->edificio = edificio;
}

// Destructor (assuming no custom logic needed)
Apartamento::~Apartamento(){};

// Getter and Setter for 'disponible'
float Apartamento::getMetrosTotales(){ // Getter name mismatch in header
  return Propiedad::getMetrosTotales();
}

string Apartamento::CasaApartamentoDisponible(){
  if(disponible){
    return "Apartamento Disponible";
  }
  else{
    return "Apartamento Ocupado";
  }
  return "Apartamento";
}
void Apartamento::setMetrosTotales(float _metrostotales){
  Propiedad::setMetrosTotales(_metrostotales);
}

void Apartamento::imprimirEdificio(){

  cout<< "Nombre Edificio: " << edificio->getNombre() << " Cantidad pisos: " << edificio->getCantPisos() << " Gastos Comunes: " << edificio->getGastosComunes()<<endl;

}

void Apartamento::setDisponible(bool disponibilidad){
  this->disponible = disponibilidad;
}

void Apartamento::ListarPropiedadesEdificio(){
}

void Apartamento::eliminarVinculosPropiedad(){
  for (IIterator * it1= this->getConversaciones()->getIterator(); it1->hasCurrent();it1->next()){
        Conversacion * convo = dynamic_cast<Conversacion*>(it1->getCurrent());
        if(convo!=nullptr)
            delete convo;
    }
    
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
