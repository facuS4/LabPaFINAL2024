#include "Sistema.h"

Sistema::Sistema()
{
    Departamentos = new List();
    misUsuarios = new List();
    Edificios = new List();
    usuarioSesion = nullptr;
}

void Sistema::menudedebugging()
{
    string charchar;
    cout << "Ingrese EXIT" << endl;
    getline(cin, charchar);
}

Sistema::~Sistema()
{
}

void Sistema::mostrarPropiedades(string codigo, Zona *zona)
{

    IIterator *it;
    for (it = zona->getPropiedades()->getIterator(); it->hasCurrent(); it->next())
    {
        Propiedad *p = (Propiedad *)it->getCurrent();
        if (p != nullptr && p->getCodigo() == codigo)
        {
            cout << "Codigo: " << p->getCodigo() << endl;
            cout << "Direccion: " << p->getDireccion()->getCalle() << " " << p->getDireccion()->getCiudad() << " " << p->getDireccion()->getNumero() << " " << p->getDireccion()->getPais() << endl;
            cout << "Dormitorios: " << p->getDormitorios() << endl;
            cout << "Ambientes: " << p->getAmbientes() << endl;
            cout << "Banios: " << p->getBanios() << endl;
            cout << "Garage: " << (p->getGarage() ? "Si" : "No") << endl;
            cout << "Superficie Edificada: " << p->getMedif() << " m2" << endl;
            cout << "Superficie Total: " << p->getMetrosTotales() << " m2" << endl;
        }
    }
}

void Sistema::AltaEdificio(string nombre, int pisos, int gastosComunes)
{

    IIterator *it = Edificios->getIterator();
    while (it->hasCurrent())
    {
        Edificio *e = (Edificio *)it->getCurrent();
        if (e->getNombre() == nombre)
        {
            cout << "El edificio ya existe" << endl;
            return;
        }
        it->next();
    }
    delete it;
    Edificio *nuevo = new Edificio(nombre, pisos, gastosComunes);
    Edificios->add(nuevo);
    cout << "Edificio '" << nombre << "' dado de alta exitosamente." << endl;
    return;
}

ICollection *Sistema::getUsuarios()
{
    return this->misUsuarios;
}

void Sistema::setUsuarioActual(Usuario *u)
{
    this->usuarioSesion = u;
}

ICollection *Sistema::getDepartamento()
{
    return this->Departamentos;
}

void Sistema::setDepartamento(Departamento *u)
{
    this->getDepartamento()->add(u);
}

void Sistema::Listarusuarios()
{
    int count = 0;
    int tipoDeUsuario = 0;
    IIterator *it;
    for (it = misUsuarios->getIterator(); it->hasCurrent(); it->next())
    {
        count++;
        Usuario *u = (Usuario *)it->getCurrent();
        Usuario *checker = dynamic_cast<Administrador *>(it->getCurrent());
        if (checker == nullptr)
        {
            Usuario *checker = dynamic_cast<Inmobiliaria *>(it->getCurrent());
            if (checker == nullptr)
                tipoDeUsuario = 2;
            else
                tipoDeUsuario = 1;
        }
        else
        {
            tipoDeUsuario = 0;
        }
        string var;
        if (tipoDeUsuario == 2)
            var = "Interesado ";
        if (tipoDeUsuario == 1)
            var = "Inmobiliaria ";
        if (tipoDeUsuario == 0)
            var = "Administrador ";
        cout << "   -( " << count << " ) " << var << "-" << endl
             << "           - " << u->getCorreoElectronico() << " -" << endl
             << endl;
    }
}

void Sistema::altaUsuario(Usuario *u)
{

    if (this->misUsuarios->member(u))
    {
        cout << "Este usuario ya existe" << endl;
        return;
    }
    misUsuarios->add(u);
    return;
}

Sistema *Sistema::instancia = NULL;

Sistema *Sistema::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new Sistema();
    }
    return instancia;
}

Usuario *Sistema::getUsuarioActual()
{

    return this->usuarioSesion;
}

