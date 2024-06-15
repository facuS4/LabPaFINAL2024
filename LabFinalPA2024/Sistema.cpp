#include "Sistema.h"

Sistema::Sistema() {
    Departamentos = new List();
    misUsuarios = new List();
    Edificios = new List();
    usuarioSesion = nullptr;
}

Sistema::~Sistema() {
}

void Sistema::mostrarPropiedades(string codigo, Zona * zona){

    IIterator * it;
    for(it = zona->getPropiedades()->getIterator();it->hasCurrent();it->next()){
        Propiedad * p = (Propiedad *) it->getCurrent();
        if (p!=nullptr && p->getCodigo()==codigo){
            cout << "Codigo: " << p->getCodigo() << endl;
            cout << "Direccion: " << p->getDireccion()->getCalle() << " " <<p->getDireccion()->getCiudad()<< " " <<p->getDireccion()->getNumero() << " " <<p->getDireccion()->getPais() << endl;
            cout << "Dormitorios: " << p->getDormitorios() << endl;
            cout << "Ambientes: " << p->getAmbientes() << endl;
            cout << "Banios: " << p->getBanios() << endl;
            cout << "Garage: " << (p->getGarage() ? "Si" : "No") << endl;
            cout << "Superficie Edificada: " << p->getMedif() << " m2" << endl;
            cout << "Superficie Total: " << p->getMetrosTotales() << " m2" << endl;
        }

    }

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
    
    //ENCUENTRA LA PROPIEDAD
    Zona * zone = nullptr;
    Propiedad * propi =nullptr;
    bool out=false;
    for (IIterator * it1= Departamentos->getIterator(); it1->hasCurrent() && !out ;it1->next()){
        Departamento * dep = dynamic_cast<Departamento*>(it1->getCurrent());
        for(IIterator * it2= dep->getZonas()->getIterator(); it2->hasCurrent() && !out;it2->next()){
            zone = dynamic_cast<Zona*>(it2->getCurrent());
            for (IIterator * it3= zone->getPropiedades()->getIterator(); it3->hasCurrent() && !out;it3->next()){
                propi = dynamic_cast<Propiedad*>(it3->getCurrent());
                if(propi->getCodigo()==codigo)
                    out=true;
                else
                    propi=nullptr;
            }
        }
    }
    // CORTA SI NO ENCUENTRA NADA
    if(propi==nullptr){
        cout << "error para encontrar propiedad"<<endl;
        return;
    }
        
    // BUSCA EN VENTAS Y ALQUILER
    bool encontrado = false;
    if (this->getUsuarioActual()!=nullptr){
        Inmobiliaria * i = dynamic_cast<Inmobiliaria*>(this->getUsuarioActual());
        for(IIterator * it1 = i->getVentas()->getIterator();it1->hasCurrent() && !encontrado;it1->next()){
            Venta * vents = dynamic_cast<Venta *>(it1->getCurrent());
            if (vents->getPropiedad()->getCodigo()==codigo){
                encontrado=true;
            }
        }
        for(IIterator * it1 = i->getAlquileres()->getIterator();it1->hasCurrent() && !encontrado;it1->next()){
            Alquiler * alqui = dynamic_cast<Alquiler *>(it1->getCurrent());
            if (alqui->getPropiedad()->getCodigo()==codigo){
                encontrado=true;
            }
        }
        if (!encontrado){
            cout << "LA PROPIEDAD NO ES TUYA"<< endl;
            return;
        }
    for(IIterator * it1=this->getUsuarios()->getIterator();it1->hasCurrent();it1->next()){
        Inmobiliaria * i = dynamic_cast<Inmobiliaria*>(it1->getCurrent());
        if (i!=nullptr){
            for(IIterator * it2=i->getVentas()->getIterator();it2->hasCurrent();it2->next()){
                Venta * vents2 = dynamic_cast<Venta*>(it2->getCurrent());
                if(vents2->getPropiedad()->getCodigo()==codigo){
                    
                    ICollection * nuevo = new List();
                    for(IIterator * it3=i->getVentas()->getIterator();it3->hasCurrent();it3->next()){
                        Venta * ventas3=dynamic_cast<Venta*>(it3->getCurrent());
                        if (ventas3->getPropiedad()->getCodigo()!=vents2->getPropiedad()->getCodigo())
                        {
                            nuevo->add(ventas3);
                        }
                        
                    }
                    i->IcolVentas(nuevo);
                    //cout << "no termine" << endl;
                    delete vents2;
                }
            }
            for(IIterator * it2=i->getAlquileres()->getIterator();it2->hasCurrent();it2->next()){
                Alquiler * alquiler2 = dynamic_cast<Alquiler*>(it2->getCurrent());
                if(alquiler2->getPropiedad()->getCodigo()==codigo){
                    
                    ICollection * nuevo = new List();
                    for(IIterator * it3=i->getAlquileres()->getIterator();it3->hasCurrent();it3->next()){
                        Alquiler * alquiler3=dynamic_cast<Alquiler*>(it3->getCurrent());
                        if (alquiler3->getPropiedad()->getCodigo()!=alquiler2->getPropiedad()->getCodigo())
                        {
                            nuevo->add(alquiler3);
                        }
                        
                    }
                    i->IcolAlquileres(nuevo);
                    //cout << "no termine" << endl;
                    delete alquiler2;
                }
            }
        }
    }
        //ELIMINA CONVERSACIONES
    propi->eliminarVinculosPropiedad();
    zone->EliminarPropiedad(propi);
    delete propi;
    cout << "eliminado" << endl;
    }
    return;
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
        if (d!=nullptr && d->getLetradpto() == letraDpto){
            for(IIterator * it3 = d->getZonas()->getIterator(); it3->hasCurrent(); it3->next()){
            Zona * z = (Zona *) it3->getCurrent();
            cout << "Codigo: " << z->getCodigo() << endl;
            }
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


Zona * Sistema::SelecionarZona(string codigo, Departamento * depto) {

    IIterator * it;
    IIterator * it3;
    for(it = depto->getZonas()->getIterator();it->hasCurrent();it->next())
    {
        Zona * z = (Zona *) it->getCurrent();
        if(z!=nullptr && z->getCodigo()==codigo){
            for(it3 = z->getPropiedades()->getIterator(); it3->hasCurrent(); it3->next()){
            Propiedad * p = (Propiedad *) it3->getCurrent();
            cout << "Codigo: " << p->getCodigo() << endl;
            
            }
            delete it;
            delete it3;
            return z;
        }
    }
    return nullptr;
}
/*void Sistema::SelecionarZona(string codigo) {
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
}*/

bool Sistema::boolSeleccionarZona(string codigo) {
    cout << codigo;
    return false;
}

void Sistema::ListarEdificio() {
    IIterator * it;
    for(it=Edificios->getIterator();it->hasCurrent();it->next()){
        Edificio * e = dynamic_cast<Edificio *>(it->getCurrent()); 
        cout << "Nombre del Edificio: " << e->getNombre() << endl;
    }
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

void Sistema::altaPropiedad(){
    Inmobiliaria * i = dynamic_cast<Inmobiliaria *>(this->usuarioSesion);
    Sistema::listarDepartamentos();
    string letra; //Falta cout de indique la Letra
    getline(cin,letra);
    Departamento * d = seleccionarDepartamento(letra[0]);
    if (d==nullptr)
        return;
    d->listarZonas();
    string codigoz; ////Falta cout de indique el codigo
    getline(cin, codigoz);
    Zona * z = SelecionarZona(codigoz, d);
    string casa;
    int ambientes, cuartos, banios;
    bool garaje;
    string pais, ciudad, numero, calle, garajesino, codigop;
    float mtEdifi, mtEspacioverd, mtTotales;
    
    cout << "Elija 1 si quiere crear una casa o 2 para crear un apartamento" << endl;
    getline(cin, casa);

    cout << "Por favor, ingrese el codigo" << endl;
    getline(cin, codigop);

    IIterator * it;
    for (it = z ->getPropiedades()->getIterator();it->hasCurrent(); it->next()){
        Propiedad * p = (Propiedad * ) it->getCurrent();
        
        if (p->getCodigo() == codigop ){
            cout << "Ya existe dicho codigo de propiedad" << endl;
            return;
         }
    }

    cout << "Por favor, ingrese la cantidad de ambientes" << endl;
    string sstring;
    getline(cin, sstring);
    if(sstring[0]<48 || sstring[0]>57){
        cout << "bruh" << endl;
    }
    ambientes=stoi(sstring);


    cout << "Por favor, ingrese la cantidad de cuartos" << endl;
    getline(cin, sstring);
    if(sstring[0]<48 || sstring[0]>57){
        cout << "bruh" << endl;
    }
    cuartos=stoi(sstring);

    cout << "Por favor, ingrese la cantidad de banios" << endl;
    getline(cin, sstring);
    if(sstring[0]<48 || sstring[0]>57){
        cout << "bruh" << endl;
    }
    banios=stoi(sstring);

    cout << "¿Esta propiedad cuenta con Garaje?" << endl;
    getline(cin, garajesino);
    if(garajesino == "SI" || garajesino == "si"){
        garaje = true;
    }
    else {
        garaje = false;
        cout << "No hay garaje para ti. Besos" <<endl;
    }

    cout << "Por favor, ingrese el pais" << endl;
    getline(cin, pais);

    cout << "Por favor, ingrese la ciudad" << endl;
    getline(cin, ciudad);

    cout << "Por favor, ingrese el numero" << endl;
    getline(cin, numero);

    cout << "Por favor, ingrese la calle" << endl;
    getline(cin, calle);

    dtDireccion * dir = new dtDireccion(pais, ciudad, numero, calle);   

    cout << "Por favor, ingrese la cantidad de metros edificados" << endl;
    getline(cin, sstring);
    if(sstring[0]<48 || sstring[0]>57){
        cout << "bruh" << endl;
    }
    mtEdifi=stoi(sstring);

    cout << "Por favor, ingrese la cantidad de metros totales" << endl;
    getline(cin, sstring);
    if(sstring[0]<48 || sstring[0]>57){
        cout << "bruh" << endl;
    }
    mtTotales=stoi(sstring);

    //HASTA ACA FUE MI REVISION DE ESTA FUNCION -- FIRMA JANO
    
    if(casa=="1"){ //crear la casa
        int opcion;
        cout << "Por favor, ingrese la cantidad de metros con espacios verdes" << endl;
        cin >> mtEspacioverd; 
        Casa * c = new Casa(codigop,cuartos,ambientes,banios,garaje,dir,mtEdifi,mtTotales,mtEspacioverd);

        cout << "Su casa esta en alquiler o en venta, ponga 1 si esta en alquiler, ponga 2 si esta en venta" << endl;
        cin >> opcion;
        if(opcion == 1){
            i->getAlquileres()->add(c);
        }else if(opcion == 2){
            i->getVentas()->add(c);
        }

        z->getPropiedades()->add(c); //-> Agregar luego de esto, la casa a la coleccion de propiedades de la zona z.
    }   
    else if(casa=="2"){ //crear apartamento
        int opcion2, opcion3;
        string nombre;
        cout << "Desea elegir un edificio ya existente o crear uno nuevo? Ingrese 1 para elegir uno existente o 2 para crear uno nuevo" << endl;
        cin >> opcion2;
        if(opcion2 == 1){
            Sistema::ListarEdificio();
            cout << "Por favor, ingrese el nombre del edificio" << endl;
            Edificio * e = SeleccionarEdificio("nombre"); //Falta cout de indique el nombre
            if(e==nullptr){
                cout << "No se encontro el edificio" << endl;
                return;
            }
            Apartamento * a = new Apartamento(codigop,cuartos,ambientes,banios,garaje,dir,mtEdifi,mtTotales,true,e);
            z->getPropiedades()->add(a); //-> Agregar luego de esto, el apartamento a la coleccion de propiedades de la zona z.
            cout << "Su apartamento esta en alquiler o en venta, ponga 1 si esta en alquiler, ponga 2 si esta en venta" << endl;
            cin >> opcion3;
            if(opcion3 == 1){
                i->getAlquileres()->add(a);
            }else if(opcion3 == 2){
                i->getVentas()->add(a);
            }
        }else if(opcion2 == 2){
            string nombreEdificio;
            cout << "Por favor, ingrese el nombre del edificio" << endl;
            getline(cin, nombreEdificio);
            cout << "Por favor, ingrese la cantidad de pisos" << endl;
            int pisos;
            cin >> pisos;
            cout << "Por favor, ingrese los gastos comunes" << endl;
            int gastosComunes;
            cin >> gastosComunes;
            Edificio * e = new Edificio(nombreEdificio,pisos,gastosComunes);
            Apartamento * a = new Apartamento(codigop,cuartos,ambientes,banios,garaje,dir,mtEdifi,mtTotales,true,e);
            z->getPropiedades()->add(a); //-> Agregar luego de esto, el apartamento a la coleccion de propiedades de la zona z.
            cout << "Su apartamento esta en alquiler o en venta, ponga 1 si esta en alquiler, ponga 2 si esta en venta" << endl;
            cin >> opcion3;
            if(opcion3 == 1){
                i->getAlquileres()->add(a);
            }else if(opcion3 == 2){
                i->getVentas()->add(a);
            }
        }
    } 
    else{
        cout << "No ha ingresado un valor correcto " << endl;
        return;
    }


}

Edificio * Sistema::SeleccionarEdificio(string nombre){
    IIterator * it;
    for(it = Edificios->getIterator();it->hasCurrent();it->next()){
        Edificio * e = (Edificio *) it->getCurrent();
        if(e!=nullptr && e->getNombre()==nombre){
            return e;
        }
    }
    return nullptr;
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



   /*Zona * Sistema::SelecionarZona(string codigo, Departamento * depto) {

    IIterator * it;
    IIterator * it3;
    it = depto->getZonas()->getIterator();
    for(it;it->hasCurrent();it->next())
    {
        Zona * z = (Zona *) it->getCurrent();
        if(z!=nullptr && z->getCodigo()==codigo){
            for(it3 = z->getPropiedades()->getIterator(); it3->hasCurrent(); it3->next()){
            Propiedad * p = (Propiedad *) it3->getCurrent();
            cout << "Codigo: " << p->getCodigo() << endl;
            return z;
            }
        }
    }
}*/


void Sistema::modificarPropiedad(){
    Inmobiliaria* i = dynamic_cast<Inmobiliaria*>(this->usuarioSesion);
    if (i == nullptr) {
        cout << "Error: No ha iniciado sesión como usuario inmobiliaria." << endl;
        return;
    }
    Sistema::listarDepartamentos();
    char letra;
    cout << "Por favor, ingrese la letra del Departamento" << endl;
    cin>>letra;
    Departamento * d = seleccionarDepartamento(letra);
    if (d==nullptr)
        return;
    d->listarZonas();
    string codigoz;
    cout << "Por favor, ingrese el codigo de la Zona" << endl;
    getline(cin, codigoz);
    Zona * z = SelecionarZona(codigoz, d);
    
    int ambientes, cuartos, banios;
    bool garaje;
    string pais, ciudad, numero, calle, garajesino, codigop;
    float mtEdifi, mtEspacioverd, mtTotales;
    Propiedad* propiedad = nullptr;
    
    cout << "Por favor, ingrese el codigo" << endl;
    cin >> codigop;

    IIterator * it;
    for (it = z ->getPropiedades()->getIterator();it->hasCurrent(); it->next()){
        Propiedad * p = (Propiedad * ) it->getCurrent();
        
        if (p->getCodigo() == codigop ){
            propiedad = p;
            break;
         } 
        
    }
    if (propiedad == nullptr){
        cout << "No existe dicha propiedad"<< endl;
        return;
    }

    cout << "Por favor, ingrese la nueva cantidad de ambientes" << endl;
    cin >> ambientes;
    propiedad->setAmbientes(ambientes);

    cout << "Por favor, ingrese la nueva cantidad de cuartos" << endl;
    cin >> cuartos;
    propiedad->setDormitorios(cuartos);

    cout << "Por favor, ingrese la nueva cantidad de banios" << endl;
    cin >> banios;
    propiedad->setBanios(banios);

    cout << "¿Esta propiedad cuenta con Garaje? (si/no)" << endl;
    cin >> garajesino;
    garaje = (garajesino == "si");
    propiedad->setGarage(garaje);

    cout << "Por favor, ingrese el nuevo pais" << endl;
    cin.ignore(); // Limpiar el buffer
    getline(cin, pais);

    cout << "Por favor, ingrese la nueva ciudad" << endl;
    getline(cin, ciudad);

    cout << "Por favor, ingrese el nuevo numero" << endl;
    getline(cin, numero);

    cout << "Por favor, ingrese la nueva calle" << endl;
    getline(cin, calle);

    dtDireccion* nuevaDir = new dtDireccion(pais, ciudad, numero, calle);
    propiedad->setDireccion(nuevaDir);

    cout << "Por favor, ingrese la nueva cantidad de metros edificados" << endl;
    cin >> mtEdifi;
    propiedad->setMedif(mtEdifi);

    cout << "Por favor, ingrese la nueva cantidad de metros totales" << endl;
    cin >> mtTotales;
    propiedad->setMetrosTotales(mtTotales);

    cout << "La propiedad está en alquiler o en venta, ponga 1 si está en alquiler, ponga 2 si está en venta" << endl;
    int opcion;
    cin >> opcion;

    if(opcion == 1  || opcion == 2){

        // Quitar la propiedad de la colección actual
        if (i->getAlquileres()->member(propiedad)) {
            i->getAlquileres()->remove(propiedad);
        } else if (i->getVentas()->member(propiedad)) {
            i->getVentas()->remove(propiedad);
        }

        // Agregar la propiedad a la nueva colección según la opción seleccionada
        if (opcion == 1) {
            i->getAlquileres()->add(propiedad);
        } 
        else if (opcion == 2) {
            i->getVentas()->add(propiedad);
        }

    }
    else{
        cout << "No ingreso una opcion correcta, queda en la misma situacion" << endl;
    }

    Casa * casa = dynamic_cast<Casa*>(propiedad);
    if (casa != nullptr) {
        cout << "Por favor, ingrese la nueva cantidad de metros con espacios verdes" << endl;
        cin >> mtEspacioverd;
        casa->setMetrosVerdes(mtEspacioverd);
    }
    else {
        Apartamento* apartamento = dynamic_cast<Apartamento*>(propiedad);
        if (apartamento != nullptr) {
            // Debo agregar lo correspondiente a Apartamento: disponibilidad y ver tema de Edificio.
        }
    }

    cout << "La propiedad ha sido modificada exitosamente." << endl;

}

// ELIMINAR PROPIEDAD
// PRIMERO VOY A VER SI LA INMOBILIARIA TIENE LA PROPIEDAD
// SEGUNDO LA BUSCA PROPIEDAD Y LA DESVINCULA DE TODO

