#include <iostream>
#include <string>
#include <set>

#include "SistemaFactory.h"
#include "Sistema.h"
#include "ISistema.h"
class Inmobiliaria;
using namespace std;

ISistema *sis = SistemaFactory::crearSistema();

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


int main()
{

  bool in = true;
  int tipoDeUsuario = -1;
  /*Usuario::Usuario(string email, string password){
CorreoElectronico = email;
Contrasenia = password;
}*/
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

  // USUARIOS HARDCODEDEADOS//
  dtDireccion *ladir;
  ladir = new dtDireccion("Bosnia", "Mintx", "0032", "Boris Salvatore");
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

              //getline(cin, pais);
              //cout << "ciudad:" << endl;

              //getline(cin, ciudad);
              //cout << "numero:" << endl;

              //getline(cin, numero);
              //cout << "calle:" << endl;

              //getline(cin, calle);
              //dir = new dtDireccion(pais, ciudad, numero, calle);
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
            cout << "placeholder" << endl;
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
            cout << "placeholder" << endl;
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
