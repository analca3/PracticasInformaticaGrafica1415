#ifndef __IG_MALLATVT_HPP__
#define __IG_MALLATVT_HPP__

#include <GL/glew.h>
#include <GL/glut.h>
#include <vector>
#include <utility>
#include <cmath>
#include <cstdlib>

#include "enumerados.hpp"
#include "tuplas.hpp"
#include "error-ogl.hpp"
#include "VBO.hpp"
#include "Matriz.hpp"
#include "Material.hpp"

using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::max;


class MallaTVT
{
private:

   vector<Tupla3f> ver;
   vector<Tupla3i> tri;

   vector<Tupla3f> colores_vertices, normales_vertices, normales_caras, baricentros;
   vector<pair<Tupla3f,Tupla3f> > lineas_normales_caras, lineas_normales_vertices;

   Tupla3ub color_primario;
   Tupla3ub color_secundario;

   VBO_Vertices   * vbo_vertices;
   VBO_Triangulos * vbo_triangulos;
   VBO_Colores    * vbo_colores_vertices;
   VBO_Normales   * vbo_normales_vertices;
   VBO_Lineas     * vbo_lineas_normales_caras;
   VBO_Lineas     * vbo_lineas_normales_vertices;
   VBO_Coordenadas_Textura * vbo_coordenadas_textura;

   unsigned vertices_inicial, vertices_en_eje_Y;

   visualizacion modo_dibujo;
   normales dibujo_normales;
   tipo_malla tipo;

   Material * material;
   vector<Tupla2f> coordenadas_textura;

   float dimension;
   Tupla3f centro_coordenadas_objeto, centro_coordenadas_mundo;

   bool color_fijo;

   void CorregirVectoresNormales();
   void CalcularVectoresNormales();
   void CalcularDimension();
   void CalcularCoordenadasTextura(unsigned vertices_perfil);
   void CrearVBOs();
   void Inicializar();
   void VisualizarModoInmediato();
   void VisualizarNormalesCaras();
   void VisualizarNormalesVertices();



public:
   MallaTVT(tipo_malla tipo, vector<GLfloat> vertices, vector<int> caras = vector<int>(), Material * material = nullptr);
   MallaTVT(tipo_malla tipo, vector<Tupla3f> vertices, vector<Tupla3i> caras = vector<Tupla3i>(), Material * material = nullptr);
   MallaTVT(MallaTVT * malla);
   void SetMaterial(Material * material);
   void Visualizar();
   void Revolucion(const unsigned caras, bool tapas = true);
   void Barrido_Rotacion(const unsigned caras);
   void Barrido_Traslacion(const unsigned caras, const float dx, const float dy, const float dz);
   visualizacion getModoDibujo();
   normales getModoNormales();
   Tupla3f getCentro();
   void CambioModoDibujo ( visualizacion modo ) ;
   void CambioModoNormales();
   void CambioColorFijo();
   void SetColorPrimario(Tupla3ub color);
   void SetColorSecundario(Tupla3ub color);
   bool ColorFijo();

   void CorrigeCentro(Matriz4x4 transformacion);
};

#endif
