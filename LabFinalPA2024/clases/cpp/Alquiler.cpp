
#include "../h/Alquiler.h"

Alquiler::Alquiler() : precioAlquiler(0.0f), p(nullptr) {}

Alquiler::Alquiler(float precio) : precioAlquiler(precio) {}

Alquiler::~Alquiler() {
  this->p = nullptr;
};

float Alquiler::getPrecioAlquiler() {
  return precioAlquiler;
}

void Alquiler::setPrecioAlquiler(float nuevoPrecio) {
  precioAlquiler = nuevoPrecio;
}

void Alquiler::setPropiedad(Propiedad * pp){

  this->p=pp;

}

void Alquiler::ObtenerReporteInmobiliaria4() {
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




Propiedad * Alquiler::getPropiedad(){

  return this->p;
}


//ESTO ES UN DUMMY
void Alquiler::desvincualarAlquiler(string codigo) {
  cout << codigo;
  // IMPLEMENTAR LOGICA
}