void Sistema::AltaInmobiliaria(string email, string nombre)
{
    // Verificar si el usuario actual tiene permisos de Administrador
    if (dynamic_cast<Administrador *>(this->usuarioSesion) == nullptr)
    {
        cout << "Error: Se requieren permisos de Administrador para dar de alta una inmobiliaria." << endl;
        return;
    }

    // Verificar si ya existe un usuario con el mismo email
    for (IIterator *it = misUsuarios->getIterator(); it->hasCurrent(); it->next())
    {
        Usuario *u = dynamic_cast<Usuario *>(it->getCurrent());
        if (u->getCorreoElectronico() == email)
        {
            cout << "Error: Ya existe un usuario con el email: " << email << endl;
            delete it; // Liberar memoria del iterador
            return;
        }
    }

    string pais, ciudad, numero, calle;
    cout << "Ingrese la direccion de la inmobiliaria:" << endl;
    cout << "Pais: ";
    getline(cin, pais);
    cout << "Ciudad: ";
    getline(cin, ciudad);
    cout << "Numero: ";
    getline(cin, numero);
    cout << "Calle: ";
    getline(cin, calle);

    // Crear la dirección
    dtDireccion *dir = new dtDireccion(pais, ciudad, numero, calle);
    // Dar de alta la inmobiliaria
    Usuario *inm = new Inmobiliaria(email, "", nombre, dir);
    misUsuarios->add(inm);
    cout << "Inmobiliaria '" << nombre << "' dada de alta exitosamente." << endl;
}

