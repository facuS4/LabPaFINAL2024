#include <iostream>
#include <string>
#include <set>

#include "SistemaFactory.h"
#include "Sistema.h"
#include "ISistema.h"

// FIN DE LOS INCLUUUUUUUUUUUUUDES

class Inmobiliaria;
using namespace std;

ISistema *sis = SistemaFactory::crearSistema();

//FUNCIOOOOOOOOOOOOOOOOOOOOOONESSSSSSSSSSSSSSSSSSS

bool emailcheck(std::string email) {

  if (email.length() < 3) {
    return false;
  }

  bool at = false;

  for (size_t i = 0; i < email.length(); i++) {

    if (email[i] == '@') {
      at = true;

      if (i == 0 || i == email.length() - 1) {
        return false;
      }
    }
  }

  return at;
}

//FIN DE LAS FUNCIOOOOOOOOOOOOOOOOOOOOOOOOOOOOONES




















// MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAIN
int main()
{



  bool in = true;
  int tipoDeUsuario = -1;




// PARTE DE HARCODEAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADO
  dtDireccion *ladir;

  float x= 10;
  //LA FECHA//
  dtFecha * lafecha = new dtFecha(1,2,3);
  //LA DIRRRR///
  ladir = new dtDireccion("Bosnia", "Mintx", "0032", "Boris Salvatore");
  //la diiiiiirrrr////

  // EDIFICIOS HARDCODEADOS//

  Edificio * ed1 = new Edificio("itsedificio1",5,x);
  Edificio * ed2 = new Edificio("itsedificio2",5,x);
  Edificio * ed3 = new Edificio("itsedificio3",5,x);

  // PROPIEDADES HARDCODEADAS//

//(string codigo, int dormitorios, int ambientes, int banios, bool garage,dtDireccion * direccion, float medif, float metrosTotales, bool disponible)
  Casa * casita1 = new Casa("itscodigocasa112", 2, 2, 2, true, ladir, x, x*2, x);
  Casa * casita2 = new Casa("itscodigocasa233", 2, 2, 2, true, ladir, x, x*2, x);
  Casa * casita3 = new Casa("itscodigocasa322", 2, 2, 2, true, ladir, x, x*2, x);
  Apartamento * ap1 = new Apartamento("itscodapartamento",2,2,2,true,ladir,2,2,true,ed1);
  Apartamento * ap2 = new Apartamento("codloco",2,2,2,true,ladir,2,2,true,ed2);
  Apartamento * ap3 = new Apartamento("codigoouyes",2,2,2,true,ladir,2,2,false,ed3);
  Conversacion * convo=new Conversacion();
  Mensaje * mensaje=new Mensaje(lafecha,"hola como andas");
  convo->AgregarMensaje(mensaje);
  casita1->setConvo(convo);
  ap2->setConvo(convo);


  // ZONAS HARDCODEADAS //
  Zona *ZonaSurSanJose = new Zona("sur1","SanJoseSur");
  Zona *ZonaNorteSanJose = new Zona("Norte1","SanJoseNorte");
  Zona *ZonaSurColonia = new Zona("sur2","ColoniaSur");
  Zona *ZonaNorteColonia = new Zona("Norte2","ColoniaNorte");
  Zona *ZonaSurMontevideo = new Zona("Sur3","MontevideoSur");
  Zona *ZonaNorteMontevideo = new Zona("Norte3","MontevideoNorte");

  // DEPARTAMENTOS HARDCODEADOS //
  Departamento *SanJose = new Departamento('A', "San Jose");
  Departamento *Colonia = new Departamento('B', "Colonia");
  Departamento *Montevideo = new Departamento('C', "Montevideo");

  //ANIADIRLOS//

  ZonaSurColonia->setPropiedades(casita1);
  ZonaSurSanJose->setPropiedades(casita2);
  ZonaNorteMontevideo->setPropiedades(casita3);
  ZonaSurMontevideo->setPropiedades(ap1);
  ZonaSurSanJose->setPropiedades(ap2);
  ZonaNorteColonia->setPropiedades(ap3);

  SanJose->setZona(ZonaNorteSanJose);
  SanJose->setZona(ZonaSurSanJose);
  Colonia->setZona(ZonaSurColonia);
  Colonia->setZona(ZonaNorteColonia);
  Montevideo->setZona(ZonaNorteMontevideo);
  Montevideo->setZona(ZonaSurMontevideo);

  sis->setDepartamento(SanJose);
  sis->setDepartamento(Colonia);
  sis->setDepartamento(Montevideo);

  // USUARIOS HARDCODEDEADOS//
  
  Usuario *admin = new Administrador("a@a", "123");
  Inmobiliaria *imn1 = new Inmobiliaria("go@go", "123", "los pepes", ladir);
  Interesado *int1 = new Interesado("pedro@pedro", "123", "pepe", 20, "pepoide");
  Inmobiliaria *inm2 = new Inmobiliaria("mo@mo", "", "oepes", ladir);
  Interesado *int2 = new Interesado("ta@ta", "", "pepe2", 21, "pepoide3");
  sis->altaUsuario(admin);
  sis->altaUsuario(imn1);
  sis->altaUsuario(int1);
  sis->altaUsuario(inm2);
  sis->altaUsuario(int2);
  //ventasss

  Venta * vent=new Venta(2000);
  Alquiler * alqui=new Alquiler(20);
  alqui->setPropiedad(casita1);
  vent->setPropiedad(ap3);
  imn1->setAlquileres(alqui);
  inm2->setVentas(vent);

// FIN DEL HARDCODEAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADO
//
//








//
//
  // ENTRAR AL SISTEMA
  while (in)
  {

    // FACHADA DE SESION
    while (sis->getUsuarioActual() == nullptr)
    {
      sis->Listarusuarios();
      cout << "Puede salir si ingresa" << endl
           << endl;
      cout << "Inicie sesion con su usuario" << endl
           << "Recuerde que no se puede crear usuarios en esta pantalla" << endl
           << endl
           << "Email: ";
      string ingresar;
      getline(cin, ingresar);
      if (ingresar != "")
      {
        IIterator *it = sis->getUsuarios()->getIterator();
        Usuario *utemp;
        while (it->hasCurrent())
        {
          utemp = (Usuario *)it->getCurrent();
          if (utemp->getCorreoElectronico() == ingresar)
          {
            string contra;
            string contraver;
            if (utemp->getContrasenia() == "")
            {
              system("clear");
              cout << "Su usuario no tiene contrasenia" << endl
                   << "Contrasenia: ";

              getline(cin, contra);
            }
            else
            {
              contra = utemp->getContrasenia();
            }
            do
            {
              cout << "Verifique su contrasenia o ingrese vacio para salir" << endl
                   << "Contrasenia: ";
              // cout
              // cout << utemp->getContrasenia() << endl;
              // cout << contra << endl;
              getline(cin, contraver);
              if (contraver == "")
                break;
              if (contraver == contra)
              {
                utemp->setContrasenia(contra);
                sis->setUsuarioActual(utemp);
                break;
              }
              // cout << contraver <<endl;
            } while (true);

            /* if(contraver===contra){

               utemp->setContrasenia(contra);
               sis->setUsuarioActual(utemp);

             }else{
               break;
             }*/
          }
          it->next();
        }
        delete it;
      }
      else
      {
        return 0;
      }
      system("clear");
    }
    cout << sis->getUsuarioActual()->getCorreoElectronico() << " Logeado " << endl
         << endl;
    cout << "Bienvenido al sistema" << endl;

    // FIN DEL INICIO DE LA SESION


















// MENU PRINCIPAL

    Usuario *checker = dynamic_cast<Administrador *>(sis->getUsuarioActual());
    if (checker == nullptr)
    {
      Usuario *checker = dynamic_cast<Inmobiliaria *>(sis->getUsuarioActual());
      if (checker == nullptr)
        tipoDeUsuario = 2;
      else
        tipoDeUsuario = 1;
    }
    else
    {
      tipoDeUsuario = 0;
    }
    // MENU
    while (tipoDeUsuario > -1)
    {

      cout << "<--Menu-->" << endl
           << endl;
      if (tipoDeUsuario == 0)
      {
        cout << "<--Admin-->" << endl
             << endl;
        cout << "1--Alta inmobiliaria--" << endl; // ADMINISTRADOR
        cout << "2--Alta interesado--" << endl;   // ADMINISTRADOR
        cout << "3--Obtener reporte de inmobiliarias--" << endl
             << endl; // ADMINISTRADOR
      }
      if (tipoDeUsuario == 1)
      {

        cout << "<--Inmobiliaria-->" << endl
             << endl;
        cout << "4--Alta edificio--" << endl;       // INMOBILIARIA
        cout << "5--Alta propiedad--" << endl;      // INMOBILIARIA
        cout << "6--Modificar propiedad--" << endl; // INMOBILIARIA
        cout << "7--Eliminar propiedad--" << endl;  // INMOBILIARIA
        cout << "8--Enviar mensaje de inmobiliaria--" << endl
             << endl;                               // INMOBILIARIA
        cout << "9--Consultar propiedad--" << endl; // INMOBILIARIA O INTERESADO
      }
      if (tipoDeUsuario == 2)
      {
        cout << "<--Interesado-->" << endl
             << endl;
        cout << "9--Consultar propiedad--" << endl;          // INMOBILIARIA O INTERESADO
        cout << "0--Enviar mensaje de interesado--" << endl; // INTERESADO
      }
      cout << "<--Salir-->" << endl
           << endl;
      cout << "LOGOUT--Salir de la sesion--" << endl;
      cout << "TURNOFF--Apagar--" << endl;
      string inputmenu = "";
      getline(cin, inputmenu);
      system("clear");
      try
      {
        int num = stoi(inputmenu);
        if ((tipoDeUsuario == 0 && num > 0 && num < 4) || (tipoDeUsuario == 1 && num > 3) || (tipoDeUsuario == 2 && (num == 9 || num == 0)))
        {
          switch (num)
          {
          case 0:
            cout << "placeholder" << endl;
            break;
          case 1:
            cout << "Alta inmobiliaria" << endl;
            while (true)
            {
              string email;
              string nombre;
              string pais;
              string ciudad;
              string numero;
              string calle;
              cout << "email:" << endl;
              getline(cin, email);

              while(!emailcheck(email)){
              cout << "No" << endl;

              getline(cin, email);
              }
              cout << "nombre:" << endl;
              getline(cin, nombre);

              sis->AltaInmobiliaria(email, nombre);
              break;
            }
            break;
          case 2:
            cout << "Alta interesado" << endl;
            while (true)
            {
              string email;
              string nombre;
              string apellido;
              string edad;

              cout << "email:" << endl;
              getline(cin, email);
              while(!emailcheck(email)){
              cout << "No" << endl;

              getline(cin, email);
              }
              cout << "nombre:" << endl;

              getline(cin, nombre);
              cout << "apellido" << endl;

              getline(cin, apellido);

              cout << "edad" << endl;
              

              while (edad.empty() || !isdigit(edad[0])) {
                      cout << "Ingrese la edad: ";
                      getline(cin, edad);
                      if (edad.empty() || !isdigit(edad[0])) {
                          cout << "No valido." << endl;
                      }
                  }

              int edadin = stoi(edad);
              cout << edad << endl;

              sis->AltaInteresado(email,nombre, apellido, edadin);
              break;
            }
            break;
          case 3:
            cout << "placeholder" << endl;
            break;
          case 4:
            
            while(true){


              string nombre;
              string pisos;
              string gastosComunes;
              cout << "nombre" << endl;

              getline(cin, nombre);

              cout << "pisos" << endl;


              while (pisos.empty() || !isdigit(pisos[0])) {
                      cout << "Ingrese la cantidad de pisos: ";
                      getline(cin, pisos);
                      if (pisos.empty() || !isdigit(pisos[0])) {
                          cout << "No valido." << endl;
                      }
                  }

              int pisosin = stoi(pisos);
              cout << "gastos comunes" << endl;


              while (gastosComunes.empty() || !isdigit(gastosComunes[0])) {
                      cout << "Ingrese el valor: ";
                      getline(cin, gastosComunes);
                      if (gastosComunes.empty() || !isdigit(gastosComunes[0])) {
                          cout << "No valido." << endl;
                      }
                  }

              int gastosin = stoi(gastosComunes);

              sis->AltaEdificio(nombre, pisosin, gastosin);

              cout << nombre << " " << pisosin << " " << gastosin<<endl;

              break;
            }

            break;
          case 5:
            break;
          case 6:
            cout << "placeholder" << endl;
            break;
          case 7:
            cout << "placeholder" << endl;
            break;
          case 8:
            cout << "placeholder" << endl;
            break;
          case 9:
            cout << "WORK IN PROGRESS" << endl;
            {
            sis->listarDepartamentos();
            string seldep;
            cout << "Ingresar letra de dpto: "<<endl;
            getline(cin,seldep);
            Departamento * temp= sis->seleccionarDepartamento(seldep[0]);
            if (temp==nullptr)
              break;
            cout << "Ingresar codigo de Zona: "<<endl;
            getline(cin,seldep);
            Zona * tempzona = sis->SelecionarZona(seldep,temp);
            if (tempzona==nullptr)
              break;
            cout << "Ingresar codigo de propiedad: "<<endl;
            getline(cin,seldep);
            sis->mostrarPropiedades(seldep,tempzona);
            }

            break;
          default:
            cout << "placeholder" << endl;
          }
        }
      }
      catch (const invalid_argument &e)
      {
        if (inputmenu == "LOGOUT")
        {
          cout << "placeholder" << endl;
          sis->setUsuarioActual(nullptr);
          break;
        }
        if (inputmenu == "TURNOFF")
        {

          return 0;
        }
      } // FINAL DEL MENU
    }
  } // FINAL DEL WHILE IN

  // FINAL
  system("clear");
  cout << "Nos vemos" << endl;
  admin->~Usuario();
  imn1->~Inmobiliaria();
  int1->~Interesado();
  inm2->~Inmobiliaria();
  int2->~Interesado();
  SanJose->~Departamento();
  Colonia->~Departamento();
  Montevideo->~Departamento();
  ZonaSurSanJose->~Zona();
  ZonaNorteSanJose->~Zona();
  ZonaSurColonia->~Zona();
  ZonaNorteColonia->~Zona();
  ZonaNorteMontevideo->~Zona();
  ZonaSurMontevideo->~Zona();

  return 0;
}

//FINAL DEL MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAIN
