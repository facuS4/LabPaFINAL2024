#include "../h/Zona.h"

// Default constructor
Zona::Zona(){
  codigo = "";
  nombre = "";
  Propiedades = new List();
  departamento = nullptr;
}

// Constructor with parameters
Zona::Zona(string codigoZona, string nombreZona){
  codigo = codigoZona;
  nombre = nombreZona;
  Propiedades = new List();
  departamento = nullptr;
}

// Destructor
Zona::~Zona() {
  if (Propiedades != nullptr) {
    delete Propiedades;
  }
}

// Getters and Setters for codigo
string Zona::getCodigo() {
  return codigo;
}

void Zona::setCodigo(string codigoZona) {
  codigo = codigoZona;
}

void Zona::setPropiedades(ICollectible * propiedades) {
  this->Propiedades->add(propiedades);
}

ICollection * Zona::getPropiedades() {
  return Propiedades;
}

// Getters and Setters for nombre
string Zona::getNombre() {
  return nombre;
}

void Zona::setNombre(string nombreZona) {  
  nombre = nombreZona;
}

// Method to remove a Propiedad by codigo
void Zona::EliminarPropiedad(Propiedad * prop) {
  ICollection * nuevo=new List();
  if(prop==nullptr){
    cout << "error";
    return;
    
  }
  for(IIterator * it=this->Propiedades->getIterator();it->hasCurrent();it->next()){
    Propiedad * pr = dynamic_cast<Propiedad*>(it->getCurrent());
    if(pr!=nullptr && prop!=nullptr && pr->getCodigo()!=prop->getCodigo()){
      nuevo->add(pr);
    }
    
  }
  this->Propiedades=nuevo;

    if (prop == nullptr)
        return;
    this->Propiedades->remove(prop);

}

bool Zona::ListarPropiedades(){
  IIterator * it;
  IIterator * it2;
  for (it = Propiedades->getIterator(); it->hasCurrent(); it->next()){
    it2 = it;
    Propiedad * p = (Propiedad *)it->getCurrent(); 
    cout << "Codigo de propiedad:  " << p->getCodigo() << endl;
  }
  if(it2 == nullptr){
      cout << "No hay propiedades para mostrar" << endl;
      return false;
  }
  return true;
}

Propiedad * Zona::SeleccionarPropiedad(string codigoPropiedad, string nombreUsuario) {
  cout<<nombreUsuario<<codigoPropiedad;
  return nullptr;
}

// Methods for adding Apartamento and Casa (assuming dtDireccion exists)
bool Zona::altaApartamento(int cantAmbientes, int cantDormitorios, int cantBanios, bool garage, dtDireccion direccion, int piso) {
  cout<<cantAmbientes<<cantDormitorios<<cantBanios<<garage<<piso;
  direccion.getCalle();
  // Implement logic to create and add an Apartamento Propiedad to the Propiedades collection
  // You might need to include Propiedad.h for propiedad access
  return false; // Replace with actual implementation logic and return value
}

bool Zona::altaCasa(int cantAmbientes, int cantDormitorios, int cantBanios, bool garage, dtDireccion direccion, int cantPlantas, int terreno) {
  
  cout<<cantAmbientes<<cantDormitorios<<cantBanios<<garage<<cantPlantas<<terreno;
  direccion.getCalle();
  // Implement logic to create and add a Casa Propiedad to the Propiedades collection
  // You might need to include Propiedad.h for propiedad access
  return false; // Replace with actual implementation logic and return value
}
