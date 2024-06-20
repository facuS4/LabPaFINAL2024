#include "../h/Venta.h"

// Default constructor
Venta::Venta() : precioVenta(0.0f), p(nullptr) {}

// Constructor with parameter
Venta::Venta(float precio){
  precioVenta = precio;
  this->p=nullptr;
} 

// Destructor (assuming no custom logic needed)
Venta::~Venta() = default;


  //Propiedad * getPropiedad();
void Venta::ObtenerReporteInmobiliaria3() {
    if (this->p == nullptr) {
        cout << "Error: p is nullptr" << endl;
        return;
    }
    /*Casa * p2 = dynamic_cast<Casa*>(p);
    if(p2!=nullptr){
      cout << "TIPO DE PROPIEDAD: Casa";
    }
    else{
      Apartamento * p3 = dynamic_cast<Apartamento*>(p);
      if(p3!=nullptr){
      cout << "TIPO DE PROPIEDAD: Apartamento";
      cout << "BOOL DISPONIBLE? "<< p3->getDisponible();
      }
    }*/
    cout<< p->CasaApartamentoDisponible()<<endl;
    if(p->CasaApartamentoDisponible()[0]=='A'){
      p->imprimirEdificio();
    }
    auto zona = this->p->getZona();
    if (zona == nullptr) {
        cout << "Error: p->getZona() returned nullptr" << endl;
        return;
    }

    auto departamento = zona->getDepartamento();
    if (departamento == nullptr) {
        cout << "Error: zona->getDepartamento() returned nullptr" << endl;
        return;
    }

    cout << "LETRA DEPTO: " << departamento->getLetradpto() << endl;
    cout << "NOMBRE DEPTO: " << departamento->getNombre() << endl;
    cout << "ZONA CODIGO: " << zona->getCodigo() << endl;
    cout << "ZONA NOMBRE: " << zona->getNombre() << endl;

    auto propiedad = this->getPropiedad();
    if (propiedad == nullptr) {
        cout << "Error: getPropiedad() returned nullptr" << endl;
        return;
    }

    cout << "PROPIEDAD CODIGO: " << propiedad->getCodigo() << endl;
    cout << "PROPIEDAD AMBIENTES: " << propiedad->getAmbientes() << endl;
    cout << "PROPIEDAD BANIOS: " << propiedad->getBanios() << endl;
    cout << "PROPIEDAD DIRECCION: " << propiedad->getDireccion()->getPais() << " - " << propiedad->getDireccion()->getCiudad() << " - " << propiedad->getDireccion()->getCalle() << " - " << propiedad->getDireccion()->getNumero() << endl;
    cout << "PROPIEDAD DORMITORIOS: " << propiedad->getDormitorios() << endl;
    cout << "PROPIEDAD BOOL GARAGE?: " << propiedad->getGarage() << endl;
    cout << "PROPIEDAD METROS EDIFICADOS: " << propiedad->getMedif() << endl;
    cout << "PROPIEDAD METROS VERDES: " << propiedad->getMetrosTotales() - propiedad->getMedif() << endl;
    cout << "PROPIEDAD METROS TOTALES: " << propiedad->getMetrosTotales() << endl <<endl;
}


Propiedad * Venta::getPropiedad(){
  return this->p;
}

// Getter and Setter methods for precioVenta
float Venta::getPrecioVenta() {
  return precioVenta;
}
void Venta::setPropiedad(Propiedad * pp){

  this->p=pp;
  //cout << pp->getCodigo();
}

void Venta::setPrecioVenta(float nuevoPrecio) {
  precioVenta = nuevoPrecio;
}

// Method to desvincular a Venta (replace with your logic)
void Venta::desvincularVenta(string codigoPropiedad) {
  cout << codigoPropiedad;
  // Implement logic to potentially remove association with a Propiedad identified by 'codigoPropiedad'
  // This might involve:
  //  - Updating the related Propiedad to indicate it's no longer en venta
  //  - Removing the Venta from a collection of ventas associated with the Propiedad (if applicable)
  //  - Notifying other interested parties (optional)
}
