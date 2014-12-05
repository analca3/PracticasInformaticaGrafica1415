// *********************************************************************
// **
// ** Informática Gráfica, curso 2014-15
// ** 
// **
// ** Práctica 2  (declaraciones públicas)
// **
// *********************************************************************

#ifndef __IG_PRACTICA2_HPP__
#define __IG_PRACTICA2_HPP__

#include <vector>
#include "mallaTVT.hpp"
#include "practica.hpp"


class Practica2 : virtual public Practica
{
public:

   void DibujarObjetos();
   void Inicializar(int argc, char * argv[]);
   void CambioModoDibujo(visualizacion modo_dibujo);
   void CambioModoNormales();
   void CambioColorFijo();

   virtual ~Practica2() {};

   Practica2() {};

   Practica2(Practica2 const&);

private:

   MallaTVT * malla;
   vector<float> vertices_ply;
};

#endif
