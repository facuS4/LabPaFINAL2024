#include "Apartamento.h"

// Default constructor
Apartamento::Apartamento() : Propiedad(), disponible(true), edificio(Edificio()) {}

// Constructor with parameters
Apartamento::Apartamento(string codigo, int dormitorios, int ambientes, int banios, bool garage, dtDireccion direccion, float medif, float metrosPropiedad, bool disp) :
    Propiedad(codigo, dormitorios, ambientes, banios, garage, direccion, medif, metrosPropiedad),
    disponible(disp), edificio(Edificio()) {}

// Destructor (assuming no custom logic needed)
Apartamento::~Apartamento() override = default;

// Getter and Setter for 'disponible'
bool Apartamento::getMetrosTotales() override { // Getter name mismatch in header
  return disponible;
}

void Apartamento::setMetrosTotales(float disp) override { // Setter name mismatch in header
  disponible = disp; // Update to set actual availability (boolean)
}

// Implementations for pure virtual methods inherited from Propiedad

// Override to potentially return details of the parent Edificio (replace with your logic)
set<dtEdificio> Apartamento::ListarPropiedades() override {
  set<dtEdificio> edificioData;
  // Implement logic to get details from the parent Edificio and add to edificioData
  // This might involve accessing edificio member variables or methods
  edificioData.insert(edificio.getEdificioDt()); // Assuming getEdificioDt() exists in Edificio
  return edificioData;
}

// Implementations for Apartamento specific methods (replace with your logic)
void Apartamento::eliminarVinculosPropiedad() override {
  // Implement logic to remove any linked ventas or alquileres for this Apartamento
  // This might involve iterating through linked collections and removing references
  // Consider also notifying the Edificio about the removal (optional)
}

void Apartamento::AgregarMensaje(string mensaje) override {
  // Implement logic to add a message specific to Apartamento (optional)
}

void Apartamento::CrearMensaje(string mensaje, Usuario u) override {
  // Implement logic to create a message with user association (optional)
}

// Implementations for linking with Venta and Alquiler (optional depending on your logic)
void Apartamento::Vincular(Venta v) override {
  // Implement logic to link this Apartamento with a Venta object (optional)
  // Consider updating availability based on the Venta
}

void Apartamento::Vincular(Alquiler a) override {
  // Implement logic to link this Apartamento with an Alquiler object (optional)
  // Consider updating availability based on the Alquiler
}
