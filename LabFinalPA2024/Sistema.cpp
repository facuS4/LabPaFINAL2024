#include "Sistema.h"

Sistema::Sistema() {
    Departamentos = new List();
    Usuarios = new List();
    usuarioSesion = nullptr;
}

Sistema::~Sistema() {
}

ICollection * Sistema::getUsuarios(){

    return this->Usuarios;

}

void Sistema::setUsuarioActual(Usuario * u){

    this->usuarioSesion=u;

}

 void Sistema::altaUsuario (Usuario * u) {

    if (this->Usuarios->member(u))
    {   cout << "Este usuario ya existe" << endl;
        return;
    }
    Usuarios->add(u);
    return;
 }

Sistema * Sistema::instancia = NULL;

Sistema * Sistema::getInstancia() {
    if (instancia == NULL) {
        instancia = new Sistema();
    }
    return instancia;
}

Usuario * Sistema::getUsuarioActual(){

    return this->usuarioSesion;

}

bool Sistema::AltaInmobiliaria(string email, string nombre, dtDireccion dir) {
    cout <<nombre<<email;
    dir.getCalle();
    return false;
}

void Sistema::EliminarPropiedad(string codigo) {
    cout << codigo;
}

void Sistema::IngresarEmail(string email) {
    cout << email;
}

void Sistema::ingreasrcontraseniaNueva(string contrasenia) {
    cout << contrasenia;
}

void Sistema::listarDepartamentos() {
    IIterator * it;

    for (it = Departamentos->getIterator(); it->hasCurrent(); it->next()){
        Departamento * d = (Departamento *) it->getCurrent();

        cout << "Nombre: " << d->getNombre() << endl;
        cout << "Letra: " << d->getLetradpto() << endl;
    }
    
}

Departamento * Sistema::seleccionarDepartamento(char letraDpto) {
    IIterator * it;
    for (it = Departamentos->getIterator(); it->hasCurrent(); it->next()){
        Departamento * d = (Departamento *) it->getCurrent();
        if (d->getLetradpto() == letraDpto){
            cout << "Nombre: " << d->getNombre() << endl;
            cout << "Letra: " << d->getLetradpto() << endl;
            return d;
        }
    }
    cout << "No se encontro el departamento" << endl;
    return nullptr;
}

void Sistema::Ultimo5Mensajes() {
}

void Sistema::EnviarMensaje(string mensaje) {
    cout << mensaje;
}

void Sistema::AgregarMensaje(string mensaje) {
    cout << mensaje;
}

void Sistema::CrearMensaje(string mensaje) {
    cout << mensaje;
}


void Sistema::SelecionarZona(string codigo) {
    IIterator * it;
    IIterator * it2;
    IIterator * it3;

    for (it = Departamentos->getIterator(); it->hasCurrent(); it->next()){
        Departamento * d = (Departamento *) it->getCurrent();

        if (d != nullptr){
            for(it2 = d->getZonas()->getIterator(); it2->hasCurrent(); it2->next()){
                Zona * z = (Zona *) it2->getCurrent();
                if(z != nullptr && z->getCodigo() == codigo){
                        for(it3 = z->getPropiedades()->getIterator(); it3->hasCurrent(); it3->next()){
                        Propiedad * p = (Propiedad *) it3->getCurrent();
                        cout << "Codigo: " << p->getCodigo() << endl;
                    }
                }    
            }
        }else{
            return;
        }
            
    }
}

bool Sistema::boolSeleccionarZona(string codigo) {
    cout << codigo;
    return false;
}

void Sistema::ListarEdificio() {
}

void Sistema::altaApartamento(int ambientes) {
    cout << ambientes;
}

int Sistema::altaApartamento(int, int, int, bool, dtDireccion, int) {
    return 0;
}

int Sistema::altaCasa(int, int, int, bool, dtDireccion, int, int) {
    return 0;
}

void Sistema::vincularconInmobiliaria(Propiedad *p) {
    p->~Propiedad();
}

void Sistema::seleccionarAlquiler(int precio) {
    cout << precio;
}

void Sistema::seleccionarVenta(int valor, Propiedad *p) {
    cout <<valor;
    p->~Propiedad();

}

void Sistema::AltaDepartamento(char _letraDpt, string _codigo) {
    IIterator * it;

    for (it = Departamentos->getIterator(); it->hasCurrent(); it->next()){
        Departamento * d = (Departamento *) it->getCurrent();
        if (d->getLetradpto() == _letraDpt){
            cout << "Ya existe un departamento con la letra: " << _letraDpt << endl;
            return;
        }
    }

    Departamento * d = new Departamento(_letraDpt, _codigo);
    Departamentos->add(d);
}






    /*void Sistema::altaEstudiante(string _ci, string _nombre, string _apellido, date _fnac, string _telefono, int _creditos){
    IKey * k = new String(_ci.c_str());

    if(this->miEstudiante->member(k)){
        cout << color_red << "El Estudiante " << _nombre << " ya existe." << color_reset << endl;
        return;
    };
    estudiante * e = new estudiante(_ci, _nombre, _apellido, _fnac, _telefono, _creditos);
    miEstudiante->add(k,e);
    cout << color_green << "El Estudiante " << _nombre << " fue agregado correctamente" << color_reset << endl;
};  
    */