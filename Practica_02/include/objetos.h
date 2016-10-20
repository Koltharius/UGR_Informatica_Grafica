//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include "vertex.h"
#include <GL/gl.h>
#include <stdlib.h>
#include <vector>

using namespace std;

//*************************************************************************
// clase punto
//*************************************************************************

class _puntos3D {
public:
  _puntos3D();
  void draw_puntos(float r, float g, float b, int grosor);
  vector<_vertex3f> vertices;
};

//*************************************************************************
// clase triángulo
//*************************************************************************

class _triangulos3D : public _puntos3D {
public:
  _triangulos3D();
  void draw_aristas(float r, float g, float b, int grosor);
  void draw_solido(float r, float g, float b);
  void draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2,
                           float b2);

  vector<_vertex3i> caras;

  // Test
  vector<_vertex3f> colores_caras;
  void draw_solido_colores();
  // Fin Test
};

//*************************************************************************
// clase cubo
//*************************************************************************

class _cubo : public _triangulos3D {
public:
  _cubo(float tam);
};

//*************************************************************************
// clase piramide
//*************************************************************************

class _piramide : public _triangulos3D {
public:
  _piramide(float tam, float al);
};
