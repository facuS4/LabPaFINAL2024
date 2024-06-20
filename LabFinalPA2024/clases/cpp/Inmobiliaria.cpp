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
  this->ubicacion = ubicacion;
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
    if (this->propiedadtemp->getConversaciones() != nullptr)
    {
      delete this->propiedadtemp->getConversaciones();
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
    if (this->propiedadtemp->getConversaciones() != nullptr)
    {
      delete this->propiedadtemp->getConversaciones();
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

void Inmobiliaria::ObtenerReporteInmobiliaria2() {
    int counter = 0;
    cout << "-----En Venta-----" << endl;

    if (this->ventas == nullptr) {
        cout << "Error: ventas is nullptr" << endl;
        return;
    }

    auto ventasIterator = this->ventas->getIterator();
    if (ventasIterator == nullptr) {
        cout << "Error: ventas->getIterator() = nullptr" << endl;
        return;
    }

    for (IIterator *it = ventasIterator; it->hasCurrent(); it->next()) {
        auto current = it->getCurrent();
        if (current == nullptr) {
            cout << "Error: ventasIterator->getCurrent() = nullptr" << endl;
            continue;
        }

        Venta *v = dynamic_cast<Venta *>(current);
        if (v != nullptr) {
            v->ObtenerReporteInmobiliaria3();
            counter++;
        } else {
            cout << "Error: dynamic_cast<Venta *>" << endl;
        }
    }
    cout << "--------------------------------------"<<endl;

    cout << "CANTIDAD DE PROPIEDADES EN VENTA = " << counter << endl;
        cout << "--------------------------------------"<<endl;

    counter = 0;

    cout << "-----En Alquiler-----" << endl;

    if (this->alquileres == nullptr) {
        cout << "Error: alquileres is nullptr" << endl;
        return;
    }

    auto alquileresIterator = this->alquileres->getIterator();
    if (alquileresIterator == nullptr) {
        cout << "Error: alquileres->getIterator() = nullptr" << endl;
        return;
    }

    for (IIterator *it = alquileresIterator; it->hasCurrent(); it->next()) {
        auto current = it->getCurrent();
        if (current == nullptr) {
            cout << "Error: alquileresIterator->getCurrent() = nullptr" << endl;
            continue;
        }

        Alquiler *a = dynamic_cast<Alquiler *>(current);
        if (a != nullptr) {
            a->ObtenerReporteInmobiliaria4();
            counter++;
        } else {
            cout << "Error: dynamic_cast<Alquiler *> fallo" << endl;
        }
    }
    cout << "--------------------------------------"<<endl;
    cout << "CANTIDAD DE PROPIEDADES EN ALQUILER = " << counter << endl;
        cout << "--------------------------------------"<<endl;

}

