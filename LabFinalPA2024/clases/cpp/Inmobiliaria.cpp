#include "../h/Inmobiliaria.h"

// Default constructor
Inmobiliaria::Inmobiliaria(){
  nombre = "";
  ubicacion = nullptr;
  ventas = new List();
  alquileres = new List();
}
// Constructor with parameters
Inmobiliaria::Inmobiliaria(string _CorreoElectronico, string _Contrasenia, string _nombre, dtDireccion * ubicacion) : Usuario(_CorreoElectronico, _Contrasenia) {
  _CorreoElectronico = _CorreoElectronico;
  _Contrasenia = _Contrasenia;
  nombre = _nombre;
  ubicacion = ubicacion;
  ventas = new List();
  alquileres = new List();
}
// Destructor (assuming no custom logic needed)
Inmobiliaria::~Inmobiliaria() {
}

// Getter and Setter methods for nombre, apellido, edad, ubicacion, ventas
string Inmobiliaria::getNombre() {
  return nombre;
}

void Inmobiliaria::setNombre(string nombreUsuario) {
  nombre = nombreUsuario;
}

dtDireccion* Inmobiliaria::getUbicacion() {
  return ubicacion;
}

void Inmobiliaria::setUbicacion(dtDireccion* nuevaUbicacion) {
  ubicacion = nuevaUbicacion; // Set the new ubicacion
}

void Inmobiliaria::setVentas(ICollection* nuevasVentas) {
  ventas = nuevasVentas; // Set the new ventas
}

void Inmobiliaria::setAlquileres(ICollection* nuevosAlquileres) {
  alquileres = nuevosAlquileres; // Set the new alquileres
}

ICollection* Inmobiliaria::getVentas() {
  return ventas;
}

ICollection* Inmobiliaria::getAlquileres() {
  return alquileres;
}



// Implementations for pure virtual methods inherited from Usuario
void Inmobiliaria::Asociar(Conversacion * c) {
  c->~Conversacion();
}

void Inmobiliaria::DesvincularInmobiliaria(Conversacion *c) {
    c->~Conversacion();

}

// Methods for managing ventas and alquileres (replace with your logic)
void Inmobiliaria::desvincularAlquiler(int idAlquiler) {
  cout << idAlquiler;
  // Implement logic to remove the alquiler with the given id from the 'alquileres' collection
  // This might involve iterating through the collection and removing the matching alquiler
}

void Inmobiliaria::desvincularVenta(int idVenta) {
    cout << idVenta;

  // Implement logic to remove the venta with the given id from the 'ventas' collection
  // This might involve iterating through the collection and removing the matching venta
}

void Inmobiliaria::vincularInmobiliaria(Propiedad * p) {
  p->~Propiedad();
  // Implement logic to link the Inmobiliaria to the provided Propiedad (p)
  // This might involve adding a reference to the Propiedad in the Inmobiliaria's data
  // Or it might involve adding the Inmobiliaria to the Propiedad's associated inmobiliarias
}

void Inmobiliaria::SeleccionarAlquiler(int idAlquiler) {
  cout << idAlquiler;
  // Implement logic to select the alquiler with the given id (optional)
  // This might involve storing a reference to the selected alquiler for further actions
}

void Inmobiliaria::SeleccionarVenta(int idVenta) {
  cout << idVenta;
  // Implement logic to select the venta with the given id (optional)
  // This might involve storing a reference to the selected venta for further actions
}
