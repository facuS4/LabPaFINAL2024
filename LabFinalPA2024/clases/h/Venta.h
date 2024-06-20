#ifndef VENTA_H
#define VENTA_H

class Propiedad;
class Alquiler;
class Departamento;
class Zona;

#include <iostream>
#include "../../ICollection/collections/List.h"
#include "../../ICollection/interfaces/ICollectible.h"
#include "./Propiedad.h"
#include "./Departamento.h"




using namespace std;

class Venta : public ICollectible {
private:
  float precioVenta;
  Propiedad * p;
public:
  Venta();
  Venta(float); 
  ~Venta();
  void setPropiedad(Propiedad * pp);
  Propiedad * getPropiedad();

  float getPrecioVenta();
  void setPrecioVenta(float);

  void ObtenerReporteInmobiliaria3();

  void desvincularVenta(string codigoPropiedad);
};

#endif
