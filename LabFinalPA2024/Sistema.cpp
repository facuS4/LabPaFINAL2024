#include "Sistema.h"

Sistema::Sistema() {
    Departamentos = new List();
    Usuarios = new List();
    usuarioSesion = nullptr;
}

Sistema::~Sistema() {
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



