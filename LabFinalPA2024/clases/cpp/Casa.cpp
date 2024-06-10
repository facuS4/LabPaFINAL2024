#include "../h/Casa.h"

// Default constructor
Casa::Casa() : Propiedad(), metrosVerdes(0.0f) {}

// Constructor with parameters
Casa::Casa(string codigo, int dormitorios, int ambientes, int banios, bool garage, dtDireccion * direccion, float medif, float metrosTotales, float metrosVerdes) : Propiedad(codigo, dormitorios, ambientes, banios, garage, direccion, medif, metrosTotales){
  this->metrosVerdes = metrosVerdes;
}

// Destructor (assuming no custom logic needed)
Casa::~Casa(){};

// Getter and Setter for terreno (adjusted name for clarity)
float Casa::getMetrosVerdes() {
  return metrosVerdes;
}


// Implementations for pure virtual methods inherited from Propiedad

// Override to return an empty set since Casa isn't an Edificio
void Casa::ListarPropiedadesEdificio(){
}

// Implementations for Casa specific methods (replace with your logic)
void Casa::eliminarVinculosPropiedad(){
  // Implement logic to remove any linked ventas or alquileres for this Casa
  // This might involve iterating through linked collections and removing references
}

void Casa::AgregarMensaje(string mensaje){
  // Implement logic to add a message specific to Casa (optional)
}

void Casa::CrearMensaje(string mensaje, Usuario *u){
  // Implement logic to create a message with user association (optional)
}

// Implementations for linking with Venta and Alquiler (optional depending on your logic)
void Casa::Vincular(Venta *v){
  // Implement logic to link this Casa with a Venta object (optional)
}

void Casa::Vincular(Alquiler *a){
  // Implement logic to link this Casa with an Alquiler object (optional)
}
