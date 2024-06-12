#include "Sistema.h"

Sistema::Sistema() {
    Departamentos = new List();
    misUsuarios = new List();
    Edificios = new List();
    usuarioSesion = nullptr;
}

Sistema::~Sistema() {
}

void Sistema::AltaEdificio(string nombre, int pisos, int gastosComunes){

    IIterator * it = Edificios->getIterator();
    while(it->hasCurrent()){
        Edificio * e = (Edificio *) it->getCurrent();
        if(e->getNombre()==nombre){
            cout << "El edificio ya existe"<<endl;
            return;
        }
        it->next();
    }
    delete it;
    Edificio * nuevo = new Edificio(nombre,pisos,gastosComunes);
    Edificios->add(nuevo);
    cout << "Edificio '" << nombre << "' dado de alta exitosamente." << endl;
    return;
}


ICollection * Sistema::getUsuarios() {
    return this->misUsuarios;
}

void Sistema::setUsuarioActual(Usuario * u){
    this->usuarioSesion=u;
}

ICollection * Sistema::getDepartamento(){
    return this->Departamentos;

}

void Sistema::setDepartamento(Departamento * u){
    this->getDepartamento()->add(u);
}

void Sistema::Listarusuarios() {
    IIterator * it;
    for (it = misUsuarios->getIterator(); it->hasCurrent(); it->next()) {
        Usuario * u = (Usuario *) it->getCurrent();
        cout << "Correo: " << u->getCorreoElectronico() << endl;
    }
}


void Sistema::altaUsuario (Usuario * u) {

    if (this->misUsuarios->member(u))
    {   cout << "Este usuario ya existe" << endl;
        return;
    }
    misUsuarios->add(u);
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

void Sistema::AltaInmobiliaria(string email, string nombre) {
    // Verificar si el usuario actual tiene permisos de Administrador
    if (dynamic_cast<Administrador*>(this->usuarioSesion) == nullptr) {
        cout << "Error: Se requieren permisos de Administrador para dar de alta una inmobiliaria." << endl;
        return;
    }

    // Verificar si ya existe un usuario con el mismo email
    for (IIterator* it = misUsuarios->getIterator(); it->hasCurrent(); it->next()) {
        Usuario *u = dynamic_cast<Usuario *>(it->getCurrent());
        if (u->getCorreoElectronico() == email) {
            cout << "Error: Ya existe un usuario con el email: " << email << endl;
            delete it; // Liberar memoria del iterador
            return;
        }
    }

    string pais, ciudad, numero, calle;
    cout << "Ingrese la direccion de la inmobiliaria:" << endl;
    cout << "Pais: ";
    cin >> pais;
    cout << "Ciudad: ";
    cin >> ciudad;
    cout << "Numero: ";
    cin >> numero;
    cout << "Calle: ";
    cin >> calle;

    // Crear la dirección
    dtDireccion * dir = new dtDireccion(pais, ciudad, numero, calle);
    // Dar de alta la inmobiliaria
    Usuario *inm = new Inmobiliaria(email, "", nombre, dir);
    misUsuarios->add(inm);
    cout << "Inmobiliaria '" << nombre << "' dada de alta exitosamente." << endl;
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
        }else{
            Departamento * nuevo = new Departamento(_letraDpt, _codigo);
            Departamentos->add(nuevo);
        }
    }

    Departamento * d = new Departamento(_letraDpt, _codigo);
    Departamentos->add(d);
}

void Sistema::AltaInteresado(string email,string nombre, string apellido, int edad) {
    IIterator * it;
    // Verificar si el usuario actual tiene permisos de Administrador
    if (dynamic_cast<Administrador*>(this->usuarioSesion) == nullptr) {
        cout << "Error: Se requieren permisos de Administrador para dar de alta a un interesado." << endl;
        return;
    }

    // Verificar si ya existe un usuario con el mismo email
    for (it = misUsuarios->getIterator(); it->hasCurrent(); it->next()) {
        Usuario* usuario = dynamic_cast<Usuario*>(it->getCurrent());
        if (usuario->getCorreoElectronico() == email) {
            cout << "Error: Ya existe un usuario con el mismo email." << endl;
            delete it; // Liberar memoria del iterador
            return;
        }
    }

    Usuario* nuevoInteresado = new Interesado(email, "" , nombre, edad, apellido); 
    misUsuarios->add(nuevoInteresado);
    cout << "Interesado '" << nombre << " " << apellido << "' dado de alta exitosamente. Con email" << email << endl;
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