bool Sistema::PropiedadChecker(string codigo)
{
    Zona *zone = nullptr;
    Propiedad *propi = nullptr;
    for (IIterator *it1 = Departamentos->getIterator(); it1->hasCurrent(); it1->next())
    {
        Departamento *dep = dynamic_cast<Departamento *>(it1->getCurrent());
        if (dep == nullptr)
            continue;

        for (IIterator *it2 = dep->getZonas()->getIterator(); it2->hasCurrent(); it2->next())
        {
            zone = dynamic_cast<Zona *>(it2->getCurrent());
            if (zone == nullptr)
                continue;

            for (IIterator *it3 = zone->getPropiedades()->getIterator(); it3->hasCurrent(); it3->next())
            {
                propi = dynamic_cast<Propiedad *>(it3->getCurrent());
                if (propi == nullptr)
                    continue;

                if (propi->getCodigo() == codigo)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

void Sistema::EliminarPropiedad(string codigo)
{

    // ENCUENTRA LA PROPIEDAD
    bool propi = Sistema::PropiedadChecker(codigo);

    if (!propi)
    {
        cout << "ERROR 404" << endl;
        return;
    }

    // BUSCA EN VENTAS Y ALQUILER
    bool encontrado = false;
    if (this->getUsuarioActual() != nullptr)
    {
        Inmobiliaria *i = dynamic_cast<Inmobiliaria *>(this->getUsuarioActual());
        if (i != nullptr)
        {
            encontrado = i->PerteneceAinmobiliaria(codigo);
        }
        else
        {
            cout << "Segmentation fault.......jajajajajjjaja te la creiste" << endl;
        }
        if (!encontrado)
        {
            cout << "LA PROPIEDAD NO ES TUYA" << endl;
            return;
        }
        // SI LA PROPIEDAD ES TUYA SIGUE

        for (IIterator *it1 = this->getUsuarios()->getIterator(); it1->hasCurrent(); it1->next())
        {
            Inmobiliaria *i = dynamic_cast<Inmobiliaria *>(it1->getCurrent());
            if (i != nullptr)
            {
                i->EliminarPropiedad(codigo);
            }
        }
        // ELIMINA CONVERSACIONES

        cout << "eliminado" << endl;
    }
    return;
}

void Sistema::IngresarEmail(string email)
{
    cout << email;
}

void Sistema::ingreasrcontraseniaNueva(string contrasenia)
{
    cout << contrasenia;
}

void Sistema::listarDepartamentos()
{
    IIterator *it;

    for (it = Departamentos->getIterator(); it->hasCurrent(); it->next())
    {
        Departamento *d = (Departamento *)it->getCurrent();

        cout << "Nombre: " << d->getNombre() << endl;
        cout << "Letra: " << d->getLetradpto() << endl;
    }
}

Departamento *Sistema::seleccionarDepartamento(char letraDpto)
{
    IIterator *it;
    for (it = Departamentos->getIterator(); it->hasCurrent(); it->next())
    {
        Departamento *d = (Departamento *)it->getCurrent();
        if (d != nullptr && d->getLetradpto() == letraDpto)
        {
            for (IIterator *it3 = d->getZonas()->getIterator(); it3->hasCurrent(); it3->next())
            {
                Zona *z = (Zona *)it3->getCurrent();
                cout << "Codigo: " << z->getCodigo() << endl;
            }
            return d;
        }
    }
    cout << "No se encontro el departamento" << endl;
    return nullptr;
}

void Sistema::Ultimo5Mensajes()
{
}

void Sistema::SeleccionarConversacionInmobiliaria()
{
    // Verificar si el usuario actual es una Inmobiliaria
    Inmobiliaria *inmobiliaria = dynamic_cast<Inmobiliaria *>(this->usuarioSesion);
    if (!inmobiliaria)
    {
        cout << "Error: Solo los usuarios inmobiliaria pueden enviar mensajes." << endl;
        return;
    }

    ICollection *conversacionesAlquiler = new List();
    ICollection *conversacionesVenta = new List();

    // Listar conversaciones de alquiler
    cout << "Conversaciones Alquiler:" << endl;
    IIterator *it;
    int index = 1;
    for (it = inmobiliaria->getAlquileres()->getIterator(); it->hasCurrent(); it->next())
    {
        Alquiler *a = (Alquiler *)it->getCurrent();
        IIterator *it2;
        for (it2 = a->getPropiedad()->getConversaciones()->getIterator(); it2->hasCurrent(); it2->next())
        {
            Conversacion *c = (Conversacion *)it2->getCurrent();
            if (c != nullptr)
            {
                conversacionesAlquiler->add(c);
                IIterator *it3;
                for (it3 = c->getMensajes()->getIterator(); it3->hasCurrent(); it3->next())
                {
                    Mensaje *m = (Mensaje *)it3->getCurrent();
                    cout << "  Mensaje: " << m->getFecha()->getAnio() << "/" << m->getFecha()->getMes() << "/" << m->getFecha()->getDia() << endl;
                }
                index++;
            }
            else
            {
                cout << "No se encontro la conversacion deseada." << endl;
            }
        }
    }

    // Listar conversaciones de venta
    cout << "Conversaciones Venta:" << endl;
    IIterator *it4;
    for (it4 = inmobiliaria->getVentas()->getIterator(); it4->hasCurrent(); it4->next())
    {
        Venta *v = (Venta *)it4->getCurrent();
        IIterator *it5;
        for (it5 = v->getPropiedad()->getConversaciones()->getIterator(); it5->hasCurrent(); it5->next())
        {
            Conversacion *c2 = (Conversacion *)it5->getCurrent();
            if (c2 != nullptr)
            {
                if (conversacionesAlquiler->member(c2))
                {
                    continue;
                }
                conversacionesVenta->add(c2);
                cout << "Conversacion " << index << " Inmobiliaria: " << c2->getInmobiliaria() << endl;
                IIterator *it6;
                for (it6 = c2->getMensajes()->getIterator(); it6->hasCurrent(); it6->next())
                {
                    Mensaje *m2 = (Mensaje *)it6->getCurrent();
                    cout << "  Mensaje: " << m2->getFecha()->getAnio() << "/" << m2->getFecha()->getMes() << "/" << m2->getFecha()->getDia() << endl;
                }
                index++;
            }
            else
            {
                cout << "No se encontro la conversacion deseada." << endl;
            }
        }
    }

    // Verificar si existen conversaciones
    if (conversacionesAlquiler->isEmpty() && conversacionesVenta->isEmpty())
    {
        cout << "No hay conversaciones disponibles." << endl;
        return;
    }

    // Seleccionar una conversacion
    string opcion;
    cout << "Desea elegir una conversacion de alquiler o de venta? Ingrese 1 para alquiler o 2 para venta: ";

    while (opcion[0] != '1' && opcion[0] != '2')
    {
        cout << "Elija 1 si quiere ver las conversaciones de alquiler o 2 para ver las de venta: ";
        getline(cin, opcion);
    }

    ICollection *conversacionesSeleccionadas = (opcion[0] == '1') ? conversacionesAlquiler : conversacionesVenta;

    if (conversacionesSeleccionadas->isEmpty())
    {
        cout << "No hay conversaciones de " << (opcion[0] == '1' ? "alquiler" : "venta") << " disponibles." << endl;
        return;
    }

    cout << "Conversaciones Disponibles:" << endl;
    int currentIndex = 1;
    for (IIterator *it7 = conversacionesSeleccionadas->getIterator(); it7->hasCurrent(); it7->next(), currentIndex++)
    {
        Conversacion *c3 = (Conversacion *)it7->getCurrent();
        if (c3 == nullptr)
        {
            cout << "No se encontro la conversacion deseada." << endl;
            return;
        }
        cout << "Conversacion " << currentIndex << endl;
        IIterator *it10;
        for (it10 = c3->getMensajes()->getIterator(); it10->hasCurrent(); it10->next())
        {
            Mensaje *m4 = (Mensaje *)it10->getCurrent();
            cout << "  Mensaje: " << m4->getFecha()->getAnio() << "/" << m4->getFecha()->getMes() << "/" << m4->getFecha()->getDia() << endl;
        }
    }

    string opcion2;
    int seleccion = -1;
    while (seleccion < 1 || seleccion >= currentIndex)
    {
        cout << "Seleccione una conversacion ingresando el numero correspondiente: ";
        getline(cin, opcion2);
        try
        {
            seleccion = stoi(opcion2);
        }
        catch (const std::exception &)
        {
            seleccion = -1;
        }
        if (seleccion < 1 || seleccion >= currentIndex)
        {
            cout << "Opcion invalida. Ingrese un numero valido." << endl;
        }
    }

    Conversacion *conversacionSeleccionada = nullptr;

    // Buscar la conversación seleccionada por el índice
    currentIndex = 1;
    for (IIterator *it7 = conversacionesSeleccionadas->getIterator(); it7->hasCurrent(); it7->next(), currentIndex++)
    {
        Conversacion *c = (Conversacion *)it7->getCurrent();
        if (currentIndex == seleccion)
        {
            conversacionSeleccionada = c;
            break;
        }
    }
    this->conversacion = conversacionSeleccionada;
}

void Sistema::enviarMensajeInmobiliaria()
{

    Conversacion *conversacionSeleccionada = this->conversacion;
    if (conversacionSeleccionada == nullptr)
    {
        cout << "No se pudo encontrar la conversación seleccionada." << endl;
        this->conversacion = nullptr;

        return;
    }

    // Listar los últimos 5 mensajes de la conversación seleccionada
    cout << "Ultimos 5 mensajes de la conversacion seleccionada:" << endl;
    IIterator *itMensajes = conversacionSeleccionada->getMensajes()->getIterator();
    int count = 0;
    int offset = conversacionSeleccionada->getMensajes()->getSize();
    while (itMensajes->hasCurrent() && count < 5)
    {
        if (offset > 5)
        {
            offset--;
        }
        else
        {
            Mensaje *m = (Mensaje *)itMensajes->getCurrent();
            cout << "Mensaje: " << m->getTexto() << endl;
            count++;
        }
        itMensajes->next();
    }

    // Ingresar un nuevo mensaje
    string mensajeNuevo;
    cout << "Ingrese su mensaje para la conversacion seleccionada (o presione Enter para omitir): ";
    getline(cin, mensajeNuevo);

    if (!mensajeNuevo.empty())
    {
        // Crear un nuevo mensaje y agregarlo a la conversación seleccionada
        dtFecha *fechaActual = new dtFecha(); // Suponiendo que tienes una clase Fecha
        if (usuarioSesion != nullptr)
            mensajeNuevo = "(-Inmobiliaria: " + usuarioSesion->getCorreoElectronico() + "-) " + mensajeNuevo;
        Mensaje *nuevoMensaje = new Mensaje(fechaActual, mensajeNuevo);
        conversacionSeleccionada->AgregarMensaje(nuevoMensaje); // Suponiendo un método AgregarMensaje en Conversacion
        cout << "Mensaje enviado correctamente." << endl;
        this->conversacion = nullptr;
    }
    this->conversacion = nullptr;
}

void Sistema::AgregarMensaje(string mensaje)
{
    cout << mensaje;
}

void Sistema::CrearMensaje(string mensaje)
{
    cout << mensaje;
}

Zona *Sistema::SelecionarZona(string codigo, Departamento *depto)
{

    IIterator *it;
    IIterator *it3 = nullptr;
    for (it = depto->getZonas()->getIterator(); it->hasCurrent(); it->next())
    {
        Zona *z = (Zona *)it->getCurrent();
        if (z != nullptr && z->getCodigo() == codigo)
        {
            for (it3 = z->getPropiedades()->getIterator(); it3->hasCurrent(); it3->next())
            {
                Propiedad *p = (Propiedad *)it3->getCurrent();
                cout << "Codigo: " << p->getCodigo() << endl;
            }
            delete it;
            delete it3;
            return z;
        }
        else if (z == nullptr)
        {
            cout << "No se encontro la Zona deseada" << endl;
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

bool Sistema::boolSeleccionarZona(string codigo)
{
    cout << codigo;
    return false;
}

void Sistema::ListarEdificio()
{
    IIterator *it;
    for (it = Edificios->getIterator(); it->hasCurrent(); it->next())
    {
        Edificio *e = dynamic_cast<Edificio *>(it->getCurrent());
        cout << "Nombre del Edificio: " << e->getNombre() << endl;
    }
}

void Sistema::altaApartamento(int ambientes)
{
    cout << ambientes;
}

int Sistema::altaApartamento(int, int, int, bool, dtDireccion, int)
{
    return 0;
}

int Sistema::altaCasa(int, int, int, bool, dtDireccion, int, int)
{
    return 0;
}

void Sistema::vincularconInmobiliaria(Propiedad *p)
{
    p->~Propiedad();
}

void Sistema::seleccionarAlquiler(int precio)
{
    cout << precio;
}

void Sistema::seleccionarVenta(int valor, Propiedad *p)
{
    cout << valor;
    p->~Propiedad();
}

void Sistema::AltaDepartamento(char _letraDpt, string _codigo)
{
    IIterator *it;

    for (it = Departamentos->getIterator(); it->hasCurrent(); it->next())
    {
        Departamento *d = (Departamento *)it->getCurrent();
        if (d->getLetradpto() == _letraDpt)
        {
            cout << "Ya existe un departamento con la letra: " << _letraDpt << endl;
            return;
        }
        else
        {
            Departamento *nuevo = new Departamento(_letraDpt, _codigo);
            Departamentos->add(nuevo);
        }
    }

    Departamento *d = new Departamento(_letraDpt, _codigo);
    Departamentos->add(d);
}

void Sistema::AltaInteresado(string email, string nombre, string apellido, int edad)
{
    IIterator *it;
    // Verificar si el usuario actual tiene permisos de Administrador
    if (dynamic_cast<Administrador *>(this->usuarioSesion) == nullptr)
    {
        cout << "Error: Se requieren permisos de Administrador para dar de alta a un interesado." << endl;
        return;
    }

    // Verificar si ya existe un usuario con el mismo email
    for (it = misUsuarios->getIterator(); it->hasCurrent(); it->next())
    {
        Usuario *usuario = dynamic_cast<Usuario *>(it->getCurrent());
        if (usuario->getCorreoElectronico() == email)
        {
            cout << "Error: Ya existe un usuario con el mismo email." << endl;
            delete it; // Liberar memoria del iterador
            return;
        }
    }

    Usuario *nuevoInteresado = new Interesado(email, "", nombre, edad, apellido);
    misUsuarios->add(nuevoInteresado);
    cout << "Interesado '" << nombre << " " << apellido << "' dado de alta exitosamente. Con email" << email << endl;
}

void Sistema::altaPropiedad()
{
    Inmobiliaria *i = dynamic_cast<Inmobiliaria *>(this->usuarioSesion);
    if (i == nullptr)
        return;
    Sistema::listarDepartamentos();
    string letra = "2"; // Falta cout de indique la Letra
    getline(cin, letra);
    Departamento *d = seleccionarDepartamento(letra[0]);
    if (d == nullptr)
        return;
    d->listarZonas();
    string codigoz; ////Falta cout de indique el codigo
    getline(cin, codigoz);
    Zona *z = SelecionarZona(codigoz, d);
    string casa = "poliester";
    int ambientes, cuartos, banios;
    bool garaje;
    string pais, ciudad, numero, calle, garajesino, codigop;
    float mtEdifi, mtEspacioverd;
    while (casa[0] != '1' && casa[0] != '2')
    {
        cout << "Elija 1 si quiere crear una casa o 2 para crear un apartamento" << endl;
        getline(cin, casa);
    }

    cout << "Por favor, ingrese el codigo" << endl;
    getline(cin, codigop);
    bool checker = Sistema::PropiedadChecker(codigop);
    if (checker)
    {
        cout << "Ya existe una propiedad con ese codigo" << endl;
        return;
    }

    IIterator *it;
    for (it = z->getPropiedades()->getIterator(); it->hasCurrent(); it->next())
    {
        Propiedad *p = (Propiedad *)it->getCurrent();

        if (p->getCodigo() == codigop)
        {
            cout << "Ya existe dicho codigo de propiedad" << endl;
            return;
        }
    }

    cout << "Por favor, ingrese la cantidad de ambientes" << endl;
    string sstring;
    getline(cin, sstring);
    if (sstring[0] < 48 || sstring[0] > 57)
    {
        cout << "bruh" << endl;
    }
    ambientes = stoi(sstring);

    cout << "Por favor, ingrese la cantidad de cuartos" << endl;
    getline(cin, sstring);
    if (sstring[0] < 48 || sstring[0] > 57)
    {
        cout << "bruh" << endl;
    }
    cuartos = stoi(sstring);

    cout << "Por favor, ingrese la cantidad de banios" << endl;
    getline(cin, sstring);
    if (sstring[0] < 48 || sstring[0] > 57)
    {
        cout << "bruh" << endl;
    }
    banios = stoi(sstring);

    cout << "¿Esta propiedad cuenta con Garaje?" << endl;
    getline(cin, garajesino);
    if (garajesino == "SI" || garajesino == "si")
    {
        garaje = true;
    }
    else
    {
        garaje = false;
        cout << "No hay garaje para ti. Besos" << endl;
    }

    cout << "Por favor, ingrese el pais" << endl;
    getline(cin, pais);

    cout << "Por favor, ingrese la ciudad" << endl;
    getline(cin, ciudad);

    cout << "Por favor, ingrese el numero" << endl;
    getline(cin, numero);

    cout << "Por favor, ingrese la calle" << endl;
    getline(cin, calle);

    dtDireccion *dir = new dtDireccion(pais, ciudad, numero, calle);

    cout << "Por favor, ingrese la cantidad de metros edificados" << endl;
    getline(cin, sstring);
    while (sstring[0] < 48 || sstring[0] > 57)
    {
        cout << "bruh me queres romper el lab" << endl;

        getline(cin, sstring);
    }
    mtEdifi = stoi(sstring);

    /*cout << "Por favor, ingrese la cantidad de metros totales" << endl;
    getline(cin, sstring);
    while (sstring[0] < 48 || sstring[0] > 57)
    {
        cout << "bruh no se puede" << endl;

        getline(cin, sstring);
    }
    mtTotales = stoi(sstring);*/

    // HASTA ACA FUE MI REVISION DE ESTA FUNCION -- FIRMA JANO

    if (casa == "1")
    { // crear la casa
        string opcion;

        cout << "Por favor, ingrese la cantidad de metros con espacios verdes" << endl;
        string input = "googoogaagaa";
        getline(cin, input);
        while (input[0] > 57 && input[0] < 48)
        {
            cout << "Intente de nuevo:" << endl;
            getline(cin, input);
        }
        mtEspacioverd = stoi(input);

        Casa *c = new Casa(codigop, cuartos, ambientes, banios, garaje, dir, mtEdifi, mtEdifi + mtEspacioverd, mtEspacioverd, z);
        while (true)
        {
            cout << "Su casa esta en alquiler o en venta, ponga 1 si esta en alquiler, ponga 2 si esta en venta" << endl;
            getline(cin, opcion);
            /// ESTO NO SE PUEDE HACER
            // if(opcion == 1){
            //     i->getAlquileres()->add(c);
            // }else if(opcion == 2){
            //     i->getVentas()->add(c);
            // }
            // string basura;
            // getline(cin,basura);
            if (opcion == "1")
            {
                string input = "pppp";
                float value;
                Alquiler *alquii;
                do
                {
                    cout << "Introduzca el valor del alquiler:" << endl;
                    getline(cin, input);
                } while (input[0] > 57 && input[0] < 48);
                value = stoi(input);
                alquii = new Alquiler(value);
                alquii->setPropiedad(c);
                i->setAlquileres(alquii);
                z->setPropiedades(c);
                return;
            }
            if (opcion == "2")
            {
                string input = "pppp";
                float value;
                Venta *ventaa;
                do
                {
                    cout << "Introduzca el valor de la venta:" << endl;
                    getline(cin, input);
                } while (input[0] > 57 && input[0] < 48);
                value = stoi(input);
                ventaa = new Venta(value);
                ventaa->setPropiedad(c);
                i->setVentas(ventaa);
                // GET OUT!!!
                // agregar a zona
                z->setPropiedades(c);
                return;
            }
        }
    }
    else if (casa == "2")
    { // crear apartamento
        string opcion2, opcion3;
        string nombre;
        cout << "Desea elegir un edificio ya existente o crear uno nuevo? Ingrese 1 para elegir uno existente o 2 para crear uno nuevo" << endl;
        getline(cin, opcion2);
        if (opcion2 == "1")
        {
            Sistema::ListarEdificio();
            string basura;
            cout << "Por favor, ingrese el nombre del edificio" << endl;
            getline(cin, basura);

            Edificio *e = SeleccionarEdificio(basura); // Falta cout de indique el nombre
            if (e == nullptr)
            {
                cout << "No se encontro el edificio o no hay edificios" << endl;
                return;
            }
            Apartamento *a = new Apartamento(codigop, cuartos, ambientes, banios, garaje, dir, mtEdifi, mtEdifi, true, e, z);
            z->setPropiedades(a);
            cout << "Su apartamento esta en alquiler o en venta, ponga 1 si esta en alquiler, ponga 2 si esta en venta" << endl;
            getline(cin, opcion3);
            if (opcion3 == "1")
            {
                string input = "pppp";
                float value;
                Alquiler *alquii;
                // getline(cin, input);
                do
                {
                    cout << "Introduzca el valor del alquiler:" << endl;
                    getline(cin, input);
                } while (input[0] > 57 && input[0] < 48);
                value = stoi(input);
                alquii = new Alquiler(value);
                alquii->setPropiedad(a);
                i->setAlquileres(alquii);
                return;
            }
            else if (opcion3 == "2")
            {
                string input = "pppp";
                float value;
                Venta *ventaa;
                // getline(cin, input);
                do
                {
                    cout << "Introduzca el valor de la venta:" << endl;
                    getline(cin, input);
                } while (input[0] > 57 && input[0] < 48);
                value = stoi(input);
                ventaa = new Venta(value);
                ventaa->setPropiedad(a);
                i->setVentas(ventaa);
                return;
            }
        }
        else if (opcion2 == "2")
        {
            string nombreEdificio;
            string pisos;
            string gastosComunes;
            cout << "nombre del edificio:" << endl;

            getline(cin, nombreEdificio);

            cout << "pisos" << endl;

            while (pisos.empty() || !isdigit(pisos[0]))
            {
                cout << "Ingrese la cantidad de pisos: ";
                getline(cin, pisos);
                if (pisos.empty() || !isdigit(pisos[0]))
                {
                    cout << "No valido." << endl;
                }
            }

            int pisosin = stoi(pisos);
            cout << "gastos comunes" << endl;

            while (gastosComunes.empty() || !isdigit(gastosComunes[0]))
            {
                cout << "Ingrese el valor: ";
                getline(cin, gastosComunes);
                if (gastosComunes.empty() || !isdigit(gastosComunes[0]))
                {
                    cout << "No valido." << endl;
                }
            }

            int gastosin = stoi(gastosComunes);

            this->AltaEdificio(nombreEdificio, pisosin, gastosin);

            Edificio *e = SeleccionarEdificio(nombreEdificio); // Falta cout de indique el nombre
            if (e == nullptr)
            {
                cout << "No se encontro el edificio o no hay edificios" << endl;
                return;
            }
            Apartamento *a = new Apartamento(codigop, cuartos, ambientes, banios, garaje, dir, mtEdifi, mtEdifi, true, e, z);
            z->setPropiedades(a);
            cout << "Su apartamento esta en alquiler o en venta, ponga 1 si esta en alquiler, ponga 2 si esta en venta" << endl;
            getline(cin, opcion3);
            if (opcion3 == "1")
            {
                string input = "pppp";
                float value;
                Alquiler *alquii;
                do
                {
                    cout << "Introduzca el valor del alquiler:" << endl;
                    getline(cin, input);
                } while (input[0] > 57 && input[0] < 48);
                value = stoi(input);
                alquii = new Alquiler(value);
                alquii->setPropiedad(a);
                i->setAlquileres(alquii);
                return;
            }
            else if (opcion3 == "2")
            {
                string input = "pppp";
                float value;
                Venta *ventaa;
                do
                {
                    cout << "Introduzca el valor de la venta:" << endl;
                    getline(cin, input);
                } while (input[0] > 57 && input[0] < 48);
                value = stoi(input);
                ventaa = new Venta(value);
                ventaa->setPropiedad(a);
                i->setVentas(ventaa);
                return;
            }
        }
    }
    else
    {
        cout << "No ha ingresado un valor correcto " << endl;
        return;
    }
}

Edificio *Sistema::SeleccionarEdificio(string nombre)
{
    IIterator *it;
    for (it = Edificios->getIterator(); it->hasCurrent(); it->next())
    {
        Edificio *e = (Edificio *)it->getCurrent();
        if (e != nullptr && e->getNombre() == nombre)
        {
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

Conversacion *Sistema::getConversacionActual()
{
    return this->conversacion;
}

void Sistema::modificarPropiedad()
{
    Inmobiliaria *i = dynamic_cast<Inmobiliaria *>(this->usuarioSesion);
    if (i == nullptr)
    {
        cout << "Error: No ha iniciado sesión como usuario inmobiliaria." << endl;
        return;
    }
    Sistema::listarDepartamentos();
    char letra;
    cout << "Por favor, ingrese la letra del Departamento" << endl;
    cin >> letra;
    Departamento *d = seleccionarDepartamento(letra);
    if (d == nullptr)
    {
        return;
    }
    d->listarZonas();
    string codigoz;
    cout << "Por favor, ingrese el codigo de la Zona" << endl;
    // getline(cin, codigoz);
    cin >> codigoz;
    Zona *z = SelecionarZona(codigoz, d);
    if (z == nullptr)
    {
        cout << "Codigo de Zona incorrecto" << endl;
        return;
    }
    int ambientes, cuartos, banios;
    bool garaje, disponible;
    string pais, ciudad, numero, calle, garajesino, codigop, disponiblesino;
    float mtEdifi, mtEspacioverd, mtTotales;
    Propiedad *propiedad = nullptr;

    system("clear");
    bool haypropiedades;
    haypropiedades = z->ListarPropiedades();
    if (haypropiedades != true)
    {
        return;
    }
    cout << "Por favor, ingrese el codigo de la propiedad" << endl;
    cin >> codigop;

    IIterator *it;
    for (it = z->getPropiedades()->getIterator(); it->hasCurrent(); it->next())
    {
        Propiedad *p = (Propiedad *)it->getCurrent();

        if (p->getCodigo() == codigop)
        {
            if (!i->PerteneceAinmobiliaria(codigop))
            {
                cout << endl
                     << "Esta propiedad no es tuya" << endl;
                // Sistema::menudedebugging();
                return;
            }
            propiedad = p;
            break;
        }
    }
    if (propiedad == nullptr)
    {
        cout << "No existe dicha propiedad" << endl;
        return;
    }

    cout << "Por favor, ingrese la nueva cantidad de ambientes" << endl;
    cin >> ambientes;
    propiedad->setAmbientes(ambientes);

    system("clear");

    cout << "Por favor, ingrese la nueva cantidad de cuartos" << endl;
    cin >> cuartos;
    propiedad->setDormitorios(cuartos);

    system("clear");

    cout << "Por favor, ingrese la nueva cantidad de banios" << endl;
    cin >> banios;
    propiedad->setBanios(banios);

    system("clear");

    cout << "¿Esta propiedad cuenta con Garaje? (si/no)" << endl;
    cin >> garajesino;
    garaje = (garajesino == "si");
    propiedad->setGarage(garaje);
    if (garajesino != "si")
    {
        cout << "La propiedad no cuenta con garaje" << endl;
    }

    cout << "Por favor, ingrese el nuevo pais" << endl;
    cin.ignore(); // Limpiar el buffer
    getline(cin, pais);

    cout << "Por favor, ingrese la nueva ciudad" << endl;
    getline(cin, ciudad);

    cout << "Por favor, ingrese el nuevo numero" << endl;
    getline(cin, numero);

    cout << "Por favor, ingrese la nueva calle" << endl;
    // cin.ignore(); // Limpiar el buffer
    getline(cin, calle);

    dtDireccion *nuevaDir = new dtDireccion(pais, ciudad, numero, calle);
    propiedad->setDireccion(nuevaDir);

    system("clear");
    // cin.ignore(); // Limpiar el buffer

    cout << "Por favor, ingrese la nueva cantidad de metros edificados" << endl;
    cin >> mtEdifi;
    propiedad->setMedif(mtEdifi);

    cout << "Por favor, ingrese la nueva cantidad de metros totales" << endl;
    cin >> mtTotales;
    propiedad->setMetrosTotales(mtTotales);

    cout << "La propiedad está en alquiler o en venta, ponga 1 si está en alquiler, ponga 2 si está en venta" << endl;
    int opcion;
    cin >> opcion;

    if (opcion == 1 || opcion == 2)
    {

        // Quitar la propiedad de la colección actual
        if (i->getAlquileres()->member(propiedad))
        {
            i->getAlquileres()->remove(propiedad);
        }
        else if (i->getVentas()->member(propiedad))
        {
            i->getVentas()->remove(propiedad);
        }

        // Agregar la propiedad a la nueva colección según la opción seleccionada
        if (opcion == 1)
        {
            // i->getAlquileres()->add(propiedad);
            string input = "pppp";
            float value;
            Alquiler *alquii;
            do
            {
                cout << "Introduzca el valor del alquiler:" << endl;
                cin.ignore(); // Limpiar el buffer
                getline(cin, input);
            } while (input[0] > 57 && input[0] < 48);

            value = stoi(input);
            alquii = new Alquiler(value);
            alquii->setPropiedad(propiedad);
            i->setAlquileres(alquii);
        }
        else if (opcion == 2)
        {
            // i->getVentas()->add(propiedad);
            string input = "pppp";
            float value;
            Venta *ventaa;
            do
            {
                cout << "Introduzca el valor de la venta:" << endl;
                cin.ignore(); // Limpiar el buffer
                getline(cin, input);
            } while (input[0] > 57 && input[0] < 48);
            value = stoi(input);
            ventaa = new Venta(value);
            ventaa->setPropiedad(propiedad);
            i->setVentas(ventaa);
        }
    }
    else
    {
        cout << "No ingreso una opcion correcta, queda en la misma situacion" << endl;
    }

    Casa *casa = dynamic_cast<Casa *>(propiedad);
    if (casa != nullptr)
    {
        cout << "Por favor, ingrese la nueva cantidad de metros con espacios verdes" << endl;
        cin >> mtEspacioverd;
        casa->setMetrosVerdes(mtEspacioverd);

        system("clear");
    }
    else
    {
        Apartamento *apartamento = dynamic_cast<Apartamento *>(propiedad);
        if (apartamento != nullptr)
        {
            cout << "¿Este apartamento se encuentra disponible? (si/no)" << endl;
            cin >> disponiblesino;
            system("clear");
            disponible = (disponiblesino == "si");
            apartamento->setDisponible(disponible);
            if (disponiblesino != "si")
            {
                cout << "El apartamento no se encuentra disponible" << endl;
            }
        }
    }

    cout << endl
         << "La propiedad ha sido modificada exitosamente." << endl;
}

// ELIMINAR PROPIEDAD
// PRIMERO VOY A VER SI LA INMOBILIARIA TIENE LA PROPIEDAD
// SEGUNDO LA BUSCA PROPIEDAD Y LA DESVINCULA DE TODO
