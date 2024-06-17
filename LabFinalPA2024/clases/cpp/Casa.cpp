#include "../h/Casa.h"

// Default constructor
Casa::Casa() : Propiedad(), metrosVerdes(0.0f) {}

// Constructor with parameters
Casa::Casa(string codigo, int dormitorios, int ambientes, int banios, bool garage, dtDireccion * direccion, float medif, float metrosTotales, float metrosVerdes, Zona * zona) : Propiedad(codigo, dormitorios, ambientes, banios, garage, direccion, medif, metrosTotales, zona){
  this->metrosVerdes = metrosVerdes;
}

// Destructor (assuming no custom logic needed)
Casa::~Casa(){};

// Getter and Setter for terreno (adjusted name for clarity)
float Casa::getMetrosVerdes() {
  return metrosVerdes;

}

void Casa::setMetrosVerdes(float metrosverdes){

  this->metrosVerdes=metrosverdes;
}


// Implementations for pure virtual methods inherited from Propiedad

// Override to return an empty set since Casa isn't an Edificio
void Casa::ListarPropiedadesEdificio(){
  cout << "placeholder";
}
//        virtual void ListarPropiedadesEdifico()= 0;


// Implementations for Casa specific methods (replace with your logic)
void Casa::eliminarVinculosPropiedad(){
  for (IIterator * it1= this->getConversaciones()->getIterator(); it1->hasCurrent();it1->next()){  
        Conversacion * convo = dynamic_cast<Conversacion*>(it1->getCurrent());
        if(convo!=nullptr)
            delete convo;
    }
}

void Casa::AgregarMensaje(string mensaje){
  cout << mensaje;
  // Implement logic to add a message specific to Casa (optional)
}

void Casa::CrearMensaje(string mensaje, Usuario *u){
    cout << mensaje;
    u->~Usuario();
  // Implement logic to create a message with user association (optional)
}

// Implementations for linking with Venta and Alquiler (optional depending on your logic)
void Casa::VincularV(Venta *v){
  v->~Venta();
  // Implement logic to link this Casa with a Venta object (optional)
}

void Casa::VincularA(Alquiler *a){
  a->~Alquiler();
  // Implement logic to link this Casa with an Alquiler object (optional)
}
/*Casa();
        Casa(string, int, int, int, bool, dtDireccion , float, float, float);
        ~Casa();

        float getMetrosVerdes();
        void setMetrosVerdes(float);

        void eliminarVinculosPropiedad();
        void AgregarMensaje(string);

        void CrearMensaje(string, Usuario* u);

        void ListarPropiedadesEdificio();
        void VincularV(Venta *v);
        void VincularA(Alquiler * a);*/