#ifndef VENTA_H
#define VENTA_H

#include <iostream>
#include "../ICollection/Collections/List.h" 

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
