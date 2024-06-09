#include "Sistema.h"

Sistema::Sistema() {
    Departamentos = new List();
    Usuarios = new List();
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

bool Sistema::AltaInmobiliaria(string email, string nombre, dtDireccion dir) {
    return false;
}

void Sistema::EliminarPropiedad(string codigo) {
}

void Sistema::IngresarEmail(string email) {
}

void Sistema::ingreasrcontraseniaNueva(string contrasenia) {
}

void Sistema::listarDepartamentos() {
    IIterator * it;

    for (it = Departamentos->getIterator(); it->hasCurrent(); it->next()){
        Departamento * d = (Departamento *) it->getCurrent();

        cout << "Nombre: " << d->getNombre() << endl;
        cout << "Letra: " << d->getLetradpto() << endl;
    }
    
}

set<dtZona> Sistema::seleccionarDepartamento(string letraDpto) {
    set<dtZona> zonas;
    return zonas;
}

set<string> Sistema::Ultimo5Mensajes() {
    set<string> mensajes;
    return mensajes;
}

void Sistema::EnviarMensaje(string mensaje) {
}

void Sistema::AgregarMensaje(string mensaje) {
}

void Sistema::CrearMensaje(string mensaje) {
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
                if (z != nullptr && z->getCodigo() == codigo) {
                    for(it3 = z->getPropiedades()->getIterator(); it3->hasCurrent(); it3->next()){
                        Propiedad * p = (Propiedad *) it3->getCurrent();
                        cout << "Codigo: " << p->getCodigo() << endl;
                    }
                    return;
                }else{
                    return;
                }
            }
        }
    }
    cout << "No se encontró ninguna zona con el código: " << codigo << endl;
}

bool Sistema::boolSeleccionarZona(string codigo) {
    return false;
}

set<dtEdificio> Sistema::ListarEdificio() {
    set<dtEdificio> edificios;
    return edificios;
}

set<dtEdificio> Sistema::altaApartamento(int ambientes) {
    set<dtEdificio> edificios;
    return edificios;
}

int Sistema::altaApartamento(int, int, int, bool, dtDireccion, int) {
    return 0;
}

int Sistema::altaCasa(int, int, int, bool, dtDireccion, int, int) {
    return 0;
}

void Sistema::vincularconInmobiliaria(Propiedad * p) {
}

void Sistema::seleccionarAlquiler(int precio) {
}

void Sistema::seleccionarVenta(int valor, Propiedad * p) {
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