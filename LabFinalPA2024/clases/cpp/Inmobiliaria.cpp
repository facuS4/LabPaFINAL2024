#include "Inmobiliaria.h"

// Default constructor
Inmobiliaria::Inmobiliaria() : Usuario(), nombre(""), ubicacion(nullptr), ventas(new List<Venta>()), alquileres(new List<Alquiler>()) {}

// Constructor with parameters
Inmobiliaria::Inmobiliaria(string nombreUsuario, string apellidoUsuario, int edadUsuario, string emailUsuario) :
  Usuario(emailUsuario, ""), nombre(nombreUsuario), edad(edadUsuario), apellido(apellidoUsuario), ubicacion(nullptr),
  ventas(new List<Venta>()), alquileres(new List<Alquiler>()) {}

// Destructor (assuming no custom logic needed)
Inmobiliaria::~Inmobiliaria() {
  delete ubicacion; // Deallocate the dynamically allocated ubicacion if not null
  delete ventas; // Deallocate the dynamically allocated ventas collection
  delete alquileres; // Deallocate the dynamically allocated alquileres collection
}

// Getter and Setter methods for nombre, apellido, edad, ubicacion, ventas
string Inmobiliaria::getNombre() {
  return nombre;
}

void Inmobiliaria::setNombre(string nombreUsuario) {
  nombre = nombreUsuario;
}

string Inmobiliaria::getApellido() {
  return apellido;
}

void Inmobiliaria::setApellido(string apellidoUsuario) {
  apellido = apellidoUsuario;
}

int Inmobiliaria::getEdad() {
  return edad;
}

void Inmobiliaria::setEdad(int edadUsuario) {
  edad = edadUsuario;
}

dtDireccion* Inmobiliaria::getUbicacion() {
  return ubicacion;
}

void Inmobiliaria::setUbicacion(dtDireccion* nuevaUbicacion) {
  if (ubicacion != nullptr) {
    delete ubicacion; // Deallocate the old ubicacion if it exists
  }
  ubicacion = nuevaUbicacion; // Set the new ubicacion
}

ICollection* Inmobiliaria::getVentas() {
  return ventas;
}

// Implementations for pure virtual methods inherited from Usuario
void Inmobiliaria::Asociar(Conversacion c) override {
  conversaciones->add(c); // Add the Conversacion to the collection
}

void Inmobiliaria::DesvincularInmobiliaria(Conversacion c) override {
  conversaciones->remove(c); // Remove the Conversacion from the collection
}

// Methods for managing ventas and alquileres (replace with your logic)
void Inmobiliaria::desvincularAlquiler(int idAlquiler) {
  // Implement logic to remove the alquiler with the given id from the 'alquileres' collection
  // This might involve iterating through the collection and removing the matching alquiler
}

void Inmobiliaria::desvincularVenta(int idVenta) {
  // Implement logic to remove the venta with the given id from the 'ventas' collection
  // This might involve iterating through the collection and removing the matching venta
}

void Inmobiliaria::vincularInmobiliaria(Propiedad p) {
  // Implement logic to link the Inmobiliaria to the provided Propiedad (p)
  // This might involve adding a reference to the Propiedad in the Inmobiliaria's data
  // Or it might involve adding the Inmobiliaria to the Propiedad's associated inmobiliarias
}

void Inmobiliaria::SeleccionarAlquiler(int idAlquiler) {
  // Implement logic to select the alquiler with the given id (optional)
  // This might involve storing a reference to the selected alquiler for further actions
}

void Inmobiliaria::SeleccionarVenta(int idVenta) {
  // Implement logic to select the venta with the given id (optional)
  // This might involve storing a reference to the selected venta for further actions
}
