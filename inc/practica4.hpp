// *********************************************************************
// **
// ** Informática Gráfica, curso 2014-15
// ** 
// **
// ** Práctica 4  (declaraciones públicas)
// **
// *********************************************************************

#ifndef __IG_PRACTICA4_HPP__
#define __IG_PRACTICA4_HPP__

#include "practica.hpp"
#include "tuplas.hpp"
#include "grafoescena.hpp"
#include "FuenteLuz.hpp"
#include "Material.hpp"

class Practica4 : virtual public Practica
{
public:

   void DibujarObjetos();
   void Inicializar(int argc, char * argv[]);
   void EnciendeLuces();
   void CambioModoDibujo(visualizacion modo_dibujo);
   void CambioModoNormales();

   void CambioColorFijo();
   bool GestionarEvento(unsigned char tecla);
   void ClickRaton(int x, int y);
   void Debug();
   void Ayuda(vector<string> & strings_control);

   void FijarCamara();
   void FijarProyeccion(float ventana_tam_x, float ventana_tam_y);
   void ModificaEjeXCamara(float nuevo);
   void ModificaEjeYCamara(float nuevo);
   void ModificarEscala(int signo);

   virtual ~Practica4();

   Practica4();
   Practica4(Practica4 const&);              // No se implementa para evitar copias
   Practica4& operator=(Practica4 const&);   // No se implementa para evitar asignaciones

private:
   visualizacion modo_dibujo;

   MallaTVT * peon_madera, * peon_blanco, * peon_negro, * cuerpo_lata, * tapa_sup, * tapa_inf;
   NodoGrafoEscena * raiz;
   Material * material_peon_blanco, * material_peon_negro, * material_peon_madera, * material_cuerpo_lata, * material_tapa;

   FuenteLuzPosicional * fuente_posicional;
   FuenteLuzDireccional* fuente_direccional;
   ColeccionFuentesLuz fuentes;

   Camara * camara;

};

#endif
