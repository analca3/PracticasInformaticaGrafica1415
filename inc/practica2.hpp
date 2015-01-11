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

#include "MallaTVT.hpp"
#include "practica.hpp"
#include "grafoescena.hpp"


class Practica2 : virtual public Practica
{
public:

   void DibujarObjetos();
   void Inicializar(int argc, char * argv[]);
   void CambioModoDibujo(visualizacion modo_dibujo);
   void CambioModoNormales();
   void CambioColorFijo();
   bool GestionarEvento(unsigned char tecla);
   void Debug();
   void Ayuda(vector<string> & strings_control);

   virtual ~Practica2();

   Practica2();
   Practica2(Practica2 const&);              // No se implementa para evitar copias
   Practica2& operator=(Practica2 const&);   // No se implementa para evitar asignaciones

private:

   MallaTVT * malla;
   vector<float> vertices_ply;

   unsigned N,M;
   string file;

   NodoGrafoEscena * raiz;
};

#endif
