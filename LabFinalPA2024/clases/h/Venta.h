#ifndef VENTA_H
#define VENTA_H

#include <iostream>
#include "../../ICollection/collections/List.h"
#include "../../ICollection/interfaces/ICollectible.h"


using namespace std;

class Venta : public ICollectible {
private:
  float precioVenta;
public:
  Venta();
  Venta(float); 
  ~Venta();

  float getPrecioVenta();
  void setPrecioVenta(float);

  void desvincularVenta(string codigoPropiedad);
};

#endif
