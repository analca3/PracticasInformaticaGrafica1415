// *********************************************************************
// **
// ** Informática Gráfica, curso 2014-15
// ** 
// **
// ** Práctica 1  (declaraciones públicas)
// **
// *********************************************************************

#ifndef __IG_PRACTICA1_HPP__
#define __IG_PRACTICA1_HPP__

#include <vector>
#include "mallaTVT.hpp"
#include "practica.hpp"

class Practica1 : virtual public Practica
{
public:

   void DibujarObjetos();
   void Inicializar(int argc, char * argv[]);
   void CambioModoDibujo(visualizacion modo_dibujo);
   void CambioModoNormales();
   void CambioColorFijo();
   bool GestionarEvento(unsigned char tecla);

   virtual ~Practica1();

   Practica1();
   Practica1(Practica1 const&);              // No se implementa para evitar copias
   Practica1& operator=(Practica1 const&);   // No se implementa para evitar asignaciones

private:

   MallaTVT * malla;

   vector<float> vertices_ply;
   vector<int> caras_ply;
};

#endif
