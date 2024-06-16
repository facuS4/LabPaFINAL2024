#include "../h/Inmobiliaria.h"

// Default constructor
Inmobiliaria::Inmobiliaria()
{
  nombre = "";
  ubicacion = nullptr;
  ventas = new List();
  alquileres = new List();
}
// Constructor with parameters
Inmobiliaria::Inmobiliaria(string _CorreoElectronico, string _Contrasenia, string _nombre, dtDireccion *ubicacion) : Usuario(_CorreoElectronico, _Contrasenia)
{
  _CorreoElectronico = _CorreoElectronico;
  _Contrasenia = _Contrasenia;
  nombre = _nombre;
  ubicacion = ubicacion;
  ventas = new List();
  alquileres = new List();
}
// Destructor (assuming no custom logic needed)
Inmobiliaria::~Inmobiliaria()
{
}

// Getter and Setter methods for nombre, apellido, edad, ubicacion, ventas
string Inmobiliaria::getNombre()
{
  return this->nombre;
}

void Inmobiliaria::setNombre(string nombreUsuario)
{
  nombre = nombreUsuario;
}

dtDireccion *Inmobiliaria::getUbicacion()
{
  return ubicacion;
}

void Inmobiliaria::setUbicacion(dtDireccion *nuevaUbicacion)
{
  ubicacion = nuevaUbicacion;
}

void Inmobiliaria::setVentas(ICollectible *nuevasVentas)
{
  ventas->add(nuevasVentas);
}

void Inmobiliaria::setAlquileres(ICollectible *nuevosAlquileres)
{
  alquileres->add(nuevosAlquileres);
}

void Inmobiliaria::eliminarAlquiler(Alquiler *alqui)
{

  this->alquileres->remove(alqui);
}
void Inmobiliaria::eliminarVenta(Venta *venta)
{

  this->ventas->remove(venta);
}

ICollection *Inmobiliaria::getVentas()
{
  return ventas;
}

ICollection *Inmobiliaria::getAlquileres()
{
  return alquileres;
}

// Implementations for pure virtual methods inherited from Usuario
void Inmobiliaria::Asociar(Conversacion *c)
{
  c->~Conversacion();
}

void Inmobiliaria::DesvincularInmobiliaria(Conversacion *c)
{
  c->~Conversacion();
}

// Methods for managing ventas and alquileres (replace with your logic)
void Inmobiliaria::desvincularAlquiler(int idAlquiler)
{
  cout << idAlquiler;
  // Implement logic to remove the alquiler with the given id from the 'alquileres' collection
  // This might involve iterating through the collection and removing the matching alquiler
}

void Inmobiliaria::desvincularVenta(int idVenta)
{
  cout << idVenta;

  // Implement logic to remove the venta with the given id from the 'ventas' collection
  // This might involve iterating through the collection and removing the matching venta
}
void Inmobiliaria::menuprueba()
{
  cout << "prueba" << endl;
}

void Inmobiliaria::vincularInmobiliaria(Propiedad *p)
{
  p->~Propiedad();
  // Implement logic to link the Inmobiliaria to the provided Propiedad (p)
  // This might involve adding a reference to the Propiedad in the Inmobiliaria's data
  // Or it might involve adding the Inmobiliaria to the Propiedad's associated inmobiliarias
}

void Inmobiliaria::SeleccionarAlquiler(int idAlquiler)
{
  cout << idAlquiler;
  // Implement logic to select the alquiler with the given id (optional)
  // This might involve storing a reference to the selected alquiler for further actions
}

void Inmobiliaria::SeleccionarVenta(int idVenta)
{
  cout << idVenta;
  // Implement logic to select the venta with the given id (optional)
  // This might involve storing a reference to the selected venta for further actions
}
void Inmobiliaria::IcolAlquileres(ICollection *alquileres)
{
  // delete this->alquileres;
  this->alquileres = alquileres;
}
void Inmobiliaria::IcolVentas(ICollection *ventas)
{
  // delete this->ventas;
  this->ventas = ventas;
}

void Inmobiliaria::EliminarPropiedad(string codigo)
{
  ICollection *nuevaListaVentas = new List();
  Venta *ventaAEliminar = nullptr;

  for (IIterator *it2 = this->getVentas()->getIterator(); it2->hasCurrent(); it2->next())
  {
    Venta *venta = dynamic_cast<Venta *>(it2->getCurrent());
    if (venta != nullptr && venta->getPropiedad()->getCodigo() == codigo)
    {
      ventaAEliminar = venta;
    }
    else
    {
      nuevaListaVentas->add(venta);
    }
  }

  if (ventaAEliminar != nullptr)
  {
    this->propiedadtemp = ventaAEliminar->getPropiedad();
    this->IcolVentas(nuevaListaVentas);

    this->propiedadtemp->eliminarVinculosPropiedad();
    this->propiedadtemp->getZona()->EliminarPropiedad(this->propiedadtemp);
    if (this->propiedadtemp->getConvo() != nullptr)
    {
      delete this->propiedadtemp->getConvo();
    }
    delete this->propiedadtemp;
    delete ventaAEliminar;
  }
  else
  {
    delete nuevaListaVentas;
  }

  ICollection *nuevaListaAlquileres = new List();
  Alquiler *alquilerAEliminar = nullptr;

  for (IIterator *it2 = this->getAlquileres()->getIterator(); it2->hasCurrent(); it2->next())
  {
    Alquiler *alquiler = dynamic_cast<Alquiler *>(it2->getCurrent());
    if (alquiler != nullptr && alquiler->getPropiedad()->getCodigo() == codigo)
    {
      alquilerAEliminar = alquiler;
    }
    else
    {
      nuevaListaAlquileres->add(alquiler);
    }
  }

  if (alquilerAEliminar != nullptr)
  {
    this->propiedadtemp = alquilerAEliminar->getPropiedad();
    this->IcolAlquileres(nuevaListaAlquileres);

    this->propiedadtemp->eliminarVinculosPropiedad();
    this->propiedadtemp->getZona()->EliminarPropiedad(this->propiedadtemp);
    if (this->propiedadtemp->getConvo() != nullptr)
    {
      delete this->propiedadtemp->getConvo();
    }
    delete this->propiedadtemp;
    delete alquilerAEliminar;
  }
  else
  {
    delete nuevaListaAlquileres;
  }
}

bool Inmobiliaria::PerteneceAinmobiliaria(string codigo)
{
  for (IIterator *it1 = this->getVentas()->getIterator(); it1->hasCurrent(); it1->next())
  {
    Venta *vents = dynamic_cast<Venta *>(it1->getCurrent());
    if (vents->getPropiedad()->getCodigo() == codigo)
    {
      return true;
    }
  }
  for (IIterator *it1 = this->getAlquileres()->getIterator(); it1->hasCurrent(); it1->next())
  {
    Alquiler *alqui = dynamic_cast<Alquiler *>(it1->getCurrent());
    if (alqui->getPropiedad()->getCodigo() == codigo)
    {
      return true;
    }
  }
  return false;
}
