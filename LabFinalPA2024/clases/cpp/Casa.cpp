#include "Casa.h"

// Default constructor
Casa::Casa() : Propiedad(), metrosTotales(0.0f) {}

// Constructor with parameters
Casa::Casa(string codigo, int dormitorios, int ambientes, int banios, bool garage, dtDireccion direccion, float medif, float metrosConstruidos, float terreno) :
    Propiedad(codigo, dormitorios, ambientes, banios, garage, direccion, medif, metrosConstruidos),
    metrosTotales(terreno) {}

// Destructor (assuming no custom logic needed)
Casa::~Casa() override = default;

// Getter and Setter for terreno (adjusted name for clarity)
float Casa::getMetrosTotales() {
  return metrosTotales;
}

void Casa::setTerreno(float areaTotal) {
  metrosTotales = areaTotal;
}

// Implementations for pure virtual methods inherited from Propiedad

// Override to return an empty set since Casa isn't an Edificio
set<dtEdificio> Casa::ListarPropiedades() override {
  return set<dtEdificio>();
}

// Implementations for Casa specific methods (replace with your logic)
void Casa::eliminarVinculosPropiedad() override {
  // Implement logic to remove any linked ventas or alquileres for this Casa
  // This might involve iterating through linked collections and removing references
}

void Casa::AgregarMensaje(string mensaje) override {
  // Implement logic to add a message specific to Casa (optional)
}

void Casa::CrearMensaje(string mensaje, Usuario u) override {
  // Implement logic to create a message with user association (optional)
}

// Implementations for linking with Venta and Alquiler (optional depending on your logic)
void Casa::Vincular(Venta v) override {
  // Implement logic to link this Casa with a Venta object (optional)
}

void Casa::Vincular(Alquiler a) override {
  // Implement logic to link this Casa with an Alquiler object (optional)
}
